#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	map<int, vector<int>> mp;// y--->{x1,x2,x3.....}
	vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
		vector<int> res;
		// y1--->{x1,x2,x3}  ��ͬ��y����ĵ����һ����x��������
		for (auto& e : rectangles) {
			mp[e[1]].push_back(e[0]);
		}
		// �Ժ������������
		for (auto&[u, v] : mp) {
			// sort(begin(v), end(v));Ҳ��������д��ѧϰ��
			sort(v.begin(), v.end());
		}
		for (auto& e : points) {
			int x0 = e[0], y0 = e[1];
			int cnt = 0;
			for (auto&[y, v] : mp) {
				// y������������ֱ������
				if (y < y0) continue;
				// ���ֲ��ҵ�һ�����ڵ���x0��x�±�
				int index = lower_bound(v.begin(), v.end(), x0) - v.begin();
				cnt += v.size() - index;
			}
			res.push_back(cnt);
		}
		return res;
	}
};