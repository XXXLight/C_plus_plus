#include<bits/stdc++.h>
using namespace std;



class MyCalendarTwo {
public:
	map<int, int> mp;// ����������ʹ�������ϣ������ʹ��unordered_map
	MyCalendarTwo() {

	}

	bool book(int start, int end) {
		mp[start]++;
		mp[end]--;
		int sum = 0;
		for (auto&[u, v] : mp) {
			sum += v;
			if (sum >= 3) {
				mp[start]--;
				mp[end]++;
				return false;
			}
		}
		return true;
	}
};