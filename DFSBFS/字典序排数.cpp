#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<int> res;
	void DFS(int n, int num) {
		if (num <= n && num > 0) {
			res.push_back(num);
		}
		if (num > n) {
			return;
		}
		for (int i = 0; i <= 9; i++) {
			if (i == 0 && num == 0) continue;
			num = num * 10 + i;// 下一层num的值
			DFS(n, num);
			num = (num - i) / 10;
		}
	}
	vector<int> lexicalOrder(int n) {
		DFS(n, 0);
		return res;
	}
};