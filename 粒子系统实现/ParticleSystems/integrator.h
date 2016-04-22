#ifndef __INTEGRATOR_H__
#define __INTEGRATOR_H__

#include "forcefield.h"
#include "particle.h"

class Integrator
{
public:
	virtual void Update(Particle *p, ForceField *f, float current_time, float dt) = 0;
	virtual Vec3f getColor(){ Vec3f v(0.0,0.0,0.0); return v; }

private:

};

class EulerIntegrator :public Integrator
{
public:
	void Update(Particle *p, ForceField *f, float current_time, float dt);
	Vec3f getColor();

private:

};

class MidpointIntegrator :public Integrator
{
public:
	void Update(Particle *p, ForceField *f, float current_time, float dt);
	Vec3f getColor();
private:
	
};

class RungeKuttaIntegrator :public Integrator
{
public:
	void Update(Particle *p, ForceField *f, float current_time, float dt);
	Vec3f getColor();
private:

};

#endif __INTEGRATOR_H__