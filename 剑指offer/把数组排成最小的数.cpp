#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string minNumber(vector<int>& nums) {
		vector<string> v;
		string res;
		for (auto e : nums) v.push_back(to_string(e));
		sort(v.begin(), v.end(), [](auto& e1, auto& e2) {return e1 + e2 < e2 + e1; });
		for (auto e : v) res += e;
		return res;
	}
};