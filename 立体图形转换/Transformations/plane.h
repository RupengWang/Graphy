#ifndef __PLANE_H__
#define __PLANE_H__
#include "object3d.h"
#include "material.h"
#include "vectors.h"
#include "ray.h"
#include "hit.h"
class Plane :public Object3D
{
public:
	Plane(Vec3f normal, float offset, Material* current_material) :m_normal(normal), m_offset(offset), m_current_material(current_material){}
	bool intersect(const Ray &r, Hit &h, float tmin)
	{	
		float temp = m_normal.Dot3(r.getDirection());
		if (temp)
		{
			float t = (-m_normal.Dot3(r.getOrigin()) + m_offset) / temp;
			if (t<h.getT() && t>tmin)
			{
				h.set(t, m_current_material, m_normal, r);
				return true;
			}
		}
		return false; 
	}
private:
	Vec3f m_normal;
	float m_offset;
	Material *m_current_material;
};

#endif __PLANE_H__