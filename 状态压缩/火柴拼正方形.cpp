#include<bits/stdc++.h>
using namespace std;


// 跟 “划分为k个相等的子集”一模一样
class Solution {
	int dp[(1 << 16) + 2];
public:
	bool makesquare(vector<int>& nums) {
		int n = nums.size();
		int k = 4;
		fill(dp, dp + (1 << 16) + 2, -1); // dp数组初始化为-1,int dp[(1 << 16) + 2]={-1};只会将第一个元素设置为-1
		int sum = accumulate(nums.begin(), nums.end(), 0); // 使用accumulate方式对数组求和
		if (sum % k != 0) return false; // 不能整除，直接返回false
		int target = sum / k; // 每组的和
		dp[0] = 0;
		// dp[mask]表示mask状态时能不能被target整除，如[3,3,2,1] 3时，dp[1100]=0表示选择2 1可以整除3
		for (int mask = 0; mask < (1 << n); mask++) {
			if (dp[mask] == -1) continue;
			for (int i = 0; i < n; i++) {
				// 如果mask的第i位是0（第i位没有选择）且选择第i位的话不超过target
				if (!(mask & (1 << i)) && dp[mask] + nums[i] <= target) {
					// 将mask的第i位置1，即选择第i位,注意掩码的位和数组的位是反过来的
					dp[mask | (1 << i)] = (dp[mask] + nums[i]) % target; //能否刚好为0
					//cout<<bitset<4>(mask | (1 << i))<<" "<<bitset<4>(mask)<<" "<<dp[mask | (1 << i)]<<endl;
				}

			}
		}
		// cout<<"分割线"<<endl;
		// for(int i=0;i<(1<<4)+2;i++){
		//     cout<<bitset<4>(i)<<" "<<dp[i]<<endl;
		// }
		return dp[(1 << n) - 1] == 0; //  所有书取到
	}
};