#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	unordered_map<int, vector<int>> mp;//  int --->  vector<int> 的映射，也可以用二维vector
	vector<long long> getDistances(vector<int>& arr) {
		vector<long long> res(arr.size(), 0);
		int len = arr.size();
		for (int i = 0; i < len; i++) {
			mp[arr[i]].push_back(i);
		}
		for (auto&[u, v] : mp) {
			// 求数组v的前缀和
			long long preSum = 0;
			vector<long long> pre;
			pre.push_back(0);
			for (auto& e : v) {
				preSum += e;
				pre.push_back(preSum);
			}
			for (int i = 0; i < v.size(); i++) {
				// [i,j]范围内前缀和pre[j+1]-pre[i]
				res[v[i]] = (2 * i - v.size() + 1)*v[i] + pre[v.size()] - pre[i + 1] - pre[i] + pre[0];
			}
		}
		return res;
	}
};