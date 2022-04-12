#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int circleGame(vector<vector<int>>& toys, vector<vector<int>>& circles, int r) {
		sort(begin(circles), end(circles));

		int res = 0;
		for (auto toy : toys) { //对每个玩具，检测其是否能被某个圈套中
			int xi = toy[0], yi = toy[1], ri = toy[2];
			if (r < ri) { //玩具比圈大，必然无法被套中
				continue;
			}

			//确定圈的检索范围
			auto beg_it = lower_bound(
				begin(circles), end(circles), vector<int>{xi - (r - ri), -1});
			auto end_it = upper_bound(
				begin(circles), end(circles), vector<int>{xi + (r - ri), INT_MAX});

			for (auto it = beg_it; it != end_it; ++it) {
				if (pow((*it)[0] - xi, 2) + pow((*it)[1] - yi, 2) <= pow(r - ri, 2)) {
					++res;
					break;
				}
			}
		}

		return res;
	}
};

