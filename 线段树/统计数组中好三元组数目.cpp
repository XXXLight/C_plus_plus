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





// 转化为“计算右侧小于当前元素的个数”
class Solution {
public:
	class SolutionCountSmaller {
	private:
		vector<int> c;
		vector<int> a;

		void Init(int length) {
			c.resize(length, 0);
		}

		int LowBit(int x) {
			return x & (-x);
		}

		void Update(int pos) {
			while (pos < c.size()) {
				c[pos] += 1;
				pos += LowBit(pos);
			}
		}

		int Query(int pos) {
			int ret = 0;

			while (pos > 0) {
				ret += c[pos];
				pos -= LowBit(pos);
			}

			return ret;
		}

		void Discretization(vector<int>& nums) {
			a.assign(nums.begin(), nums.end());
			sort(a.begin(), a.end());
			a.erase(unique(a.begin(), a.end()), a.end());
		}

		int getId(int x) {
			return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
		}
	public:
		vector<int> countSmaller(vector<int>& nums) {
			vector<int> resultList;

			Discretization(nums);

			Init(nums.size());

			for (int i = (int)nums.size() - 1; i >= 0; --i) {
				int id = getId(nums[i]);
				resultList.push_back(Query(id - 1));
				Update(id);
			}

			reverse(resultList.begin(), resultList.end());

			return resultList;
		}
	};
	long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		unordered_map<int, int> mp;
		for (int i = 0; i < n; i++) {
			mp[nums1[i]] = i;
		}
		for (auto& x : nums2) {
			x = mp[x];
		}
		vector<int> v = SolutionCountSmaller().countSmaller(nums2);
		long long res = 0;
		for (int i = 0; i < n; i++) {
			res += 1LL * (nums2[i] - v[i])*(n - 1 - i - v[i]);
		}
		return res;
	}
};