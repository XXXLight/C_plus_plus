#include<bits/stdc++.h>
using namespace std;

// 不要一直想着别人的代码是怎么写的，要有自己的想法
// 代码还是要多写注释，要不然很久不看都不知道写的是什么
class Solution {
public:
	int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
		if (l >= r) {
			return 0;
		}
		int mid = (l + r) / 2;
		int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
		int i = l, j = mid + 1, pos = l;
		while (i <= mid && j <= r) {
			if (nums[i] <= nums[j]) {
				tmp[pos++] = nums[i++];
				inv_count += (j - (mid + 1));
			}
			else {
				tmp[pos++] = nums[j++];
			}
		}
		while (i <= mid) {
			tmp[pos++] = nums[i++];
			inv_count += (j - (mid + 1));
		}
		while (j <= r) {
			tmp[pos++] = nums[j++];
		}
		copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
		return inv_count;
	}

	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		vector<int> tmp(n);
		return mergeSort(nums, tmp, 0, n - 1);
	}
};



//	先想着调试出结果，而不是对比
//	控制变量法，先[2,4,8,9,1,3,5,7]
//	先模拟出合并过程
//	尽量写出bugfree的代码
class Solution {
public:
	int cnt = 0;
	void mergeSort(vector<int>&v, int l, int r) {
		if (l >= r) return;
		int m = (l + r) >> 1;
		int n = r - l + 1;
		vector<int>tmp(n);
		// 对两部分分别进行排序
		mergeSort(v, l, m);
		mergeSort(v, m + 1, r);
		int p1 = l, p2 = m + 1, k = 0;
		// 合并的过程
		while (p1 <= m && p2 <= r) {
			if (v[p1] <= v[p2]) tmp[k++] = v[p1++];
			// 此时v[p1]>v[p2]，由于此时左侧已经排好序了，最小的比右边大，则左边所有大于右边，所以逆序对个数是m-p1+1
			else { tmp[k++] = v[p2++]; cnt += m - p1 + 1; }
		}
		// 上面while推出条件是p1>m||p2>r，即只要有一个越界就推出，所以要把剩余的加进来
		while (p1 <= m) tmp[k++] = v[p1++];
		while (p2 <= r) tmp[k++] = v[p2++];
		copy(tmp.begin(), tmp.end(), v.begin() + l);
	}
	int reversePairs(vector<int>& nums) {
		mergeSort(nums, 0, nums.size() - 1);
		return cnt;
	}
};



// 树状数组
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
		for (int& num : nums) {
			num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
		}
		// 树状数组统计逆序对
		BIT bit(n);
		int ans = 0;
		for (int i = n - 1; i >= 0; --i) {
			ans += bit.query(nums[i] - 1);
			bit.update(nums[i]);
		}
		return ans;
	}
};





// 简洁版
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