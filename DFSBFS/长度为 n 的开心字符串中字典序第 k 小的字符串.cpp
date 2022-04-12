#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
	vector<string> ans;
	string str;
public:
	void backtrack(int n, int pos) {
		if (str.size() > 1 && str[str.size() - 1] == str[str.size() - 2]) return; // 不符合开心字符串要求
		if (n == pos) { // 已经到最后一个字符
			ans.push_back(str);
			return;
		}
		for (int i = 0; i < 3; ++i) { // 有三种可能
			str.push_back('a' + i);
			backtrack(n, pos + 1);
			str.pop_back();
		}
	}
	string getHappyString(int n, int k) {
		backtrack(n, 0);
		return k > ans.size() ? "" : ans[k - 1];
	}
};

