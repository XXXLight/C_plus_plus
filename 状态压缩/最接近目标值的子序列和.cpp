#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	// 根据子集改写    0<=mask<7  0<=j<3
	// 0 0 0    1 0 0
	// 0 0 1    1 0 1
	// 0 1 0    1 1 0
	// 0 1 1    1 1 1
	vector<int>  make(vector<int> v) {
		vector<int> sum(1 << v.size());
		int len = 1 << v.size();//int len = 2 << (nums.size() - 1);
		vector<int> r;
		// mask 表示从0~7（即000~111）,遍历mask，对于每个mask,if ((1 << j)&mask)表示第j位是1，即选择nums[j]
		for (int mask = 0; mask < len; mask++) {
			for (int j = 0; j < v.size(); j++) {
				if ((1 << j)&mask)   // if ((i >> j) & 1)
					sum[mask] += (v[j]);
			}
		}
		return sum;
	}
	int minAbsDifference(vector<int>& nums, int goal) {
		int n = nums.size();
		vector<int> left = make({ nums.begin(), nums.begin() + n / 2 });
		vector<int> right = make({ nums.begin() + n / 2, nums.end() });
		sort(left.begin(), left.end()); // 升序排列
		sort(right.rbegin(), right.rend()); // 降序排列
		int ans = INT_MAX, i = 0, j = 0;
		while (i < left.size() && j < right.size()) {
			int t = left[i] + right[j];
			ans = min(ans, abs(goal - t));
			if (t > goal) j++;
			else if (t < goal) i++;
			else return 0;
		}
		return ans;
	}
};




class Solution {
public:
	int minAbsDifference(vector<int>& nums, int goal) {
		int n = nums.size();
		int half = n / 2;
		int ls = half, rs = n - half;

		vector<int> lsum(1 << ls, 0);
		for (int i = 1; i < (1 << ls); i++) {
			for (int j = 0; j < ls; j++) {
				if ((i & (1 << j)) == 0) continue;
				lsum[i] = lsum[i - (1 << j)] + nums[j];
				break;
			}
		}
		vector<int> rsum(1 << rs, 0);
		for (int i = 1; i < (1 << rs); i++) {
			for (int j = 0; j < rs; j++) {
				if ((i & (1 << j)) == 0) continue;
				rsum[i] = rsum[i - (1 << j)] + nums[ls + j];
				break;
			}
		}
		sort(lsum.begin(), lsum.end());
		sort(rsum.begin(), rsum.end());

		int ret = INT_MAX;
		for (int x : lsum) {
			ret = min(ret, abs(goal - x));
		}
		for (int x : rsum) {
			ret = min(ret, abs(goal - x));
		}

		int i = 0, j = rsum.size() - 1;
		while (i < lsum.size() && j >= 0) {
			int s = lsum[i] + rsum[j];
			ret = min(ret, abs(goal - s));
			if (s > goal) {
				j--;
			}
			else {
				i++;
			}
		}
		return ret;
	}
};


