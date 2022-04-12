#include<bits/stdc++.h>
using namespace std;

// �侲�������ֶ��Ƶ�����ѧ�Ͽ��д���100%����
// ������¥������
// ��¥�ݡ�����ܺ�IV������������

//  [1,2,3]   4
//  dp[0]=1    dp[1]=dp[1-1]=dp[0]=1
//  dp[2]=dp[2-1]+dp[2-2]=dp[0]+dp[1]=2
//  dp[3]=dp[3-1]+dp[3-2]+dp[3-3]=7
using ll = long long;
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<ll> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= target; i++) {
			for (auto e : nums) {
				if (i - e >= 0) {
					dp[i] += dp[i - e]; // �����ٴ��������Ӧ����ֵ
					if (dp[i] > INT_MAX)   dp[i] %= INT_MAX; //�������
				}
			}
		}
		return dp[target];
	}
};


class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (nums.size() == 0 && target > 0) return 0;
		vector<int> memo(target + 1, -1);
		return  tryCombinationSum4(nums, target, memo);
	}
	int tryCombinationSum4(vector<int>& nums, int target, vector<int>& memo) {
		if (target < 0)return 0;
		if (target == 0) return 1;
		if (memo[target] != -1)return  memo[target];
		int res = 0;
		// ������ǵ��ƹ�ʽ
		for (int i = 0; i < nums.size(); i++) {
			res += tryCombinationSum4(nums, target - nums[i], memo);
		}
		return memo[target] = res;
	}
};