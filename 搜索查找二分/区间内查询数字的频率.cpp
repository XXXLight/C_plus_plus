#include<bits/stdc++.h>
using namespace std;

class RangeFreqQuery {
	//vector<vector<int>> data;�ö�ά��ϣ���vector������
	unordered_map<int, vector<int>> data;
public:
	RangeFreqQuery(vector<int>& arr) : data(10001) {
		// ���������ֵ----������֮���ӳ�䣬��һ�Զ�Ĺ�ϵ
		for (int i = 0; i < arr.size(); ++i) {
			data[arr[i]].push_back(i);
		}
	}

	int query(int left, int right, int value) {
		return distance(lower_bound(data[value].begin(), data[value].end(), left),
			upper_bound(data[value].begin(), data[value].end(), right));
	}
};