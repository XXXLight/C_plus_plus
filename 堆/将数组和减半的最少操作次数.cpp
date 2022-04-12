#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	priority_queue<double> p;// ◊¢“‚ π”√double
	int halveArray(vector<int>& nums) {
		long double res = 0, sum = 0, s = 0;
		for (auto& e : nums) sum += e;
		for (auto& e : nums) p.emplace(e);
		long double thr = sum / 2;
		int cnt = 0;
		while (s < thr) {
			double t = p.top();
			s += t / 2;
			p.pop();
			p.emplace(t / 2);
			cnt++;
		}
		return cnt;
	}
};