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

		/* ��ɢ��, ������״������� */
		vector<int> numsort(nums.begin(), nums.end());
		sort(numsort.begin(), numsort.end());
		Node *nodes = new Node[nums.size() + 1], res = Node();

		for (int i : nums) {
			/* ��ɢ��, �����ǰ���ֵ� ���� - 1 */
			int rk = lower_bound(numsort.begin(), numsort.end(), i) - numsort.begin();

			/* �����ǰβ���� ����г��� �� ���� */
			Node cur = query(nodes, rk);
			cur.m++, cur.c = max(cur.c, 1);

			/* ����ȫ�� ����г��� �� ���� */
			res += cur;

			/* ������״���� */
			add(nodes, rk + 1, cur, nums.size());
		}

		return res.c;
	}
};

