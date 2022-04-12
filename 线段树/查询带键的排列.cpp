#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int MX;
	int *bit;
	void init(int n) {
		MX = n;
		bit = new int[MX + 1];
		memset(bit, 0, (MX + 1) * 4);
	}
	int lowbit(int x) {
		return x & (-x);
	}
	void add(int x, int v) {
		for (; x <= MX; x += lowbit(x)) {
			bit[x] += v;
		}
	}

	int ask(int x) {
		int ret = 0;
		for (; x; x -= lowbit(x)) {
			ret += bit[x];
		}
		return ret;
	}
	vector<int> processQueries(vector<int>& queries, int m) {
		int n = queries.size();
		init(n + m);
		//将值映射到n+1~n+m
		vector<int> pos(m + 1, 0);
		for (int i = 1; i <= m; i++) {
			add(n + i, 1);
			pos[i] = n + i;
		}

		vector<int> ans(queries.size(), 0);
		for (int i = 0; i < queries.size(); i++) {
			//获取位置
			int p = pos[queries[i]];
			//查询个数
			ans[i] = ask(p - 1);
			//更新
			add(p, -1);
			//更新新坐标
			pos[queries[i]] = n - i;
			add(n - i, 1);
		}
		return ans;
	}
};

