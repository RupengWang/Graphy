#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__
#include "matrix.h"
#include "object3d.h"
class Transform:public Object3D
{
public:
	Transform(Matrix matrix,Object3D* object):m_matrix(matrix),m_object(object){}
	bool intersect(const Ray &r, Hit &h, float tmin)
	{
		Vec3f origin = r.getOrigin();
		Vec3f direction = r.getDirection();
		Matrix matrix = m_matrix;

		matrix.Inverse();
		matrix.Transform(origin);
		matrix.TransformDirection(direction);
		
		Ray ray(origin, direction);
		if (m_object->intersect(ray, h, tmin))
		{
			Vec3f normal = h.getNormal(); //从object中获取法向量
			matrix.Transpose();
			matrix.Transform(normal);
			normal.Normalize();
			h.set(h.getT(), h.getMaterial(), normal, r);
			return true;
		}
		return false;
	}
private:
	Matrix m_matrix;
	Object3D *m_object;
};

#endif __TRANSFORM_H__