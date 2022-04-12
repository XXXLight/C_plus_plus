#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

// 标准切割问题

class Solution {
public:
	// 唯一想到set
	unordered_set<string> st;
	int res = 0;
	void DFS(string s, int idx, int depth) {
		// 切割到字符串结尾，更新答案
		if (idx == s.size()) {
			res = max(res, depth);
		}
		// 切割出[index,i]位置的字符串
		for (int i = idx; i < s.size(); i++) {
			string str = s.substr(idx, i - idx + 1);
			if (st.find(str) == st.end()) {
				st.insert(str);
				DFS(s, i + 1, depth + 1);
				st.erase(str);
			}
		}
	}
	int maxUniqueSplit(string s) {
		DFS(s, 0, 0);
		return res;
	}
};