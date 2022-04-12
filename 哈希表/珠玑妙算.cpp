#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


class Solution {
public:
	vector<int> masterMind(string solution, string guess) {
		unordered_map<int, int> mp;
		int len = solution.size();
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < len; i++) {
			if (solution[i] == guess[i]) cnt1++;
			else {
				mp[solution[i]]++;
			}
		}
		for (int i = 0; i < len; i++) {
			if (solution[i] == guess[i]) continue;
			if (mp[guess[i]]) { cnt2++; mp[guess[i]]--; }
		}
		return { cnt1,cnt2 };
	}
};