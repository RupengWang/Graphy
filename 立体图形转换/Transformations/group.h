#ifndef __GROUP_H__
#define __GROUP_H__
#include <map>
using namespace std;
#include "object3d.h"
//class Object3D;
class Ray;
class Hit;
class Group :public Object3D
{
public:
	Group(){ m_num_objects = 0;  }
	Group(int num_objects){ m_num_objects = num_objects; }
	~Group(){}
	bool intersect(const Ray &r, Hit &h, float tmin);
	void addObject(int index, Object3D *obj);
private:
	int m_num_objects;
	map<int,Object3D*> object3d_group;
};



#endif __GROUP_H__