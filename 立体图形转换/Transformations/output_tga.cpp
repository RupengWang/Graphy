#include "output_tga.h"


OutputTGA::OutputTGA(ArgParser *args, SceneParser *scenes)
{
	imgDepth = new Image(args->size_x, args->size_y);
	imgDepth->SetAllPixels(scenes->getBackgroundColor());
	imgOutput = new Image(args->size_x, args->size_y);
	imgOutput->SetAllPixels(scenes->getBackgroundColor());
	imgNormals = new Image(args->size_x, args->size_y);
	imgNormals->SetAllPixels(Vec3f(0, 0, 0));
}

void OutputTGA::output(ArgParser *args, SceneParser *scence)
{
	Camera *camera = scence->getCamera();
	Group *group = scence->getGroup();
	Vec3f normal;
	//Light *light = scence->getLight();

	for (int i = 0; i < imgDepth->Height(); i++)
		for (int j = 0; j < imgDepth->Width(); j++)
		{
			Vec2f v(j, i);
			v /= imgDepth->Width();
			Ray ray = camera->generateRay(v);
			Hit hit;
			if (group->intersect(ray, hit, camera->getTMin()))
			{
				if (args->output_file != NULL)
					imgOutput->SetPixel(j, i, getPixelColor(args,scence, &hit, &ray));

				if (args->depth_file != NULL)
				{
					//颜色深度的计算
					float depth = hit.getT();
					float length = args->depth_y - args->depth_x;
					float color = 1.0 - (depth - args->depth_x) / length;
					Vec3f colorMain(color, color, color);
					imgDepth->SetPixel(j, i, colorMain);
				}
				if (args->normals_file != NULL)
				{
					//对于法向量可视化, 只用简单地显示法向量的坐标的绝对值为 (r, g, b) 颜色
					normal = hit.getNormal();
					float r = abs(normal.x());
					float g = abs(normal.y());
					float b = abs(normal.z());
					imgNormals->SetPixel(j, i, Vec3f(r,g,b));
				}
			}
		}

	//输出TGA图像文件
	if (args->output_file != NULL)
		imgOutput->SaveTGA(args->output_file);
	if (args->depth_file != NULL)
		imgDepth->SaveTGA(args->depth_file);
	if (args->normals_file != NULL)
		imgNormals->SaveTGA(args->normals_file);
}

Vec3f OutputTGA::getPixelColor(ArgParser *args, SceneParser *scence, Hit *hit, Ray *ray)
{
	Vec3f direction, color, interection_point;
	interection_point = hit->getIntersectionPoint();
	Vec3f Cobject = hit->getMaterial()->getDiffuseColor();
	Vec3f Clight = scence->getAmbientLight();
	Vec3f Cpixel = Cobject*Clight;
	Vec3f CLastlight;
	Vec3f normal = hit->getNormal();
	float dir = ray->getDirection().Dot3(normal);
	for (int i = 0; i < scence->getNumLights(); i++)
	{
		scence->getLight(i)->getIllumination(interection_point, direction, color);
		if (dir>0&&args->isShadeBack)
			normal *= -1;
		float temp = direction.Dot3(normal);
		if (temp > 0)
			CLastlight += temp*color*Cobject;
		else
			CLastlight = Vec3f(0.0, 0.0, 0.0);
	}
	return (CLastlight + Cpixel);
}