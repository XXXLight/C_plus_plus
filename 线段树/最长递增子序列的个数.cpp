#include<bits/stdc++.h>
using namespace std;


class Solution {
	class Node {
	public:
		int m, c;
		Node() : m(0), c(0) {}
		Node& operator+=(Node& b) {
			if (b.m > m)
				m = b.m, c = b.c;
			else if (b.m == m)
				c += b.c;
			return *this;
		}
	};
	void add(Node nodes[], int rk, Node &val, int N) {
		for (; rk <= N; rk += (rk & (-rk))) nodes[rk] += val;
	}
	Node query(Node nodes[], int rk) {
		Node res;
		for (; rk; rk -= (rk & (-rk))) res += nodes[rk];
		return res;
	}
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (nums.size() == 0) return 0;

		/* 离散化, 并用树状数组求解 */
		vector<int> numsort(nums.begin(), nums.end());
		sort(numsort.begin(), numsort.end());
		Node *nodes = new Node[nums.size() + 1], res = Node();

		for (int i : nums) {
			/* 离散化, 求出当前数字的 排名 - 1 */
			int rk = lower_bound(numsort.begin(), numsort.end(), i) - numsort.begin();

			/* 求出当前尾数的 最长序列长度 和 个数 */
			Node cur = query(nodes, rk);
			cur.m++, cur.c = max(cur.c, 1);

			/* 更新全局 最长序列长度 和 个数 */
			res += cur;

			/* 更新树状数组 */
			add(nodes, rk + 1, cur, nums.size());
		}

		return res.c;
	}
};

