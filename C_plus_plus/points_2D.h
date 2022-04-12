#pragma once
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*****************************************************************
点和向量的声明，以及加减，数乘比较等基础操作
*****************************************************************/

const double pi = acos(-1.0);
struct Point {
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) {

	}
};//点的结构体 
typedef Point Vector;//同时也是向量 
Vector operator+(Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y); }//向量相加 
Vector operator-(Vector a, Vector b) { return Vector(a.x - b.x, a.y - b.y); }//向量相减 ，得到向量ba 
Vector operator*(Vector a, double b) { return Vector(a.x*b, a.y*b); }//向量乘上一个数 
Vector operator/(Vector a, double b) { return Vector(a.x / b, a.y / b); }//向量除去一个数 
bool operator< (const Point &a, const Point &b)
{
	return a.x < b.x || (a.x == b.x&&a.y < b.y);
}//方便对点进行排序，依据的排序规则为水平坐标小的就小一些，当水平坐标相等时就纵坐标小的小 
const double eps = 1e-10;//可以适当调整为1e-8
int dcmp(double x)
{
	if (fabs(x) < eps) return 0;
	if (x < 0) return -1;
	return 1;
}
bool operator==(const Point &a, const Point &b)
{
	return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;//对向量（点）的相等进行重载 
}
/*********************************************
向量之间的一些基本运算
*********************************************/
//向量与向量的计算
double Dot(Vector a, Vector b)
{
	return a.x*b.x + a.y*b.y;//向量的点乘 
}
double Length(Vector a)
{
	return sqrt(Dot(a, a));//计算向量a的长度 
}
double Angle(Vector a, Vector b)
{
	return acos(Dot(a, b) / Length(a) / Length(b));//计算向量a,b的夹角 
}
double Cross(Vector a, Vector b)
{
	return a.x*b.y - a.y*b.x;
	//计算a×b，切记，叉乘有前后之分 
	//b的在a的逆时针方向时为正 
}
double Area2(Point a, Point b, Point c)
{
	return Cross(b - a, c - a);
	//计算a,b,c三点构成的三角形的面积的两倍 
	//注意：ab（由a指向b的向量），ac（a指向c的向量）。
	//ac在ab的逆时针方向时，面积为正，反之为负 
}
Vector Rotate(Vector a, double rad)
{
	return Vector(a.x*cos(rad) - a.y*sin(rad), a.x*sin(rad) + a.y*cos(rad));
	//rad是弧度，旋转方向为逆时针 
}
Vector Normal(Vector a)
{
	double L = Length(a);
	return Vector(-a.y / L, a.x / L);
	//求出a向量的单位法向量
	//逆时针旋转90度的法向量 
}
//还有一种用虚数表现点的向量的方法，慢一些
/********************************************************
#include<complex>
using namespace std;
typedef complex<double> Point;
typedef Point Vector;
double Dot(Vector a,Vector b)
{
	return real(conj(a)*b);
}
double Cross(Vector a,Vector b)
{
	return imag(conj(a)*b);
}
Vector Rotate(Vector a,double rad)
{
	return a*(exp(Point(0,rad)));
}
//conj返回该复数的共轭复数
//imag返回复数的虚部
//real返回复数的实部
************************************************************************************/
/***********************************************************************************
以下为点和直线
************************************************************************************/
struct Line {
	Point p;
	Vector v;
	Line(double px, double py, double ex, double ey) :p(px, py), v(ex - px, ey - py) {}
	Line(double px, double py, Point a) :
		p(px, py), v(a.x - px, a.y - py) {}
	Line(Point a, Point b) :
		p(a.x, b.x), v(b.x - a.x, b.y - a.y) {}
	Point point(int x)//已知一点的横坐标，求其点 
	{
		double t = (x - p.x) / v.x;
		return Point(x, p.y + t * v.y);
	}
};
Point GetLineIntersection(Point p, Vector v, Point q, Vector w)
{
	Vector u = p - q;
	double t = Cross(w, u) / Cross(v, w);
	return p + v * t;
	//返回直线p+tv和q+tw的交点（v,w分别是两条线的方向向量，p和q分别是直线上的一点） 
	//需要注意的是Cross（v，w）不能共线 
}
double Distancetoline(Point p, Point a, Point b)
{
	Vector v1 = b - a, v2 = p - a;
	return fabs(Cross(v1, v2)) / Length(v1);
	//求得p到直线ab的距离 
}
double Distancetosegment(Point p, Point a, Point b)
{
	if (a == b) return Length(p - a);
	Vector v1 = b - a, v2 = p - a, v3 = p - b;
	if (dcmp(Dot(v1, v2)) < 0) return Length(v2);
	if (dcmp(Dot(v1, v3)) > 0) return Length(v3);
	return  fabs(Cross(v1, v2)) / Length(v1);
	//求得p到直线ab的最小距离 
}
Point GetLineProjection(Point p, Point a, Point b)
{
	Vector v = b - a;
	return a + v * (Dot(v, p - a) / Dot(v, v));
	//p在直线ab上的投影点 
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
	double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
		c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - a1);
	return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
	//判断a1a2与b1b2是否相交（交点不在a1,a2,b1,b2上） 
	//如果c1c2表示两直线共线 
}
//当c1c2不同时为零时，还有一种一条线段在；另一条直线上的端点的情况，需要用下函数判断某点是否在直线上
bool OnSegment(Point p, Point a1, Point a2)
{
	return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
	//用叉乘判断时候在这条直线上，用点乘判断是否在线段中
	//判断p点是否在线段a1a2上 
}
/***************************************
多边形面积公式
***************************************/
double PolygonArea(Point* p, int n)
{
	double area = 0;
	for (int i = 1; i < n - 1; i++)
	{
		area += Cross(p[i] - p[0], p[i + 1] - p[0]);
	}
	return area / 2;
	//注意此方法的得出的面积有向，在不能保证点的分布是顺时针还是啊逆时针的时候需要加上绝对值
	//p是点的数组，n是多边形的边数，也是点数 
}
/**********************************************************
与圆和球有关的计算问题
**********************************************************/
struct Circle {
	Point c;//圆心 
	double r;//半径
	Circle(Point c, double r) :c(c), r(r) {}
	Point point(double rad)
	{
		return Point(c.x + cos(rad)*r, c.y + sin(rad)*r);// 圆上rad角处点的坐标 
	}
};
int getLineCircleIntersection(Line L, Circle C, double &t1, double &t2, vector<Point>& sol)
{
	double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
	double e = a * a + c * c, f = 2 * (a*b + c * d), g = b * b + d * d - C.r*C.r;
	double delta = f * f - 4 * e*g;
	if (dcmp(delta) < 0) return 0; //相离 
	if (dcmp(delta) == 0)   //相切 
	{
		t1 = t2 = -f / (2 * e);//t为交点的横坐标 
		sol.push_back(L.point(t1));
		return 1;
	}
	//相交 
	t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(L.point(t1));
	t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(L.point(t2));
	return 2;
}
//向量的极角 
double angle(Vector v) { return atan2(v.y, v.x); }

int getCircleCircleIntersection(Circle c1, Circle c2, vector<Point>& sol)
{
	double d = Length(c1.c - c2.c);
	if (dcmp(d) == 0)
	{
		if (dcmp(c1.r - c2.r) == 0) return -1;//两圆相交
		return 0;//当共圆心时，如半径大小不相同则必定无交点 
	}
	if (dcmp(c1.r + c2.r - d) < 0) return 0;
	if (dcmp(fabs(c1.r - c2.r) - d) > 0) return 0;
	double a = angle(c2.c - c1.c);
	double da = acos((c1.r*c1.r + d * d - c2.r*c2.r) / (2 * c1.r*d));
	//c1c2到c1p1的角（p1是交点）
	Point p1 = c1.point(a - da), p2 = c1.point(a + da);
	sol.push_back(p1);
	if (p1 == p2) return 1;
	sol.push_back(p2);
	return 2;
	//本函数用于求两圆之间的相交情况 
}
int getTangents(Point p, Circle c, Vector* v)
{
	Vector u = c.c - p;
	double dist = Length(u);
	if (dist < c.r) return 0;//点在圆内不可能出现切线
	if (dcmp(dist - c.r) == 0) {
		v[0] = Rotate(u, pi / 2);
		return 1;
		//点在圆上恰有一条切线 
	}
	double ang = asin(c.r / dist);
	v[0] = Rotate(u, -ang);
	v[1] = Rotate(u, ang);
	return 2;//两条切线
	//本函数用于求一个点和圆所能产生的切线 
}
int getTangents(Circle A, Circle B, Point* a, Point* b)
{
	int cnt = 0;
	if (A.r < B.r)
	{
		swap(A, B);
		swap(a, b);
	}
	int d2 = (A.c.x - B.c.x)*(A.c.x - B.c.x) + (A.c.y - B.c.y)*(A.c.y - B.c.y);//圆心距离的平方 
	int rdiff = A.r - B.r;
	int rsum = A.r + B.r;
	if (d2 < rdiff*rdiff) return 0;
	//两圆的圆心距离小于半径差
	//内含 
	double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);//圆心连线的极角 
	if (d2 == 0 && A.r == B.r) return -1;//两圆重合 
	if (d2 == rdiff * rdiff) {
		a[cnt] = A.point(base); b[cnt] = B.point(base);
		cnt++;
		return 1;
	}
	//外公切线
	double ang = acos((A.r - B.r) / sqrt(d2));
	a[cnt] = A.point(base + ang); b[cnt] = B.point(base + ang); cnt++;
	a[cnt] = A.point(base - ang); b[cnt] = B.point(base - ang); cnt++;
	if (d2 == rsum * rsum) {
		a[cnt] = A.point(base); b[cnt] = B.point(base + pi); cnt++;
	}
	else if (d2 > rsum*rsum) {//相离 
		double ang = acos((A.r + B.r) / sqrt(d2));
		a[cnt] = A.point(base + ang); b[cnt] = B.point(base + ang); cnt++;
		a[cnt] = A.point(base - ang); b[cnt] = B.point(base - ang); cnt++;
	}
	return cnt;
}
/**********************************************************
二维几何常用算法
**********************************************************/
int ConvexHull(Point* p, int n, Point* ch)
{
	//输入点数组p，个数n，输出点数组ch，函数返回凸包的顶点数量
	//输入点钟不能有重复点
	//函数执行完成后p的顺序将会被破坏 
	// 如果在凸包的边界上不希望出现输入的点的话把两个<=改成<
	//精度高时采用dcmp比较 
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--)
	{
		while (m > k&&Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = p[i];
	}
	if (n > 1) m--;
	return m;
}