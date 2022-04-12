#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	unordered_map<int, int> mp;
	vector<string> findLongestSubarray(vector<string>& array1) {
		vector<string> res;
		mp[0] = -1;
		int cntalp = 0;
		int cntnum = 0;
		int start = 0, maxLen = 0;
		for (int i = 0; i < array1.size(); i++) {
			if (isalpha(array1[i][0])) cntalp++;
			else cntnum++;
			int diff = cntalp - cntnum;
			if (mp.count(diff)) {
				int curLen = i - mp[diff];
				if (curLen > maxLen) {
					maxLen = curLen;
					start = mp[diff] + 1;
				}
			}
			if (not mp.count(diff))
				mp[diff] = i;
		}
		// Êý×é¿½±´
		res.resize(maxLen);
		for (int i = start; i <= start + maxLen - 1; i++) {
			res[i - start] = array1[i];
		}
		return res;
		//return vector<string>(array1.begin() + start, array1.begin() + start + maxLen);
	}
};