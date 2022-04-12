#include<bits/stdc++.h>
using namespace std;

// 没有想到字符串排序呀！！！

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		sort(strs.begin(), strs.end());
		string st = strs.front(), en = strs.back();
		int i, num = min(st.size(), en.size());
		for (i = 0; i < num && st[i] == en[i]; i++);  // 此处分号不能少，不能少！！！
		return string(st, 0, i);
	}
};

//	排序，取第一个和最后一个元素的公共前缀即可
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		sort(strs.begin(), strs.end());
		string st = strs[0];
		string en = strs[strs.size() - 1];
		int len = 0;
		for (int i = 0; i < st.size(); i++) {
			if (st[i] == en[i]) len++;
			else break;
		}
		return st.substr(0, len);
	}
};