#include<bits/stdc++.h>
using namespace std;

class RangeFreqQuery {
	//vector<vector<int>> data;用二维哈希表和vector都可以
	unordered_map<int, vector<int>> data;
public:
	RangeFreqQuery(vector<int>& arr) : data(10001) {
		// 建立数组的值----》索引之间的映射，是一对多的关系
		for (int i = 0; i < arr.size(); ++i) {
			data[arr[i]].push_back(i);
		}
	}

	int query(int left, int right, int value) {
		return distance(lower_bound(data[value].begin(), data[value].end(), left),
			upper_bound(data[value].begin(), data[value].end(), right));
	}
};