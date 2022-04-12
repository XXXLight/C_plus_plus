#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


class Solution {
public:
	long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		vector<int> pos(n);
		for (int i = 0; i < n; ++i) {
			pos[nums2[i]] = i;
		}

		long long ans = 0;
		tree.resize(n + 1);

		// 只需要在 [1, n-1) 范围内枚举 pos1_y 即可
		for (int i = 1; i < n - 1; ++i) {
			update(pos[nums1[i - 1]] + 1);
			int p = pos[nums1[i]];
			int t = query(p);
			ans += static_cast<long long>(t) * (n - i - p + t - 1);
		}

		return ans;
	}

	static int lowbit(int x) {
		return x & (-x);
	}

	void update(int x) {
		while (x < tree.size()) {
			++tree[x];
			x += lowbit(x);
		}
	}

	int query(int x) {
		int ans = 0;
		while (x) {
			ans += tree[x];
			x -= lowbit(x);
		}
		return ans;
	}

private:
	vector<int> tree;
};





// 模板类
template <class T> class FenwickTree {
	int limit;
	vector<T> arr;

	int lowbit(int x) { return x & (-x); }

public:
	FenwickTree(int limit) {
		this->limit = limit;
		arr = vector<T>(limit + 1);
	}

	void update(int idx, T delta) {
		for (; idx <= limit; idx += lowbit(idx))
			arr[idx] += delta;
	}

	T query(int idx) {
		T ans = 0;
		for (; idx > 0; idx -= lowbit(idx))
			ans += arr[idx];
		return ans;
	}
};
class Solution {
public:
	long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		FenwickTree<int> occur(n);
		unordered_map<int, int> pos;
		for (int i = 0; i < n; ++i)
			pos[nums2[i]] = i + 1;

		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			int idx = pos[nums1[i]];

			int left = occur.query(idx);
			int right = n - idx - (occur.query(n) - occur.query(idx));
			ans += 1LL * left * right;

			occur.update(idx, 1);
		}

		return ans;
	}
};

