#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	struct node {
		string str;
		int step;
	};
	//判断a与b是否只有1出不同。
	bool ischangeOne(string a, string b) {
		int n = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i])n++;
		}
		return n == 1;
	}
	int minMutation(string start, string end, vector<string>& bank) {
		vector<bool> vis = vector<bool>(bank.size());//标记是否访问过
		queue<node> qq;
		qq.push({ start,0 });
		while (!qq.empty()) {
			auto[str, step] = qq.front(); qq.pop();
			if (str == end) {
				return step;
			}
			for (int i = 0; i < bank.size(); i++) {
				//如果访问过就跳过，如果相差不是1处就跳过
				if (vis[i] || !ischangeOne(str, bank[i]))continue;
				qq.push({ bank[i],step + 1 });
				vis[i] = 1;
			}
		}
		return -1;
	}
};

