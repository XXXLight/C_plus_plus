#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<int> tree;
	int n;
	int lowbit(int i) {
		return i & -i;
	}
	void update(int id, int x) { // 将id更新为x
		while (id <= n) {
			tree[id] = max(tree[id], x);
			id += lowbit(id);
		}
	}
	int query(int id) {
		int ans = 0;
		while (id) {
			ans = max(ans, tree[id]);
			id -= lowbit(id);
		}
		return ans;
	}
	vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
		vector<int> diff = obstacles; // 离散化数组
		sort(diff.begin(), diff.end());
		n = unique(diff.begin(), diff.end()) - diff.begin();
		tree.resize(n + 1, 0);
		vector<int> ans;
		for (auto& i : obstacles) {
			int idx = lower_bound(diff.begin(), diff.begin() + n, i) - diff.begin() + 1;
			int res = query(idx);
			ans.push_back(res + 1);
			update(idx, res + 1);
		}
		return ans;
	}
};
