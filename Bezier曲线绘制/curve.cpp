

#include "curve.h"
//vector<vector<GLfloat>> vertices;          //用于存储点的坐标
//vector<int> num_ver;
vector<Vec3f> vertices;

Curve::Curve()
{

}
Curve::Curve(int i)
{

}
void Curve::set(int i, Vec3f v)
{
	return;
}

// 用于画图的FOR VISUALIZATION
void Curve::Paint(ArgParser *args)
{
}

// 用于实现样条类型转换的FOR CONVERTING BETWEEN SPLINE TYPES
void Curve::OutputBezier(FILE *file)
{

}
void Curve::OutputBSpline(FILE *file)
{

}

// 用于得到控制点的FOR CONTROL POINT PICKING
int Curve::getNumVertices()
{
	return 0;
}
Vec3f Curve::getVertex(int i)
{
	Vec3f v(0,0,0);
	return v;
}

// 用于编辑操作的FOR EDITING OPERATIONS
void Curve::moveControlPoint(int selectedPoint, float x, float y)
{

}
void Curve::addControlPoint(int selectedPoint, float x, float y)
{

}
void Curve::deleteControlPoint(int selectedPoint)
{

}

// 用于产生三角形的FOR GENERATING TRIANGLES
TriangleMesh* Curve::OutputTriangles(ArgParser *args)
{
	return 0;
}


void BezierCurve::set(int i,Vec3f v)
{
	vertices.push_back(v); 
	
}
void BezierCurve::Paint(ArgParser *args)
{

	//画Bezier曲线
	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0, 0);
	for (Vec3f temp : vertices)
	{
		glVertex3f(temp[0], temp[1], temp[2]);
	}
	glEnd();
	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(0, 0, 1.0);
	for (int i = 0; i<vertices.size();i++)
	{	
		if ((i + 1) % 4 == 0) continue;
		else{
			glVertex3f(vertices[i][0], vertices[i][1], vertices[i][2]);
			glVertex3f(vertices[i + 1][0], vertices[i + 1][1], vertices[i + 1][2]);
		}
	}
	glEnd();
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0, 1.0, 0);
	Vec3f v,v1;
	
	for (int i = 0; i<vertices.size(); i++)
	{
		if ((i % 4) != 0) continue;
		else{
			for (float t = 0.0, m = 0.0; t < 1.0, m < 1.0; t += 0.05)
			{
				m = t + 0.05;
				v = (1 - t)*(1 - t)*(1 - t)*vertices[i] + 3 * t*(1 - t)*(1 - t)*vertices[i + 1] + 3 * t*t*(1 - t)*vertices[i + 2] + t*t*t*vertices[i + 3];
				v1 = (1 - m)*(1 - m)*(1 - m)*vertices[i] + 3 * m*(1 - m)*(1 - m)*vertices[i + 1] + 3 * m*m*(1 - m)*vertices[i + 2] + m*m*m*vertices[i + 3];
				glVertex3f(v[0], v[1], v[2]);
				glVertex3f(v1[0], v1[1], v1[2]);
			}
		}
	}
	glEnd();
}

float BezierCurve::transferBezier(float coord1, float coord2, float coord3,float coord4 ,float t)
{
	float temp;
	temp = (1 - t)*(1 - t)*(1 - t)*coord1 + 3 * t*(1 - t)*(1 - t)*coord2 + 3 * t*t*(1 - t)*coord3 + t*t*t*coord4;
	return temp;
}

void BSplineCurve::Paint(ArgParser *args)
{
	
}