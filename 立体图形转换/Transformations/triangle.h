#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "object3d.h"
#include "material.h"
#include "vectors.h"
#include "ray.h"
#include "hit.h"
//#include "matrix.h"
class Triangle :public Object3D
{
public:
	Triangle(Vec3f v0,Vec3f v1,Vec3f v2,Material* current_material):m_v0(v0),m_v1(v1),m_v2(v2),m_current_material(current_material)
	{
		Vec3f::Cross3(m_normal, m_v1 - m_v0, m_v2 - m_v0);
		m_normal.Normalize();
	}
	bool intersect(const Ray &r, Hit &h, float tmin)
	{
		float Beta = 0;
		float Gamma = 0;
		Vec3f r1 = m_v0 - m_v1;
		Vec3f r2 = m_v0 - m_v2;
		Vec3f r3 = r.getDirection();
		Vec3f r4 = m_v0 - r.getOrigin();
		float detA = det3x3(r1.x(), r2.x(), r3.x(), r1.y(), r2.y(), r3.y(), r1.z(), r2.z(), r3.z());
		Beta = det3x3(r4.x(), r2.x(), r3.x(), r4.y(), r2.y(), r3.y(), r4.z(), r2.z(), r3.z()) / detA;
		Gamma = det3x3(r1.x(), r4.x(), r3.x(), r1.y(), r4.y(), r3.y(), r1.z(), r4.z(), r3.z()) / detA;
		float t = det3x3(r1.x(), r2.x(), r4.x(), r1.y(), r2.y(), r4.y(), r1.z(), r2.z(), r4.z()) / detA;
		if (Beta + Gamma<1 && Beta>0 && Gamma>0)
		{
			if (t >= tmin&&t<h.getT())
			{
				h.set(t, m_current_material, m_normal, r);
				return true;
			}
		}
		return false;
	}

	float det4x4(float a1, float a2, float a3, float a4,
		float b1, float b2, float b3, float b4,
		float c1, float c2, float c3, float c4,
		float d1, float d2, float d3, float d4) {
		return
			a1 * det3x3(b2, b3, b4, c2, c3, c4, d2, d3, d4)
			- b1 * det3x3(a2, a3, a4, c2, c3, c4, d2, d3, d4)
			+ c1 * det3x3(a2, a3, a4, b2, b3, b4, d2, d3, d4)
			- d1 * det3x3(a2, a3, a4, b2, b3, b4, c2, c3, c4);
	}

	float det3x3(float a1, float a2, float a3,
		float b1, float b2, float b3,
		float c1, float c2, float c3) {
		return
			a1 * det2x2(b2, b3, c2, c3)
			- b1 * det2x2(a2, a3, c2, c3)
			+ c1 * det2x2(a2, a3, b2, b3);
	}

	float det2x2(float a, float b,
		float c, float d) {
		return a * d - b * c;
	}
private:
	Vec3f m_v0, m_v1, m_v2,m_normal;
	Material *m_current_material;
};

#endif __TRIANGLE_H__