#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		map<int, int> mp;
		// 求导
		for (auto& e : trips) {
			mp[e[1]] += e[0];
			mp[e[2]] -= e[0];
		}
		// 积分
		int sum = 0;
		for (auto&[u, v] : mp) {
			sum += v;
			if (sum > capacity) return false;
		}
		return true;
	}
};