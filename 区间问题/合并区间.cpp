#include<bits/stdc++.h>
using namespace std;

// 时间复杂度和空间复杂度由排序决定
// 时间复杂度：o(nlog(n))
// 空间复杂度：o(log(n))
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		// 必须先排序
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> res;
		// 用结果集的状态作为循环条件
		for (int i = 0; i < intervals.size(); i++) {
			// L,R是当前区间
			int L = intervals[i][0], R = intervals[i][1];
			// res.back是上一个区间
			if (res.empty() || res.back()[1] < L) {
				// 没有交集放当前的集合
				res.push_back({ L,R });
			}
			else if (res.back()[1] >= L) {
				// 有交集扩大区间
				res.back()[1] = max(res.back()[1], R);
			}
		}
		return res;
	}
};