#include<bits/stdc++.h>
using namespace std;

// (a&b)^(a&c) = a&(b^c)
class Solution {
public:
	int getXORSum(vector<int>& arr1, vector<int>& arr2) {
		int xorArr2 = 0;
		for (auto e : arr2) xorArr2 ^= e;
		vector<int> v;
		for (auto e : arr1) v.push_back(e&xorArr2);
		int res = 0;
		for (auto e : v) res ^= e;
		return res;
	}
};