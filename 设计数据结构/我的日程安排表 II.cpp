#include<bits/stdc++.h>
using namespace std;


class MyCalendarTwo {
public:
	map<int, int> rec;

	MyCalendarTwo() {}

	bool book(int start, int end) {
		rec[start] += 1;
		rec[end] -= 1;
		int cur = 0;

		for (auto& p : rec) {
			cur += p.second;
			if (cur > 2) {   // 若修改成 cur > 1， 则对应着「我的日程安排表Ⅰ」 的代码
				rec[start]--, rec[end]++;
				return false;
			}
		}
		return true;
	}
};


