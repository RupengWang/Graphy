#ifndef __IFS_H__
#define __IFS_H__
#include "matrix.h"
#include "image.h"
#include <stdlib.h>
using namespace std;

#define m 0x100000000LL
#define c 0xB16  
#define a 0x5DEECE66DLL 

static unsigned long long seed = 1;

class IFS
{
public:
	IFS(int number);
	void input(FILE *file); 
	void outputImg(Image *img,int points,int iters);
	bool ifOverflow(Vec2f f);
private:
	int num;
	Matrix *matrix;
	float *array;

};


#endif __IFS_H__