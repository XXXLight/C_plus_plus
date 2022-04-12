#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

class Solution {
private:
	int p[N];
public:
	int find(int x) {
		if (x != p[x])  p[x] = find(p[x]);
		return p[x];
	}
	void merge(int a, int b) {
		int x = find(a), y = find(b);
		if (x == y)     return;
		p[x] = y;
	}
	bool gcdSort(vector<int>& nums) {
		vector<int> nums1 = nums;
		for (int i = 1; i < N; i++) p[i] = i;
		// 分解质因数
		for (auto c : nums) {
			int k = c;
			for (int i = 2; i <= c / i; i++) {
				bool flag = false;
				while (c % i == 0)
					c /= i, flag = true;
				if (flag)
					merge(k, i);
			}
			// 合并质因子
			if (c > 1)
				merge(k, c);
		}
		sort(nums1.begin(), nums1.end());
		// 对比原数组
		for (int i = 0; i < nums1.size(); i++) {
			if (nums1[i] == nums[i])    continue;
			if (find(nums1[i]) != find(nums[i]))    return false;
		}
		return true;
	}
};
