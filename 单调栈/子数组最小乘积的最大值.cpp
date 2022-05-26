#include<bits/stdc++.h>
using namespace std;



class Solution {
private:
	using LL = long long;
	static constexpr int mod = 1000000007;

public:
	int maxSumMinProduct(vector<int>& nums) {
		int n = nums.size();
		// 数组 left 初始化为 0，数组 right 初始化为 n-1
		// 设置为元素不存在时的特殊值
		vector<int> left(n), right(n, n - 1);
		// 单调栈
		stack<int> s;
		for (int i = 0; i < n; ++i) {
			while (!s.empty() && nums[s.top()] >= nums[i]) {
				// 这里的 right 是非严格定义的，right[i] 是右侧最近的小于等于 nums[i] 的元素下标
				right[s.top()] = i - 1;
				s.pop();
			}
			if (!s.empty()) {
				// 这里的 left 是严格定义的，left[i] 是左侧最近的严格小于 nums[i] 的元素下标
				left[i] = s.top() + 1;
			}
			s.push(i);
		}

		// 前缀和
		vector<LL> pre(n + 1);
		for (int i = 1; i <= n; ++i) {
			pre[i] = pre[i - 1] + nums[i - 1];
		}

		LL best = 0;
		for (int i = 0; i < n; ++i) {
			best = max(best, (pre[right[i] + 1] - pre[left[i]]) * nums[i]);
		}
		return best % mod;
	}
};

