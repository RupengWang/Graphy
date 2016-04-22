#include "integrator.h"

void EulerIntegrator::Update(Particle *p, ForceField *f, float current_time, float dt)
{
	Vec3f vec_position = p->getPosition();
	float mass = p->getMass();
	Vec3f vec_acceleration = f->getAcceleration(vec_position, mass, current_time);

	Vec3f vec_new_velocity = p->getVelocity() + vec_acceleration * dt;// v(n+1) = v(n) + a(p(n), t) * dt
	Vec3f vec_new_position = vec_position + p->getVelocity() * dt;// p(n+1) = p(n)+ v(n) * dt
	p->setVelocity(vec_new_velocity);
	p->setPosition(vec_new_position);
	p->increaseAge(dt);
}

Vec3f  EulerIntegrator::getColor()
{
	return Vec3f(0.0, 0.3, 0.5);
}

void MidpointIntegrator::Update(Particle *p, ForceField *f, float current_time, float dt)
{
	Vec3f temp_position = p->getPosition();//pn
	Vec3f temp_velocity = p->getVelocity();//vn
	Vec3f vec_acceleration = f->getAcceleration(temp_position, p->getMass(), current_time);//a(pn, t)
	Vec3f vec_position = temp_position + temp_velocity * (dt / 2);//pm
	Vec3f vec_velocity = temp_velocity + vec_acceleration * (dt / 2);//vm
	Vec3f vec_new_position = temp_position + vec_velocity * dt;//pn+1
	Vec3f vec_new_velocity = temp_velocity + f->getAcceleration(vec_position, p->getMass(), current_time + dt / 2) * dt;//vn+1

	p->setPosition(vec_new_position);
	p->setVelocity(vec_new_velocity);
	p->increaseAge(dt);
}


Vec3f MidpointIntegrator::getColor()
{
	return Vec3f(1.0, 0.3, 0.0);
}

void RungeKuttaIntegrator::Update(Particle *p, ForceField *f, float current_time, float dt)
{

}
Vec3f RungeKuttaIntegrator::getColor()
{
	return Vec3f(1.0,0.3,0.0);
}