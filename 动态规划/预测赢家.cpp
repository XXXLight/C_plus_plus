#include<bits/stdc++.h>
using namespace std;

// 动态规划就是理解+画表格，表格画出来题目自然就好解了
// 净胜分 a=x-y 总分 b=sum=x+y ，所以x=(a+b)/2
class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int length = nums.size();
		auto dp = vector<vector<int>>(length, vector<int>(length)); // auto dp
		for (int i = 0; i < length; i++) {
			dp[i][i] = nums[i];
		}
		for (int i = length - 2; i >= 0; i--) {
			for (int j = i + 1; j < length; j++) {
				// 相对分数，净胜分
				dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
			}
		}
		return dp[0][length - 1] >= 0;
	}
};


class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		return total(nums, 0, nums.size() - 1, 1) >= 0;
	}

	int total(vector<int>& nums, int start, int end, int turn) {
		if (start == end) {
			return nums[start] * turn;
		}
		int scoreStart = nums[start] * turn + total(nums, start + 1, end, -turn);
		int scoreEnd = nums[end] * turn + total(nums, start, end - 1, -turn);
		return max(scoreStart * turn, scoreEnd * turn) * turn;
	}
};



