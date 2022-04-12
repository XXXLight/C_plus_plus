#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int month[13][2] = { {0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},
{31,31},{31,31},{30,30},{31,31},{30,30},{31,31} };  //0ƽ1�� 
	bool isLead(int year) {   //�Ƿ�Ϊ���� 
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
		int ans = 0;  //Ϊʲô��ʼֵ��1�������˵�����һ����ô��ֵ���2 
		while (m2 > m1 || d2 > d1 || y2 > y1) {
			d1++;   //������1 
			ans++;
			if (d1 == month[m1][isLead(y1)] + 1) {  //������������� 
				m1++;
				d1 = 1;
			}
			if (m1 == 13) {  //�����12����  
				y1++;
				m1 = 1;
			}
		}
		return ans;
	}
};


// ʹ������ķ����������������
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
		for (int i = 1971; i < year; i++) days += 365 + isleap(i);// 1971ֻ�ǲο�ֵ�����������滻
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
		// ʹ��istringstream�����ķ���
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