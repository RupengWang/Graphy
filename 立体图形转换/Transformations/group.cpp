//#include "object3d.h"
#include "ray.h"
#include "hit.h"
#include "group.h"

void Group::addObject(int index, Object3D *obj)
{
	object3d_group.insert(pair<int,Object3D*>(index,obj));
}
bool Group::intersect(const Ray &r, Hit &h, float tmin)
{
	//Group的interset函数，再使用的时候会循环调用
	bool intersected = false;
	for (int i = 0; i < m_num_objects; i++)
	{
		if (object3d_group[i]->intersect(r, h, tmin))
		intersected = true;
	}
	return intersected;
}