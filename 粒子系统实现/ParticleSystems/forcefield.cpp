#include "forcefield.h"

Vec3f GravityForceField::getAcceleration(const Vec3f &position, float mass, float t)
{
	return G;
}

Vec3f ConstantForceField::getAcceleration(const Vec3f &position, float mass, float t)
{
	return Vec3f(m_force *(1 / mass));
}

Vec3f RadialForceField::getAcceleration(const Vec3f &position, float mass, float t)
{
	return Vec3f(-m_magnitude * position * (1 / mass));
}

Vec3f VerticalForceField::getAcceleration(const Vec3f &position, float mass, float t)
{
	return Vec3f(0, -m_magnitude * position.y() * 1 / mass, 0);
}