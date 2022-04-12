#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


// �鲢���򷨣��������ԣ���������ָ��֮��Ĺ�ϵ��������һ����
class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		// ��nums��ǰ׺��
		vector<long> v = { 0 };
		for (int i = 0; i < nums.size(); ++i) v.emplace_back(v[i] + nums[i]);
		// �ٰ�ǰ׺�ʹ���ȥ,��ǰ׺��������й鲢���򣬶����Ƕ�ԭ���������������
		return merge_sort(v, 0, v.size(), lower, upper);
	}
	int merge_sort(vector<long>& nums, int lo, int hi, int lower, int upper) {
		if (hi - lo <= 1) return 0;// �����1��Ԫ�ز��ܽ��й鲢
		int mid = lo + (hi - lo >> 1);
		// preSum[right]-preSum[left],left,rightָ�붼����lo~mid�м������mid~hi֮�������
		int count = merge_sort(nums, lo, mid, lower, upper) + merge_sort(nums, mid, hi, lower, upper);
		int right1 = mid, right2 = mid;
		for (int left = lo; left < mid; ++left) {
			// forѭ����ʾleftָ����lo~mid֮��
			// whileѭ����ʾrightָ����mid~hi֮��
			while (right1 != hi && nums[right1] - nums[left] < lower) ++right1;
			while (right2 != hi && nums[right2] - nums[left] <= upper) ++right2;
			count += right2 - right1;// ָ��ֱ������������������
		}
		// [left,mid)&[mid,right)�����Խ�ȥ�����ڲ����ӿ�
		inplace_merge(nums.begin() + lo, nums.begin() + mid, nums.begin() + hi);
		return count;
	}
};



// û��ʹ����״�����������������ԭʼ����������û�ж����ݽ���ӳ��
class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		long long sum = 0;
		vector<long long> preSum = { 0 };
		// ����ǰ׺��,ǰ׺�͵�һ��Ԫ����0,sum[i~j]=preSum[j+1]-preSum[i],ע���preSum��û�н������������
		for (int v : nums) {
			sum += v;
			preSum.push_back(sum);
		}
		unordered_map<long long, long long> mp;
		int res = 0;
		// ����ǰ׺�����飬��ǰ׺��������м���ͳ�Ʋ������ѯ�����Ƚ��������ѯ���ٽ��м���ͳ��
		for (int i = 0; i < preSum.size(); i++) {
			long long left = preSum[i] - upper, right = preSum[i] - lower;
			int cnt = 0;
			for (long long k = left; k <= right; k++) {
				cnt += mp[k];// ����Ͳ�ѯ
			}
			res += cnt;
			mp[preSum[i]]++;// Ƶ������,���ǵ����޸�
		}
		return res;
	}
};


// û��ʹ����״�����������������ԭʼ�������������ݽ���ӳ��
class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		long long sum = 0;
		vector<long long> preSum = { 0 };
		// ����ǰ׺��,ǰ׺�͵�һ��Ԫ����0,sum[i~j]=preSum[j+1]-preSum[i],ע���preSum��û�н������������
		for (int v : nums) {
			sum += v;
			preSum.push_back(sum);
		}

		// �������п��ܵ�����,����ע��set��Ҫ���������ܣ�ȥ��+����
		set<long long> allNumbers;
		for (long long x : preSum) {
			allNumbers.insert(x);
			allNumbers.insert(x - lower);
			allNumbers.insert(x - upper);
		}

		// ���ù�ϣ�������ɢ��
		unordered_map<long long, int> values;
		unordered_map<int, int> mp;
		int idx = 0;// idx��0��ʼ����ɢ������0��1��2��3��3~  n
		for (long long x : allNumbers) {
			values[x] = idx;
			idx++;
		}
		int res = 0;
		// ����ǰ׺�����飬��ǰ׺��������м���ͳ�Ʋ������ѯ�����Ƚ��������ѯ���ٽ��м���ͳ��
		// ԭʼ���������A[i],i=[0,n-1]����Ƶ������
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


// ��״����
class BIT {
private:
	vector<int> tree;// ��״����Ĵ�С��ԭʼ�����1
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
		// ����ǰ׺��,ǰ׺�͵�һ��Ԫ����0,sum[i~j]=preSum[j+1]-preSum[i],ע���preSum��û�н������������
		for (int v : nums) {
			sum += v;
			preSum.push_back(sum);
		}

		// �������п��ܵ�����,����ע��set��Ҫ���������ܣ�ȥ��+����
		set<long long> allNumbers;
		for (long long x : preSum) {
			allNumbers.insert(x);
			allNumbers.insert(x - lower);
			allNumbers.insert(x - upper);
		}

		// ���ù�ϣ�������ɢ��
		unordered_map<long long, int> values;
		int idx = 0;// idx��0��ʼ����ɢ������0��1��2��3��3~  n
		for (long long x : allNumbers) {
			values[x] = idx;
			idx++;
		}

		int ret = 0;
		BIT bit(values.size());
		// ����ǰ׺�����飬��ǰ׺��������м���ͳ�Ʋ������ѯ�����Ƚ��������ѯ���ٽ��м���ͳ��
		// ԭʼ���������A[i],i=[0,n-1]����Ƶ������
		for (int i = 0; i < preSum.size(); i++) {
			int left = values[preSum[i] - upper], right = values[preSum[i] - lower];
			ret += bit.query(right + 1) - bit.query(left);// A[left]+A[left+1]+...+A[right]
			bit.update(values[preSum[i]] + 1, 1);// A[values[preSum[i]]]++������Ƶ��ͳ��
		}
		return ret;
	}
};



// �߶���
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
		// ���ù�ϣ�������ɢ��
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

