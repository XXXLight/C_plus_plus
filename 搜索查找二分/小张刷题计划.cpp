#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	bool Check(int limit, vector<int> cost, int day) {
		// 每组划分 limit 的最大和，贪心划分看有多少组
		int useday, totaltime, maxtime;
		useday = 1; totaltime = maxtime = 0;
		for (int i = 0; i < cost.size(); ++i) {
			int nexttime = min(maxtime, cost[i]);
			if (nexttime + totaltime <= limit) {
				totaltime += nexttime;
				maxtime = max(maxtime, cost[i]);
			}
			else {
				++useday;
				totaltime = 0;
				maxtime = cost[i];
			}
		}
		return (useday <= day);
	}
	int minTime(vector<int>& time, int m) {
		int left, right, middle;
		left = right = 0;
		for (int i = 0; i < time.size(); ++i) {
			right += time[i];
		}
		while (left <= right) {
			middle = (left + right) >> 1;
			if (Check(middle, time, m)) right = middle - 1;
			else left = middle + 1;
		}
		return left;
	}
};

