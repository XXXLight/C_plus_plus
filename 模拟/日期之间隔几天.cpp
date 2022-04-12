#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int month[13][2] = { {0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},
{31,31},{31,31},{30,30},{31,31},{30,30},{31,31} };  //0平1闰 
	bool isLead(int year) {   //是否为闰年 
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	int daysBetweenDates(string date1, string date2) {
		if (date1 > date2) swap(date1, date2);
		int y1 = stoi(date1.substr(0, 4));
		int m1 = stoi(date1.substr(5, 2));
		int d1 = stoi(date1.substr(8, 2));
		int y2 = stoi(date2.substr(0, 4));
		int m2 = stoi(date2.substr(5, 2));
		int d2 = stoi(date2.substr(8, 2));
		int ans = 0;  //为什么初始值是1，题干中说如果差一天那么差值输出2 
		while (m2 > m1 || d2 > d1 || y2 > y1) {
			d1++;   //天数加1 
			ans++;
			if (d1 == month[m1][isLead(y1)] + 1) {  //如果满当月天数 
				m1++;
				d1 = 1;
			}
			if (m1 == 13) {  //如果满12个月  
				y1++;
				m1 = 1;
			}
		}
		return ans;
	}
};


// 使用下面的方法更加有助于理解
class Solution {
public:
	int daysBetweenDates(string date1, string date2) {
		return abs(get(date1) - get(date2));
	}
	bool isleap(int year) {
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
	int m_days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int get(string date) {
		int year, month, day;
		sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
		int days = 0;
		for (int i = 1971; i < year; i++) days += 365 + isleap(i);// 1971只是参考值，可以任意替换
		for (int i = 1; i < month; i++) {
			if (i == 2) days += 28 + isleap(year);
			else days += m_days[i];
		}
		return days + day;
	}
};



class Solution {
public:
	int daysBetweenDates(string date1, string date2) {
		return abs(get(date1) - get(date2));
	}
	bool isleap(int year) {
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
	int m_days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int get(string date) {
		// 使用istringstream流动的方法
		int year, month, day;
		char c1, c2;
		istringstream s(date);
		s >> year, s >> c1, s >> month, s >> c2, s >> day;
		int days = 0;
		for (int i = 1971; i < year; i++) days += 365 + isleap(i);
		for (int i = 1; i < month; i++) {
			if (i == 2) days += 28 + isleap(year);
			else days += m_days[i];
		}
		return days + day;
	}
};