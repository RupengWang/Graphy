#ifndef SPLINE
#define SPLINE

//#include <GL/glut.h>
#include "vectors.h"
#include "triangle_mesh.h"
#include "arg_parser.h"

using namespace std;

class Spline
{
public:

	// 用于画图的FOR VISUALIZATION
	virtual void Paint(ArgParser *args){};

	// 用于实现样条类型转换的FOR CONVERTING BETWEEN SPLINE TYPES
	virtual void OutputBezier(FILE *file){};
	virtual void OutputBSpline(FILE *file){};

	// 用于得到控制点的FOR CONTROL POINT PICKING
	virtual int getNumVertices(){ return 0; };
	virtual Vec3f getVertex(int i){
		Vec3f a = { 0, 0, 0 }; return a;
	};

	// 用于编辑操作的FOR EDITING OPERATIONS
	virtual void moveControlPoint(int selectedPoint, float x, float y){};
	virtual void addControlPoint(int selectedPoint, float x, float y){};
	virtual void deleteControlPoint(int selectedPoint){};
	
	// 用于产生三角形的FOR GENERATING TRIANGLES
	virtual TriangleMesh* OutputTriangles(ArgParser *args){ return 0; };
};


#endif