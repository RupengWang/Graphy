#include "generator.h"


float drand48()
{
	seed = (random_a * seed + random_c) & 0xFFFFFFFFFFFFLL;
	unsigned int x = seed >> 16;
	return  ((float)x / (float)random_m);
}

void HoseGenerator::Paint()
{

}

int HoseGenerator::numNewParticles(float current_time, float dt)
{
	return (dt*desired / life_span);
}
Particle* HoseGenerator::Generate(float current_time, int i)
{
	Random rand(i);
	Vec3f vec_position = pos + rand.randomVector() * pos_rand*drand48();
	Vec3f vec_velocity = vel + rand.randomVector() * vel_rand*drand48();
	float lifespan = life_span + rand.next() * life_rand;
	p = new Particle(vec_position, vec_velocity, col, d_color, m, lifespan);
	return p;
}

//RingGenerator类成员函数的实现

int RingGenerator::numNewParticles(float current_time, float dt)
{
	return (dt*desired / life_span)*500;
	//return 1;
}

Particle* RingGenerator::Generate(float current_time, int i)
{
	Random rand(i);
	Vec3f vec_position = (pos + rand.randomVector() * pos_rand*drand48());
	//vec_position.Set(vec_position[0]*i/10,vec_position[1]*i/10,vec_position[2]*i/10);
	vec_position.Set((vec_position[0]+3) * cos(i*PI / 2500), vec_position[1], (vec_position[0]+3) * sin(i*PI / 2500));
	Vec3f vec_velocity = vel + rand.randomVector() * vel_rand*drand48();
	float lifespan = life_span + rand.next() * life_rand;
	p = new Particle(vec_position, vec_velocity, col, d_color, m, lifespan);
	return p;
}