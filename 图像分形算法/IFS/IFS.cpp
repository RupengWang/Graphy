#include "IFS.h"

float drand48()
{
	seed = (a * seed + c) & 0xFFFFFFFFFFFFLL;
	unsigned int x = seed >> 16;
	return  ((float)x / (float)m);
}

IFS::IFS(int number)
{
	num = number;
	matrix = new Matrix[num];
	array = new float(num);
}

//从文件中读取矩阵的数据
void IFS::input(FILE *file)
{
	for (int i = 0; i < num; i++)
	{
		fscanf_s(file, "%f", &array[i]);
		matrix[i].Read3x3(file);
	}
}

void IFS::outputImg(Image *img, int points, int iters)
{
	int width = img->Width(), height = img->Height();
	for (int i = 1; i <= points; i++)
	{
		Vec2f V = Vec2f(drand48(), drand48());
		for (int k = 0; k<iters; k++)
		{
			float p = drand48();
			float sum = 0;
			int j = 0;
			for (j = 0; j< num; j++)
			{
				sum += array[j];
				if (p <= sum)
					break;
			}
			matrix[j].Transform(V);
		}
		if (ifOverflow(V))
			img->SetPixel(V.x()*width, V.y()*height, Vec3f(0, 1, 0));
	}
}
bool IFS::ifOverflow(Vec2f f)
{
	if (f.x() >= 0 && f.x() <= 1 && f.y() >= 0 && f.y() <= 1)
		return true;
	else
		return false;
}
