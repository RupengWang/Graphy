//
// originally implemented by Justin Legakis
//
#include "image.h"
#include "IFS.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, const char** argv)
{
	char *input_file = NULL;
	int size = 100;
	char *output_file = NULL;
	int iters = 0;
	int num_points = 0;
	int n = 0;

	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "-input")) {
			i++; assert(i < argc);
			input_file = new char[strlen(argv[i])+1];
			//input_file = argv[i];
			strcpy_s(input_file, strlen(argv[i]) + 1, argv[i]);
		}
		else if (!strcmp(argv[i], "-iters")) {
			i++; assert(i < argc);
			iters = atoi(argv[i]);
		}
		else if (!strcmp(argv[i], "-size")) {
			i++; assert(i < argc);
			size = atoi(argv[i]);
		}
		else if (!strcmp(argv[i], "-output")) {
			i++; assert(i < argc);
			output_file = new char[strlen(argv[i]) + 1];
			//output_file = argv[i];
			strcpy_s(output_file, strlen(argv[i]) + 1, argv[i]);
		}
		else if (!strcmp(argv[i], "-points")) {
			i++; assert(i < argc);
			num_points = atoi(argv[i]);
		}
		else {
			printf("whoops error with command line argument %d: '%s'\n", i, argv[i]);
			assert(0);
		}
	}

	//创建一个size*size大小的image对象
	Image *Img = new Image(size,size);
	//设置背景颜色为黑色
	Img->SetAllPixels(Vec3f(0, 0, 0));

	FILE* f;
	fopen_s(&f,input_file, "r");
	if (f == 0)
	{
		printf("can't open input_file!");
		return false;
	}
	else
	{
		printf("open file successful!\n");
		fscanf_s(f, "%d", &n);
		IFS *ifs = new IFS(n);
		ifs->input(f);
		fclose(f);
		ifs->outputImg(Img, num_points, iters);
		Img->SaveTGA(output_file);
	}
	return 0;
	
}