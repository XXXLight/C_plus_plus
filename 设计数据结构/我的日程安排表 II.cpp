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
			if (cur > 2) {   // ���޸ĳ� cur > 1�� ���Ӧ�š��ҵ��ճ̰��ű�� �Ĵ���
				rec[start]--, rec[end]++;
				return false;
			}
		}
		return true;
	}
};


