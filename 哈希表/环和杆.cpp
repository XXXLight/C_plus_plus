#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int countPoints(string rings) {
		int len = rings.size();
		unordered_map<char, set<char>> mp;  // 建立char到set<char>之间的映射
		for (int i = 1; i < len; i += 2) {
			mp[rings[i]].insert(rings[i - 1]);
		}
		int res = 0;
		for (auto&[u, v] : mp) {
			if (v.size() == 3) res++;
		}
		return res;
	}
};