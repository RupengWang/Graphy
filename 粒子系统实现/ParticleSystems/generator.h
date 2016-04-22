#ifndef __GENERATOR_H__
#define __GENERATOR_H__

#include "random.h"
#include "vectors.h"
#include "particle.h"
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>

#define random_m 0x100000000LL
#define random_c 0xB16  
#define random_a 0x5DEECE66DLL 

#define PI 3.1415926
static unsigned long long seed = 1;
class Generator
{
public:
	Generator(){}
	Generator(float position_randomness, float velocity_randomness) :pos_rand(position_randomness), vel_rand(velocity_randomness)
	{
	}
	~Generator(void){}
	//for the GUI
	virtual void Paint(){ }
	virtual void Restart(){ }
	//初始化
	virtual void SetColors(Vec3f color, Vec3f dead_color, float color_randomness){ col = color; d_color = dead_color; col_rand = color_randomness; }
	virtual void SetMass(float mass, float randomness){ m = mass; rand_m = randomness; }
	virtual void SetLifespan(float lifespan, float lifespan_randomness, int desired_num_particles){ life_span = lifespan; life_rand = lifespan_randomness; desired = desired_num_particles; }
	// 每个时间步，产生一些质点
	virtual int numNewParticles(float current_time, float dt) = 0{ return (dt*desired / life_span); }
	virtual Particle *Generate(float current_time, int i) = 0 { Particle *d = NULL; return d; }
private:
	float pos_rand;
	float vel_rand;
	Vec3f col,d_color;
	float m,rand_m,col_rand;
	float life_span, life_rand;
	int desired;
	Particle *p;

};

class HoseGenerator :public Generator
{
public:
	HoseGenerator();
	HoseGenerator(Vec3f position, float position_randomness, Vec3f velocity, float velocity_randomness) : 
		pos(position),pos_rand (position_randomness),vel (velocity),vel_rand (velocity_randomness)
	{

	}
	~HoseGenerator(){}
	void Paint();
	void SetColors(Vec3f color, Vec3f dead_color, float color_randomness){ col = color; d_color = dead_color; col_rand = color_randomness; }
	void SetMass(float mass, float randomness){ m = mass; rand_m = randomness; }
	void SetLifespan(float lifespan, float lifespan_randomness, int desired_num_particles)
	{
		life_span = lifespan; life_rand = lifespan_randomness; desired = desired_num_particles;
	}
	// 每个时间步，产生一些质点
	int numNewParticles(float current_time, float dt);
	Particle* Generate(float current_time, int i);
private:
	Vec3f pos;
	float pos_rand;
	Vec3f vel;
	float vel_rand;
	Vec3f col, d_color;
	float m,rand_m, col_rand;
	float life_span,life_rand;
	int desired;
	Particle *p;
};

class RingGenerator :public Generator
{
public:
	RingGenerator(){}
	RingGenerator(float position_randomness, Vec3f velocity, float velocity_randomness) :pos_rand(position_randomness), vel(velocity), vel_rand(velocity_randomness)
	{
	}
	~RingGenerator(){}
	void SetColors(Vec3f color, Vec3f dead_color, float color_randomness){ col = color; d_color = dead_color; col_rand = color_randomness; }
	void SetMass(float mass, float randomness){ m = mass; rand_m = randomness; }
	void SetLifespan(float lifespan, float lifespan_randomness, int desired_num_particles){ life_span = lifespan; life_rand = lifespan_randomness; desired = desired_num_particles; }

	int numNewParticles(float current_time, float dt);
	Particle* Generate(float current_time, int i);
private:
	Vec3f pos;
	float pos_rand;
	Vec3f vel;
	float vel_rand;
	Vec3f col, d_color;
	float m, rand_m, col_rand;
	float life_span, life_rand;
	int desired;
	Particle *p;
};
#endif