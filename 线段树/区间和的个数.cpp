#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


// 归并排序法，类比逆序对，都是两个指针之间的关系，本质是一样的
class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		// 对nums求前缀和
		vector<long> v = { 0 };
		for (int i = 0; i < nums.size(); ++i) v.emplace_back(v[i] + nums[i]);
		// 再把前缀和传进去,对前缀和数组进行归并排序，而不是对原来的数组进行排序
		return merge_sort(v, 0, v.size(), lower, upper);
	}
	int merge_sort(vector<long>& nums, int lo, int hi, int lower, int upper) {
		if (hi - lo <= 1) return 0;// 理解是1个元素不能进行归并
		int mid = lo + (hi - lo >> 1);
		// preSum[right]-preSum[left],left,right指针都落在lo~mid中间或都落在mid~hi之间的数量
		int count = merge_sort(nums, lo, mid, lower, upper) + merge_sort(nums, mid, hi, lower, upper);
		int right1 = mid, right2 = mid;
		for (int left = lo; left < mid; ++left) {
			// for循环表示left指针在lo~mid之间
			// while循环表示right指针在mid~hi之间
			while (right1 != hi && nums[right1] - nums[left] < lower) ++right1;
			while (right2 != hi && nums[right2] - nums[left] <= upper) ++right2;
			count += right2 - right1;// 指针分别落在两个区间的数量
		}
		// [left,mid)&[mid,right)，可以进去函数内部看接口
		inplace_merge(nums.begin() + lo, nums.begin() + mid, nums.begin() + hi);
		return count;
	}
};



// 没有使用树状数组的做法，就是最原始的做法，且没有对数据进行映射
class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		long long sum = 0;
		vector<long long> preSum = { 0 };
		// 计算前缀和,前缀和第一个元素是0,sum[i~j]=preSum[j+1]-preSum[i],注意对preSum是没有进行排序操作的
		for (int v : nums) {
			sum += v;
			preSum.push_back(sum);
		}
		unordered_map<long long, long long> mp;
		int res = 0;
		// 遍历前缀和数组，对前缀和数组进行计数统计并区间查询，且先进行区间查询，再进行计数统计
		for (int i = 0; i < preSum.size(); i++) {
			long long left = preSum[i] - upper, right = preSum[i] - lower;
			int cnt = 0;
			for (long long k = left; k <= right; k++) {
				cnt += mp[k];// 区间和查询
			}
			res += cnt;
			mp[preSum[i]]++;// 频数数组,就是单点修改
		}
		return res;
	}
};


// 没有使用树状数组的做法，就是最原始的做法，对数据进行映射
class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		long long sum = 0;
		vector<long long> preSum = { 0 };
		// 计算前缀和,前缀和第一个元素是0,sum[i~j]=preSum[j+1]-preSum[i],注意对preSum是没有进行排序操作的
		for (int v : nums) {
			sum += v;
			preSum.push_back(sum);
		}

		// 计算所有可能的数字,这里注意set主要有两个功能，去重+排序
		set<long long> allNumbers;
		for (long long x : preSum) {
			allNumbers.insert(x);
			allNumbers.insert(x - lower);
			allNumbers.insert(x - upper);
		}

		// 利用哈希表进行离散化
		unordered_map<long long, int> values;
		unordered_map<int, int> mp;
		int idx = 0;// idx从0开始，离散化后是0，1，2，3，3~  n
		for (long long x : allNumbers) {
			values[x] = idx;
			idx++;
		}
		int res = 0;
		// 遍历前缀和数组，对前缀和数组进行计数统计并区间查询，且先进行区间查询，再进行计数统计
		// 原始数组假设是A[i],i=[0,n-1]，是频数数组
		for (int i = 0; i < preSum.size(); i++) {
			int left = values[preSum[i] - upper], right = values[preSum[i] - lower];
			int cnt = 0;
			for (int k = left; k <= right; k++) {
				cnt += mp[k];
			}
			res += cnt;
			mp[values[preSum[i]]]++;
		}
		return res;
	}
};


// 树状数组
class BIT {
private:
	vector<int> tree;// 树状数组的大小比原始数组大1
	int n;

public:
	BIT(int _n) : n(_n), tree(_n + 1) {}

	static constexpr int lowbit(int x) {
		return x & (-x);
	}

	void update(int x, int d) {
		while (x <= n) {
			tree[x] += d;
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
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		long long sum = 0;
		vector<long long> preSum = { 0 };
		// 计算前缀和,前缀和第一个元素是0,sum[i~j]=preSum[j+1]-preSum[i],注意对preSum是没有进行排序操作的
		for (int v : nums) {
			sum += v;
			preSum.push_back(sum);
		}

		// 计算所有可能的数字,这里注意set主要有两个功能，去重+排序
		set<long long> allNumbers;
		for (long long x : preSum) {
			allNumbers.insert(x);
			allNumbers.insert(x - lower);
			allNumbers.insert(x - upper);
		}

		// 利用哈希表进行离散化
		unordered_map<long long, int> values;
		int idx = 0;// idx从0开始，离散化后是0，1，2，3，3~  n
		for (long long x : allNumbers) {
			values[x] = idx;
			idx++;
		}

		int ret = 0;
		BIT bit(values.size());
		// 遍历前缀和数组，对前缀和数组进行计数统计并区间查询，且先进行区间查询，再进行计数统计
		// 原始数组假设是A[i],i=[0,n-1]，是频数数组
		for (int i = 0; i < preSum.size(); i++) {
			int left = values[preSum[i] - upper], right = values[preSum[i] - lower];
			ret += bit.query(right + 1) - bit.query(left);// A[left]+A[left+1]+...+A[right]
			bit.update(values[preSum[i]] + 1, 1);// A[values[preSum[i]]]++，进行频数统计
		}
		return ret;
	}
};



// 线段树
struct SegNode {
	int lo, hi, add;
	SegNode* lchild, *rchild;
	SegNode(int left, int right) : lo(left), hi(right), add(0), lchild(nullptr), rchild(nullptr) {}
};

class Solution {
public:
	SegNode* build(int left, int right) {
		SegNode* node = new SegNode(left, right);
		if (left == right) {
			return node;
		}
		int mid = (left + right) / 2;
		node->lchild = build(left, mid);
		node->rchild = build(mid + 1, right);
		return node;
	}

	void insert(SegNode* root, int val) {
		root->add++;
		if (root->lo == root->hi) {
			return;
		}
		int mid = (root->lo + root->hi) / 2;
		if (val <= mid) {
			insert(root->lchild, val);
		}
		else {
			insert(root->rchild, val);
		}
	}

	int count(SegNode* root, int left, int right) const {
		if (left > root->hi || right < root->lo) {
			return 0;
		}
		if (left <= root->lo && root->hi <= right) {
			return root->add;
		}
		return count(root->lchild, left, right) + count(root->rchild, left, right);
	}

	int countRangeSum(vector<int>& nums, int lower, int upper) {
		long long sum = 0;
		vector<long long> preSum = { 0 };
		for (int v : nums) {
			sum += v;
			preSum.push_back(sum);
		}

		set<long long> allNumbers;
		for (long long x : preSum) {
			allNumbers.insert(x);
			allNumbers.insert(x - lower);
			allNumbers.insert(x - upper);
		}
		// 利用哈希表进行离散化
		unordered_map<long long, int> values;
		int idx = 0;
		for (long long x : allNumbers) {
			values[x] = idx;
			idx++;
		}

		SegNode* root = build(0, values.size() - 1);
		int ret = 0;
		for (long long x : preSum) {
			int left = values[x - upper], right = values[x - lower];
			ret += count(root, left, right);
			insert(root, values[x]);
		}
		return ret;
	}
};

