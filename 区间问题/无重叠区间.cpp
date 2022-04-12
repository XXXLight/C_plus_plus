#include<bits/stdc++.h>
using namespace std;


// 记录：1.拉姆达表达式写法：[](a,b){return ;}
// 2.有点类似最长上升子序列
class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.size() == 0) return 0;
		int cnt = 1;
		// 类比bool cmp
		// 按l升序，r降序排列
		sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
			if (a[0] != b[0]) return a[0] < b[0];
			return a[1] > b[1];
		});
		// 维护前一个区间[L,R]
		int L = intervals[0][0], R = intervals[0][1];
		for (int i = 1; i < intervals.size(); i++) {
			//当前区间与上一个区间进行对比
			int curL = intervals[i][0], curR = intervals[i][1];
			// 因为是按左端点排序的，所以当前区间与上一个区间一共有三种关系
			// 1.包含 2.相交 3.远离
			// 1.包含
			if (curR <= R) {
				L = curL;
				R = curR;
			}
			// 3.远离
			else if (curL >= R) {
				L = curL;
				R = curR;
				cnt++;
			}
			// 2.相交 ，[L,R]不用处理
		}
		return intervals.size() - cnt;
	}
};