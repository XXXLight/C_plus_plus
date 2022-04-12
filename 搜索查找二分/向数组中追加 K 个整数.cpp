#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	long long minimalKSum(vector<int>& nums, int k) {
		long long lo = 1, hi = 2e9;
		sort(nums.begin(), nums.end());
		nums.erase(unique(nums.begin(), nums.end()), nums.end());
		auto ok = [&](long long x) {
			int cnt = 0;
			for (auto &e : nums) {
				if (e <= x) {
					cnt++;
				}
				else {
					break;
				}
			}
			return x - cnt >= k;
		};
		while (lo < hi) {
			long long mid = (lo + hi) / 2;
			if (ok(mid)) {
				hi = mid;
			}
			else {
				lo = mid + 1;
			}
		}
		long long ans = hi * (hi + 1) / 2;
		for (auto &e : nums) {
			if (e <= hi) {
				ans -= e;
			}
		}
		return ans;
	}
};

