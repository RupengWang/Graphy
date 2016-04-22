#include "surface.h"

void Surface::set(int i, Vec3f v)
{

}

// 用于画图的FOR VISUALIZATION
void Surface::Paint(ArgParser *args)
{

}

// 用于实现样条类型转换的FOR CONVERTING BETWEEN SPLINE TYPES
void Surface::OutputBezier(FILE *file)
{

}
void Surface::OutputBSpline(FILE *file)
{

}

// 用于得到控制点的FOR CONTROL POINT PICKING
int Surface::getNumVertices()
{
	return 0;
}
Vec3f Surface::getVertex(int i)
{
	Vec3f v(0,0,0);
	return v;
}

// 用于编辑操作的FOR EDITING OPERATIONS
void Surface::moveControlPoint(int selectedPoint, float x, float y)
{

}
void Surface::addControlPoint(int selectedPoint, float x, float y)
{

}
void Surface::deleteControlPoint(int selectedPoint)
{

}

// 用于产生三角形的FOR GENERATING TRIANGLES
TriangleMesh* Surface::OutputTriangles(ArgParser *args)
{
	return 0;
}