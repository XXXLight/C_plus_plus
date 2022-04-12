#pragma once
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

//���ַ�����㣬�������cout<<setprecision(13)<<zero_point_binary() ���޶����λ����
//����������x^3=7��x,��Ҫ���ݺ�����͹�Էֱ�滮����
double zero_point_binary() {
	const double e = pow(10, -15); //����
	double left = 1.9, right = 2.0; //ȷ�����Ե���������
	double mid; //�������
	while (abs(right - left) > e) { //����������ھ���
		mid = (right + left) / 2; //��������
		if (pow(mid, 3) > 7) right = mid; //��С����
		else if (pow(mid, 3) < 7) left = mid; //��С����
	}
	return mid;
}


//ţ�ٷ������,�����ڲ��ܶ��庯������Ϊreturn�������壬���Զ����������ϵ����namespace������
namespace Zero_Point_Newton {
	double f(double x)  //ԭ���ĺ�������x^3-7�����
	{
		return x * x*x - 7;
	}
	double ff(double x) //�����ĵ���
	{
		return 3 * x*x;
	}
	double zero_point_newton(double x_0, double e) { //x_0��ʾ��ʼ��x�㣬e��ʾ����
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