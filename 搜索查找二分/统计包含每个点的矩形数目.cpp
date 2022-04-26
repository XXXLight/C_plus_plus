#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	map<int, vector<int>> mp;// y--->{x1,x2,x3.....}
	vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
		vector<int> res;
		// y1--->{x1,x2,x3}  相同的y坐标的点放在一起，且x有序排序
		for (auto& e : rectangles) {
			mp[e[1]].push_back(e[0]);
		}
		// 对横坐标进行排序
		for (auto&[u, v] : mp) {
			// sort(begin(v), end(v));也可以这样写，学习了
			sort(v.begin(), v.end());
		}
		for (auto& e : points) {
			int x0 = e[0], y0 = e[1];
			int cnt = 0;
			for (auto&[y, v] : mp) {
				// y不满足条件，直接跳过
				if (y < y0) continue;
				// 二分查找第一个大于等于x0的x下标
				int index = lower_bound(v.begin(), v.end(), x0) - v.begin();
				cnt += v.size() - index;
			}
			res.push_back(cnt);
		}
		return res;
	}
};