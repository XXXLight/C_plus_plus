#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> res;
	void DFS(int l, int r, string tmp) { // ע���string& tmp����Ҫ������
		// l,r��ʾʣ�µ�������
		if (l == 0 && r == 0) {
			res.push_back(tmp);
			return;
		}
		if (l > r) return;	
		if (l > 0) DFS(l - 1, r, tmp + "(");	//�������۵����Ż���˫���Ŷ���
		if (r > 0) DFS(l, r - 1, tmp + ")");
	}
	vector<string> generateParenthesis(int n) {
		DFS(n, n, "");
		return res;
	}
};