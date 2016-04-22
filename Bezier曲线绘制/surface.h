#include "spline.h"
#include "curve.h"

class Surface: public Spline
{
public:
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

class SurfaceOfRevolution :public Surface
{
public: 
	SurfaceOfRevolution(Curve *c){};
};

class BezierPatch :public Surface
{

};