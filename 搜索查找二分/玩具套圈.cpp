#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int circleGame(vector<vector<int>>& toys, vector<vector<int>>& circles, int r) {
		sort(begin(circles), end(circles));

		int res = 0;
		for (auto toy : toys) { //��ÿ����ߣ�������Ƿ��ܱ�ĳ��Ȧ����
			int xi = toy[0], yi = toy[1], ri = toy[2];
			if (r < ri) { //��߱�Ȧ�󣬱�Ȼ�޷�������
				continue;
			}

			//ȷ��Ȧ�ļ�����Χ
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

