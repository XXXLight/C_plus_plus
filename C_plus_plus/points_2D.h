#pragma once
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*****************************************************************
����������������Լ��Ӽ������˱ȽϵȻ�������
*****************************************************************/

const double pi = acos(-1.0);
struct Point {
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) {

	}
};//��Ľṹ�� 
typedef Point Vector;//ͬʱҲ������ 
Vector operator+(Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y); }//������� 
Vector operator-(Vector a, Vector b) { return Vector(a.x - b.x, a.y - b.y); }//������� ���õ�����ba 
Vector operator*(Vector a, double b) { return Vector(a.x*b, a.y*b); }//��������һ���� 
Vector operator/(Vector a, double b) { return Vector(a.x / b, a.y / b); }//������ȥһ���� 
bool operator< (const Point &a, const Point &b)
{
	return a.x < b.x || (a.x == b.x&&a.y < b.y);
}//����Ե�����������ݵ��������Ϊˮƽ����С�ľ�СһЩ����ˮƽ�������ʱ��������С��С 
const double eps = 1e-10;//�����ʵ�����Ϊ1e-8
int dcmp(double x)
{
	if (fabs(x) < eps) return 0;
	if (x < 0) return -1;
	return 1;
}
bool operator==(const Point &a, const Point &b)
{
	return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;//���������㣩����Ƚ������� 
}
/*********************************************
����֮���һЩ��������
*********************************************/
//�����������ļ���
double Dot(Vector a, Vector b)
{
	return a.x*b.x + a.y*b.y;//�����ĵ�� 
}
double Length(Vector a)
{
	return sqrt(Dot(a, a));//��������a�ĳ��� 
}
double Angle(Vector a, Vector b)
{
	return acos(Dot(a, b) / Length(a) / Length(b));//��������a,b�ļн� 
}
double Cross(Vector a, Vector b)
{
	return a.x*b.y - a.y*b.x;
	//����a��b���мǣ������ǰ��֮�� 
	//b����a����ʱ�뷽��ʱΪ�� 
}
double Area2(Point a, Point b, Point c)
{
	return Cross(b - a, c - a);
	//����a,b,c���㹹�ɵ������ε���������� 
	//ע�⣺ab����aָ��b����������ac��aָ��c����������
	//ac��ab����ʱ�뷽��ʱ�����Ϊ������֮Ϊ�� 
}
Vector Rotate(Vector a, double rad)
{
	return Vector(a.x*cos(rad) - a.y*sin(rad), a.x*sin(rad) + a.y*cos(rad));
	//rad�ǻ��ȣ���ת����Ϊ��ʱ�� 
}
Vector Normal(Vector a)
{
	double L = Length(a);
	return Vector(-a.y / L, a.x / L);
	//���a�����ĵ�λ������
	//��ʱ����ת90�ȵķ����� 
}
//����һ�����������ֵ�������ķ�������һЩ
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
//conj���ظø����Ĺ����
//imag���ظ������鲿
//real���ظ�����ʵ��
************************************************************************************/
/***********************************************************************************
����Ϊ���ֱ��
************************************************************************************/
struct Line {
	Point p;
	Vector v;
	Line(double px, double py, double ex, double ey) :p(px, py), v(ex - px, ey - py) {}
	Line(double px, double py, Point a) :
		p(px, py), v(a.x - px, a.y - py) {}
	Line(Point a, Point b) :
		p(a.x, b.x), v(b.x - a.x, b.y - a.y) {}
	Point point(int x)//��֪һ��ĺ����꣬����� 
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
	//����ֱ��p+tv��q+tw�Ľ��㣨v,w�ֱ��������ߵķ���������p��q�ֱ���ֱ���ϵ�һ�㣩 
	//��Ҫע�����Cross��v��w�����ܹ��� 
}
double Distancetoline(Point p, Point a, Point b)
{
	Vector v1 = b - a, v2 = p - a;
	return fabs(Cross(v1, v2)) / Length(v1);
	//���p��ֱ��ab�ľ��� 
}
double Distancetosegment(Point p, Point a, Point b)
{
	if (a == b) return Length(p - a);
	Vector v1 = b - a, v2 = p - a, v3 = p - b;
	if (dcmp(Dot(v1, v2)) < 0) return Length(v2);
	if (dcmp(Dot(v1, v3)) > 0) return Length(v3);
	return  fabs(Cross(v1, v2)) / Length(v1);
	//���p��ֱ��ab����С���� 
}
Point GetLineProjection(Point p, Point a, Point b)
{
	Vector v = b - a;
	return a + v * (Dot(v, p - a) / Dot(v, v));
	//p��ֱ��ab�ϵ�ͶӰ�� 
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
	double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
		c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - a1);
	return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
	//�ж�a1a2��b1b2�Ƿ��ཻ�����㲻��a1,a2,b1,b2�ϣ� 
	//���c1c2��ʾ��ֱ�߹��� 
}
//��c1c2��ͬʱΪ��ʱ������һ��һ���߶��ڣ���һ��ֱ���ϵĶ˵���������Ҫ���º����ж�ĳ���Ƿ���ֱ����
bool OnSegment(Point p, Point a1, Point a2)
{
	return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
	//�ò���ж�ʱ��������ֱ���ϣ��õ���ж��Ƿ����߶���
	//�ж�p���Ƿ����߶�a1a2�� 
}
/***************************************
����������ʽ
***************************************/
double PolygonArea(Point* p, int n)
{
	double area = 0;
	for (int i = 1; i < n - 1; i++)
	{
		area += Cross(p[i] - p[0], p[i + 1] - p[0]);
	}
	return area / 2;
	//ע��˷����ĵó�����������ڲ��ܱ�֤��ķֲ���˳ʱ�뻹�ǰ���ʱ���ʱ����Ҫ���Ͼ���ֵ
	//p�ǵ�����飬n�Ƕ���εı�����Ҳ�ǵ��� 
}
/**********************************************************
��Բ�����йصļ�������
**********************************************************/
struct Circle {
	Point c;//Բ�� 
	double r;//�뾶
	Circle(Point c, double r) :c(c), r(r) {}
	Point point(double rad)
	{
		return Point(c.x + cos(rad)*r, c.y + sin(rad)*r);// Բ��rad�Ǵ�������� 
	}
};
int getLineCircleIntersection(Line L, Circle C, double &t1, double &t2, vector<Point>& sol)
{
	double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
	double e = a * a + c * c, f = 2 * (a*b + c * d), g = b * b + d * d - C.r*C.r;
	double delta = f * f - 4 * e*g;
	if (dcmp(delta) < 0) return 0; //���� 
	if (dcmp(delta) == 0)   //���� 
	{
		t1 = t2 = -f / (2 * e);//tΪ����ĺ����� 
		sol.push_back(L.point(t1));
		return 1;
	}
	//�ཻ 
	t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(L.point(t1));
	t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(L.point(t2));
	return 2;
}
//�����ļ��� 
double angle(Vector v) { return atan2(v.y, v.x); }

int getCircleCircleIntersection(Circle c1, Circle c2, vector<Point>& sol)
{
	double d = Length(c1.c - c2.c);
	if (dcmp(d) == 0)
	{
		if (dcmp(c1.r - c2.r) == 0) return -1;//��Բ�ཻ
		return 0;//����Բ��ʱ����뾶��С����ͬ��ض��޽��� 
	}
	if (dcmp(c1.r + c2.r - d) < 0) return 0;
	if (dcmp(fabs(c1.r - c2.r) - d) > 0) return 0;
	double a = angle(c2.c - c1.c);
	double da = acos((c1.r*c1.r + d * d - c2.r*c2.r) / (2 * c1.r*d));
	//c1c2��c1p1�Ľǣ�p1�ǽ��㣩
	Point p1 = c1.point(a - da), p2 = c1.point(a + da);
	sol.push_back(p1);
	if (p1 == p2) return 1;
	sol.push_back(p2);
	return 2;
	//��������������Բ֮����ཻ��� 
}
int getTangents(Point p, Circle c, Vector* v)
{
	Vector u = c.c - p;
	double dist = Length(u);
	if (dist < c.r) return 0;//����Բ�ڲ����ܳ�������
	if (dcmp(dist - c.r) == 0) {
		v[0] = Rotate(u, pi / 2);
		return 1;
		//����Բ��ǡ��һ������ 
	}
	double ang = asin(c.r / dist);
	v[0] = Rotate(u, -ang);
	v[1] = Rotate(u, ang);
	return 2;//��������
	//������������һ�����Բ���ܲ��������� 
}
int getTangents(Circle A, Circle B, Point* a, Point* b)
{
	int cnt = 0;
	if (A.r < B.r)
	{
		swap(A, B);
		swap(a, b);
	}
	int d2 = (A.c.x - B.c.x)*(A.c.x - B.c.x) + (A.c.y - B.c.y)*(A.c.y - B.c.y);//Բ�ľ����ƽ�� 
	int rdiff = A.r - B.r;
	int rsum = A.r + B.r;
	if (d2 < rdiff*rdiff) return 0;
	//��Բ��Բ�ľ���С�ڰ뾶��
	//�ں� 
	double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);//Բ�����ߵļ��� 
	if (d2 == 0 && A.r == B.r) return -1;//��Բ�غ� 
	if (d2 == rdiff * rdiff) {
		a[cnt] = A.point(base); b[cnt] = B.point(base);
		cnt++;
		return 1;
	}
	//�⹫����
	double ang = acos((A.r - B.r) / sqrt(d2));
	a[cnt] = A.point(base + ang); b[cnt] = B.point(base + ang); cnt++;
	a[cnt] = A.point(base - ang); b[cnt] = B.point(base - ang); cnt++;
	if (d2 == rsum * rsum) {
		a[cnt] = A.point(base); b[cnt] = B.point(base + pi); cnt++;
	}
	else if (d2 > rsum*rsum) {//���� 
		double ang = acos((A.r + B.r) / sqrt(d2));
		a[cnt] = A.point(base + ang); b[cnt] = B.point(base + ang); cnt++;
		a[cnt] = A.point(base - ang); b[cnt] = B.point(base - ang); cnt++;
	}
	return cnt;
}
/**********************************************************
��ά���γ����㷨
**********************************************************/
int ConvexHull(Point* p, int n, Point* ch)
{
	//���������p������n�����������ch����������͹���Ķ�������
	//������Ӳ������ظ���
	//����ִ����ɺ�p��˳�򽫻ᱻ�ƻ� 
	// �����͹���ı߽��ϲ�ϣ����������ĵ�Ļ�������<=�ĳ�<
	//���ȸ�ʱ����dcmp�Ƚ� 
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