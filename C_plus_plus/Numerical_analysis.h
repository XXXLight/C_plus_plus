#pragma once
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

//二分法求零点，输出采用cout<<setprecision(13)<<zero_point_binary() 来限定输出位数。
//比如以下求x^3=7的x,需要根据函数凹凸性分别规划区间
double zero_point_binary() {
	const double e = pow(10, -15); //精度
	double left = 1.9, right = 2.0; //确定粗略的左右区间
	double mid; //区间二分
	while (abs(right - left) > e) { //左右区间大于精度
		mid = (right + left) / 2; //二分区间
		if (pow(mid, 3) > 7) right = mid; //缩小区间
		else if (pow(mid, 3) < 7) left = mid; //缩小区间
	}
	return mid;
}


//牛顿法求零点,函数内不能定义函数，因为return会有歧义，所以多个函数有联系，用namespace包起来
namespace Zero_Point_Newton {
	double f(double x)  //原来的函数，求x^3-7的零点
	{
		return x * x*x - 7;
	}
	double ff(double x) //函数的导数
	{
		return 3 * x*x;
	}
	double zero_point_newton(double x_0, double e) { //x_0表示起始的x点，e表示精度
		int k = 0;
		double x[1000];
		while (1)
		{
			x[k + 1] = x[k] - f(x[k]) / ff(x[k]);
			if (abs(x[k + 1] - x[k]) < e)
			{
				return x[k + 1];
				break;
			}
			else k = k + 1;
		}
	}
}