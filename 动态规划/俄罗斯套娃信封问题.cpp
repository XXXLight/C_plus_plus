#include<bits/stdc++.h>
using namespace std;

// 时间复杂度：o(n^2),两层for循环
// 空间复杂度：o(n)，dp数组
class Solution {
public:
	// 最长上升子序列接口
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		vector<int> dp(len, 1);
		for (int j = 1; j < len; j++) {
			for (int i = 0; i < j; i++) {
				// j是常量了，i是变量，dp[j]也是常量
				if (nums[i] < nums[j]) {
					dp[j] = max(dp[j], dp[i] + 1); //求数组的最大值
				}
			}
		}
		return *max_element(dp.begin(), dp.end()); //注意返回的是dp数组中的最大值
	}
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		// 这种sort方法值得学习，当第一维度相同时，第二维度降序排列
		// 这里的[0]、[1]等代表维度
		sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
			return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);	// 就是按照一维升序，二维降序的规则
		});
		vector<int> v;
		// 取出第二个维度
		for (auto e : envelopes) {
			v.push_back(e[1]);
		}
		int res = lengthOfLIS(v);
		return res;
	}
};