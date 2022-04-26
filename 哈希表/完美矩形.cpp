#include<bits/stdc++.h>
using namespace std;


//������������� ��ôһ���������㣺 
//��1�������� ������ ������ ������ ���ĸ���ֻ����һ�� ������ɶԳ��� 
//��2���ĸ���Χ�ǵľ������ = С���ε����֮��
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







