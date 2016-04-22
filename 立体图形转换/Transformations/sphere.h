#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "object3d.h"
#include "material.h"
#include "vectors.h"
#include "ray.h"
#include "hit.h"

class Sphere :public Object3D
{
public:
	Sphere(){}
	Sphere(Vec3f center, float radius, Material *current_material):
		m_center(center),m_radius(radius),m_material(current_material){}
	~Sphere(){}
	virtual bool intersect(const Ray &r, Hit &h, float tmin)
	{
		//P(t) = Ro + t*Rd	     H(P) = P¡¤P - r2  =  0	
		//(Ro + tRd) ¡¤(Ro + tRd) - r2 = 0
		//Rd¡¤Rdt2 + 2Rd¡¤Rot + Ro¡¤Ro - r2 = 0
		//a = 1  (remember, || Rd || = 1)
		//b = 2Rd¡¤Ro
		//c = Ro¡¤Ro ¨C r2
		//float a = 1;
		float a = r.getDirection().Dot3(r.getDirection());
		//float b = r.getDirection()[0] * r.getOrigin()[0] + r.getDirection()[1] * r.getOrigin()[1] + r.getDirection()[2] * r.getOrigin()[2];
		Vec3f bVec3f = r.getDirection()*(r.getOrigin() - m_center);
		float b = 2 * (bVec3f[0] + bVec3f[1] + bVec3f[2]);
		Vec3f cVec3f = (r.getOrigin() - m_center) *(r.getOrigin() - m_center);
		//float c = r.getOrigin()[0] * r.getOrigin()[0] + r.getOrigin()[1] * r.getOrigin()[1] + r.getOrigin()[2] * r.getOrigin()[2];
		float c = cVec3f[0] + cVec3f[1] + cVec3f[2] - m_radius*m_radius;
		float dpow = b*b - 4 * a*c;
		if (dpow >= 0){
			float d = sqrt(dpow);
			float t = (-d - b) / (a * 2);
			float t2 = (d - b) / (a * 2);
			float t_current = h.getT();
			if (t > tmin&&t < t_current)
			{
				Vec3f hitPoint = r.getOrigin() + r.getDirection()*t;
				Vec3f n = (hitPoint - m_center);
				n.Normalize();
				h.set(t, m_material,n, r);
				return true;
			}
			else if (t2 > tmin&&t2 < t_current)
			{
				Vec3f hitPoint = r.getOrigin() + r.getDirection()*t2;
				Vec3f n = (hitPoint - m_center);
				n.Normalize();
				h.set(t2, m_material, n, r);
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
private:
	Vec3f m_center;
	float m_radius;
	Material *m_material;
};



#endif __SPHERE_H__