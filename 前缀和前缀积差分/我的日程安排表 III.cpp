#include<bits/stdc++.h>
using namespace std;


class MyCalendarThree {
public:
	map<int, int> mp;// 差分问题必须使用有序哈希表
	MyCalendarThree() {

	}

	int book(int start, int end) {
		mp[start] += 1;
		mp[end] -= 1;
		int ans = 0, cur = 0;
		for (auto&[a, b] : mp) {
			cur += b;
			ans = max(ans, cur);
		}
		return ans;
	}
};