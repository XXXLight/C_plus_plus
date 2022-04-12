#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> mp;
		for (auto& e : strs) {
			auto temp = e;
			sort(temp.begin(), temp.end());
			mp[temp].push_back(e);
		}
		for (auto&[u, v] : mp) {
			res.push_back(v);
		}
		return res;
	}
};