#include<bits/stdc++.h>
using namespace std;


class MyCalendarThree {
public:
	map<int, int> mp;
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

