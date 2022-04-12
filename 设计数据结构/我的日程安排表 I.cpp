#include<bits/stdc++.h>
using namespace std;


class MyCalendar {
public:
	map<int, int> mp;
	MyCalendar() {
	}

	bool book(int start, int end) {
		mp[start]++;
		mp[end]--;
		int ans = 0;
		for (map<int, int> ::iterator it = mp.begin(); it != mp.end(); it++) {
			ans += it->second;
			if (ans >= 2) {
				mp[start]--;
				mp[end]++;
				return false;
			}
		}
		return true;
	}
};
