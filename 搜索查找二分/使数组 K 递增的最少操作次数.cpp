#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int kIncreasing(vector<int>& arr, int k) {
		int ret = 0;
		int n = arr.size();
		vector<int> v;
		v.reserve((n + k - 1) / k);
		for (int i = 0; i < k; ++i) {
			v.clear();
			v.push_back(arr[i]);
			for (int j = i + k; j < n; j += k) {
				if (arr[j] >= v.back()) {
					v.push_back(arr[j]);
				}
				else {
					int pos = upper_bound(v.begin(), v.end(), arr[j]) - v.begin();
					v[pos] = arr[j];
					ret++;
				}
			}
		}
		return ret;
	}
};