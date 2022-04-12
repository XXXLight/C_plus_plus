#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> res;
	void DFS(int l, int r, string tmp) { // 注意别string& tmp，不要传引用
		// l,r表示剩下的括号数
		if (l == 0 && r == 0) {
			res.push_back(tmp);
			return;
		}
		if (l > r) return;	
		if (l > 0) DFS(l - 1, r, tmp + "(");	//这里无论单引号或是双引号都可
		if (r > 0) DFS(l, r - 1, tmp + ")");
	}
	vector<string> generateParenthesis(int n) {
		DFS(n, n, "");
		return res;
	}
};