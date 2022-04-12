#include<bits/stdc++.h>
using namespace std;

// ��Ҫһֱ���ű��˵Ĵ�������ôд�ģ�Ҫ���Լ����뷨
// ���뻹��Ҫ��дע�ͣ�Ҫ��Ȼ�ܾò�������֪��д����ʲô
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



//	�����ŵ��Գ�����������ǶԱ�
//	���Ʊ���������[2,4,8,9,1,3,5,7]
//	��ģ����ϲ�����
//	����д��bugfree�Ĵ���
class Solution {
public:
	int cnt = 0;
	void mergeSort(vector<int>&v, int l, int r) {
		if (l >= r) return;
		int m = (l + r) >> 1;
		int n = r - l + 1;
		vector<int>tmp(n);
		// �������ֱַ��������
		mergeSort(v, l, m);
		mergeSort(v, m + 1, r);
		int p1 = l, p2 = m + 1, k = 0;
		// �ϲ��Ĺ���
		while (p1 <= m && p2 <= r) {
			if (v[p1] <= v[p2]) tmp[k++] = v[p1++];
			// ��ʱv[p1]>v[p2]�����ڴ�ʱ����Ѿ��ź����ˣ���С�ı��ұߴ���������д����ұߣ���������Ը�����m-p1+1
			else { tmp[k++] = v[p2++]; cnt += m - p1 + 1; }
		}
		// ����while�Ƴ�������p1>m||p2>r����ֻҪ��һ��Խ����Ƴ�������Ҫ��ʣ��ļӽ���
		while (p1 <= m) tmp[k++] = v[p1++];
		while (p2 <= r) tmp[k++] = v[p2++];
		copy(tmp.begin(), tmp.end(), v.begin() + l);
	}
	int reversePairs(vector<int>& nums) {
		mergeSort(nums, 0, nums.size() - 1);
		return cnt;
	}
};



// ��״����
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
		// ��ɢ��
		sort(tmp.begin(), tmp.end());
		for (int& num : nums) {
			num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
		}
		// ��״����ͳ�������
		BIT bit(n);
		int ans = 0;
		for (int i = n - 1; i >= 0; --i) {
			ans += bit.query(nums[i] - 1);
			bit.update(nums[i]);
		}
		return ans;
	}
};





// ����
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