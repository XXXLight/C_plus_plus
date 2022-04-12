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
		// ��ɢ��
		sort(tmp.begin(), tmp.end());
		// ʹ�����õķ�ʽ��ԭ�������ݽ����޸�
		for (int& num : nums) {
			num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin();
		}
		// ��״����ͳ�������,����ԭʼ���飨�����Ͳ��ö����������A[i],i=[0,n-1],һ��n�ע��ԭʼ������Ƶ�����飬������nums����
		BIT bit(n);
		int ans = 0;
		// ����������߽���Ƶ��ͳ�ƣ�ͬʱ��ǰ׺��
		for (int i = n - 1; i >= 0; --i) {
			ans += bit.query(nums[i]);// �����ѯ,A[0]+A[1]+A[2]+....+A[nums[i]-1],�ر�nums[i]=0�Ƿ���0
			bit.update(nums[i] + 1); // ������£�A[nums[i]]++,����Ƶ��ͳ��
		}
		return ans;
	}
};




// û��ʹ����״����ķ���
class Solution {
public:
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		vector<int> tmp = nums;
		unordered_map<int, int> mp;
		// ��ɢ��
		sort(tmp.begin(), tmp.end());
		// ʹ�����õķ�ʽ��ԭ�������ݽ����޸�
		for (int& num : nums) {
			num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin();
		}
		// ʹ������������ģ��
		int res = 0;
		for (int i = n - 1; i >= 0; i--) {
			int cnt = 0;
			if (nums[i] >= 1) {
				for (int k = 0; k <= nums[i] - 1; k++) {
					cnt += mp[k];// A[0]+A[1]+A[2]+....+A[nums[i]-1]
				}
			}
			res += cnt;
			mp[nums[i]]++; // ������£�A[nums[i]]++,����Ƶ��ͳ��
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
		// ��ɢ��
		sort(tmp.begin(), tmp.end());
		// ʹ�����õķ�ʽ��ԭ�������ݽ����޸�
		for (int& num : nums) {
			num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin();
		}
		// ��״����ͳ�������,����ԭʼ������A[i],i=[0,n-1],һ��n�ע��ԭʼ������Ƶ�����飬������nums����
		BIT bit(n);
		int ans = 0;
		// ����������߽���Ƶ��ͳ�ƣ�ͬʱ��ǰ׺��,ԭʼ����������Ͳ��ö���
		for (int i = n - 1; i >= 0; --i) {
			ans += bit.query(nums[i]);// �����ѯ,A[0]+A[1]+A[2]+....+A[nums[i]-1],�ر�nums[i]=0�Ƿ���0
			cout << ans << " ";
			bit.update(nums[i] + 1); // ������£�A[nums[i]]++,����Ƶ��ͳ��
		}
		cout << endl;
		// ʹ������������ģ��
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
			mp[nums[i]]++; // ������£�A[nums[i]]++,����Ƶ��ͳ��
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