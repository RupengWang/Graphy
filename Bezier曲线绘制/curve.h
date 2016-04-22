#ifndef CURVE
#define CURVE



#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "spline.h"
#include <GL/glut.h>

using namespace std;

class Curve :public Spline
{
public:
	Curve();
	Curve(int i);
	void set(int i, Vec3f v);


	// 用于画图的FOR VISUALIZATION
	void Paint(ArgParser *args);

	// 用于实现样条类型转换的FOR CONVERTING BETWEEN SPLINE TYPES
	void OutputBezier(FILE *file);
	void OutputBSpline(FILE *file);

	// 用于得到控制点的FOR CONTROL POINT PICKING
	int getNumVertices();
	Vec3f getVertex(int i);

	// 用于编辑操作的FOR EDITING OPERATIONS
	void moveControlPoint(int selectedPoint, float x, float y);
	void addControlPoint(int selectedPoint, float x, float y);
	void deleteControlPoint(int selectedPoint);

	// 用于产生三角形的FOR GENERATING TRIANGLES
	TriangleMesh* OutputTriangles(ArgParser *args);
};

class BezierCurve :public Curve
{
public:
	BezierCurve(){};
	BezierCurve(int i){};

	void set(int i, Vec3f v);
	void Paint(ArgParser *args);

	/*void ReadFile(ArgParser *args);*/

	float transferBezier(float coord1,float coord2,float coord3,float coord4,float t);
private:
	
};

class BSplineCurve:public Curve
{
public:
	BSplineCurve(){};
	BSplineCurve(int i){};
	
	void Paint(ArgParser *args);
};



#endif