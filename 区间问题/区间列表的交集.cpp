#include<bits/stdc++.h>
using namespace std;

// 双指针
// 时间复杂度：o(M+N)
// 空间复杂度：o(M+N)

// 因为有序所以无需排序
class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
		vector<vector<int>> res;
		int i = 0, j = 0;
		// 注意这里是&&,退出条件是i = firstList.size() || j = secondList.size()，即有一个已经到达结尾
		while (i < firstList.size() && j < secondList.size()) {
			int L1 = firstList[i][0], R1 = firstList[i][1];
			int L2 = secondList[j][0], R2 = secondList[j][1];
			// 有交集，放结果
			if (L1 <= R2 && L2 <= R1) {
				res.push_back({ max(L1, L2), min(R1, R2) });
			}
			// 交替移动指针
			if (R2 <= R1) j++;
			else i++;
		}
		return res;
	}
};