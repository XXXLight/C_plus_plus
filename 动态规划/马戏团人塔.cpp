#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
		int len = height.size();
		vector<vector<int>> v(len, vector<int>(2, 0));
		vector<int> help;
		for (int i = 0; i < len; i++) {
			v[i][0] = height[i];
			v[i][1] = weight[i];
		}
		sort(v.begin(), v.end(), [](auto e1, auto e2) {return e1[0] < e2[0] || e1[0] == e2[0] && (e1[1] > e2[1]); });
		for (auto e : v) help.push_back(e[1]);
		vector<int> lis;
		lis.push_back(help[0]);
		for (int i = 1; i < help.size(); i++) {
			if (help[i] > lis.back()) {
				lis.push_back(help[i]);
			}
			else {
				int index = lower_bound(lis.begin(), lis.end(), help[i]) - lis.begin();
				lis[index] = help[i];
			}
		}
		return lis.size();
	}
};