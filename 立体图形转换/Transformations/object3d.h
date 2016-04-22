#ifndef __OBJECT_3D_H__
#define __OBJECT_3D_H__

class Ray;
class Hit;
class Material;
class Object3D
{
public:
	Object3D(){};
	Object3D(Material *material){ m_material = material; }
	~Object3D(){};
	virtual bool intersect(const Ray &r, Hit &h, float tmin) = 0{}
private:
	Material *m_material;
};

#endif