#ifndef __OUTPUT_TGA_H__
#define __OUTPUT_TGA_H__

#include "image.h"
#include "arg_parser.h"
#include "scene_parser.h"

#include "camera.h"
#include "group.h"
#include "ray.h"
#include "hit.h"
#include "material.h"
#include "sphere.h"
#include "object3d.h"
#include "light.h"

class OutputTGA
{
public:
	OutputTGA(ArgParser *args, SceneParser *scenes);
	~OutputTGA()
	{
		delete imgDepth;
		delete imgOutput;
		delete imgNormals;
	}
	void output(ArgParser *args, SceneParser *scence);
	Vec3f getPixelColor(ArgParser *args, SceneParser *scence, Hit *hit, Ray *ray);
private:
	OutputTGA(){}
	Image *imgDepth;
	Image *imgOutput;
	Image *imgNormals;
};

#endif __OUTPUT_TGA_H__