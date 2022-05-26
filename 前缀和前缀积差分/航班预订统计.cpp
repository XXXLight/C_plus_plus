#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	map<int, int> mp;
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
		for (auto& e : bookings) {
			mp[e[0]] += e[2];
			mp[e[1] + 1] -= e[2];
		}
		vector<int> res(n, 0);
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (not mp.count(i)) mp[i] = 0;
			sum += mp[i];
			res[i - 1] = sum;
		}
		return res;
	}
};