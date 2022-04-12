#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


class BIT {
private:
	vector<int> tree;
	int n;

public:
	BIT(int _n) : n(_n), tree(_n + 1) {}

	static int lowbit(int x) {
		return x & (-x);
	}

	int query(int x) {
		int ret = 0;
		while (x) {
			ret += tree[x];
			x -= lowbit(x);
		}
		return ret;
	}

	void update(int x) {
		while (x <= n) {
			++tree[x];
			x += lowbit(x);
		}
	}
};
class Solution {
public:
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		vector<int> tmp = nums;
		// 离散化
		sort(tmp.begin(), tmp.end());
		// 使用引用的方式对原来的数据进行修改
		for (int& num : nums) {
			num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin();
		}
		// 树状数组统计逆序对,假设原始数组（根本就不用定义出来）是A[i],i=[0,n-1],一共n项，注意原始数组是频数数组，而不是nums数组
		BIT bit(n);
		int ans = 0;
		// 逆序遍历，边进行频数统计，同时求前缀和
		for (int i = n - 1; i >= 0; --i) {
			ans += bit.query(nums[i]);// 区间查询,A[0]+A[1]+A[2]+....+A[nums[i]-1],特别nums[i]=0是返回0
			bit.update(nums[i] + 1); // 单点更新，A[nums[i]]++,进行频数统计
		}
		return ans;
	}
};




// 没有使用树状数组的方法
class Solution {
public:
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		vector<int> tmp = nums;
		unordered_map<int, int> mp;
		// 离散化
		sort(tmp.begin(), tmp.end());
		// 使用引用的方式对原来的数据进行修改
		for (int& num : nums) {
			num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin();
		}
		// 使用数组来进行模拟
		int res = 0;
		for (int i = n - 1; i >= 0; i--) {
			int cnt = 0;
			if (nums[i] >= 1) {
				for (int k = 0; k <= nums[i] - 1; k++) {
					cnt += mp[k];// A[0]+A[1]+A[2]+....+A[nums[i]-1]
				}
			}
			res += cnt;
			mp[nums[i]]++; // 单点更新，A[nums[i]]++,进行频数统计
		}
		return res;
	}
};


class BIT {
private:
	vector<int> tree;
	int n;

public:
	BIT(int _n) : n(_n), tree(_n + 1) {}

	static int lowbit(int x) {
		return x & (-x);
	}

	int query(int x) {
		int ret = 0;
		while (x) {
			ret += tree[x];
			x -= lowbit(x);
		}
		return ret;
	}

	void update(int x) {
		while (x <= n) {
			++tree[x];
			x += lowbit(x);
		}
	}
};
class Solution {
public:
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		vector<int> tmp = nums;
		unordered_map<int, int> mp;
		// 离散化
		sort(tmp.begin(), tmp.end());
		// 使用引用的方式对原来的数据进行修改
		for (int& num : nums) {
			num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin();
		}
		// 树状数组统计逆序对,假设原始数组是A[i],i=[0,n-1],一共n项，注意原始数组是频数数组，而不是nums数组
		BIT bit(n);
		int ans = 0;
		// 逆序遍历，边进行频数统计，同时求前缀和,原始的数组根本就不用定义
		for (int i = n - 1; i >= 0; --i) {
			ans += bit.query(nums[i]);// 区间查询,A[0]+A[1]+A[2]+....+A[nums[i]-1],特别nums[i]=0是返回0
			cout << ans << " ";
			bit.update(nums[i] + 1); // 单点更新，A[nums[i]]++,进行频数统计
		}
		cout << endl;
		// 使用数组来进行模拟
		int res = 0;
		for (int i = n - 1; i >= 0; i--) {
			int cnt = 0;
			if (nums[i] >= 1) {
				for (int k = 0; k <= nums[i] - 1; k++) {
					cnt += mp[k];// A[0]+A[1]+A[2]+....+A[nums[i]-1]
				}
			}
			res += cnt;
			cout << res << " ";
			mp[nums[i]]++; // 单点更新，A[nums[i]]++,进行频数统计
		}
		cout << endl;
		return ans;
	}
};



class Solution {
public:
	int dfs(vector<int> & nums, int l, int r) {
		if (r - l <= 1) return 0;
		int mid = (l + r) >> 1;
		int res = dfs(nums, l, mid) + dfs(nums, mid, r);
		sort(nums.begin() + l, nums.begin() + mid);
		for (int i = mid; i < r; ++i) {
			res += nums.begin() + mid - upper_bound(nums.begin() + l, nums.begin() + mid, nums[i]);
		}
		return res;
	}
	int reversePairs(vector<int>& nums) {
		return dfs(nums, 0, nums.size());
	}
};