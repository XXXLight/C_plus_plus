#include<bits/stdc++.h>
using namespace std;


//如果是完美矩形 那么一定满足两点： 
//（1）最左下 最左上 最右下 最右上 的四个点只出现一次 其他点成对出现 
//（2）四个点围城的矩形面积 = 小矩形的面积之和
class Solution {
	inline int area(int x1, int y1, int x2, int y2) { return 1LL * (x2 - x1)*(y2 - y1); }
public:
	bool isRectangleCover(vector<vector<int>>& r) {
		int sumArea = 0;
		map <pair<int, int>, int> point;
		for (auto m : r) {
			sumArea += area(m[0], m[1], m[2], m[3]);
			++point[{m[0], m[1]}];
			++point[{m[2], m[3]}];
			++point[{m[0], m[3]}];
			++point[{m[2], m[1]}];
		}
		vector<pair<int, int>> reM;
		for (auto &p : point) if (p.second & 1) reM.push_back(p.first);
		if (reM.size() == 4) return sumArea == area(reM[0].first, reM[0].second, reM[3].first, reM[3].second);
		return false;
	}
};







