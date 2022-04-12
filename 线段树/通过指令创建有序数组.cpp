#include<bits/stdc++.h>
using namespace std;


class BIT {
private:
	int n;
	vector<int> tree;

public:
	BIT(int _n) : n(_n), tree(_n + 1) {}

	static constexpr int lowbit(int x) {
		return x & (-x);
	}

	void update(int x) {
		while (x <= n) {
			++tree[x];
			x += lowbit(x);
		}
	}

	int query(int x) const {
		int ans = 0;
		while (x) {
			ans += tree[x];
			x -= lowbit(x);
		}
		return ans;
	}
};

class Solution {
private:
	static constexpr int mod = 1000000007;

public:
	int createSortedArray(vector<int>& instructions) {
		int ub = *max_element(instructions.begin(), instructions.end());
		BIT bit(ub);
		long long ans = 0;
		for (int i = 0; i < instructions.size(); ++i) {
			int x = instructions[i];
			int smaller = bit.query(x - 1);
			int larger = i - bit.query(x);
			ans += min(smaller, larger);
			bit.update(x);
		}
		return ans % mod;
	}
};

