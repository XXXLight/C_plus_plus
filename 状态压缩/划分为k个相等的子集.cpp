#include<bits/stdc++.h>
using namespace std;

// DFS
class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		sort(nums.rbegin(), nums.rend());
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % k != 0) return false;
		int avg = sum / k;

		vi = vector<bool>(nums.size(), false);
		return dfs(nums, avg, 0, 0, k);
	}

	bool dfs(vector<int>& nums, int target, int sum, int idx, int k) {
		if (k == 0) return true;

		for (int i = idx; i < nums.size(); i++) {
			if (vi[i]) continue;

			int temp = sum + nums[i];
			if (temp > target) continue;

			int nextSum = (temp == target) ? 0 : temp;
			int nextIdx = (temp == target) ? 0 : idx + 1;
			int nextK = (temp == target) ? k - 1 : k;

			if (i > 0 && nums[i - 1] == nums[i] && !vi[i - 1]) continue;

			vi[i] = true;
			if (dfs(nums, target, nextSum, nextIdx, nextK)) return true;
			vi[i] = false;
		}
		return false;
	}

private:
	vector<bool> vi;
};



// 状态压缩，该版本不易于理解
class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		const int n = nums.size();
		int sum = 0;
		for (int x : nums) sum += x;
		if (sum % k) return false;
		sum /= k;
		vector<bool> f(1 << n);
		f[0] = true;
		for (int i = 1; i < 1 << n; i++) {
			int s = 0;
			for (int j = 0; j < n; j++)
				if (i >> j & 1) s += nums[j];
			if (s % sum) continue;
			if (s == sum) f[i] = true;
			else {
				for (int k = i; k; k = k - 1 & i) {
					if (!f[k]) continue;
					if (f[k] && f[i ^ k]) {
						f[i] = true;
						break;
					}
				}
			}
			if (f[i] && f[((1 << n) - 1) ^ i]) return true;
		}
		return false;
	}
};



// 状态压缩，这个版本比较好理解一点
class Solution {
	int dp[(1 << 16) + 2];
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int n = nums.size();
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

//输入：
//[3, 3, 2, 1]
//3
//输出：
//0001 0000 0
//0010 0000 0
//0100 0000 2
//1000 0000 1
//0011 0001 0
//0101 0001 2
//1001 0001 1
//0011 0010 0
//0110 0010 2
//1010 0010 1
//0111 0011 2
//1011 0011 1
//1100 0100 0
//1101 0101 0
//1110 0110 0
//1111 0111 0
//1100 1000 0
//1101 1001 0
//1110 1010 0
//1111 1011 0
//1101 1100 0
//1110 1100 0
//1111 1101 0
//1111 1110 0
//分割线
//0000 0
//0001 0
//0010 0
//0011 0
//0100 2
//0101 2
//0110 2
//0111 2
//1000 1
//1001 1
//1010 1
//1011 1
//1100 0
//1101 0
//1110 0
//1111 0
//0000 - 1
//0001 - 1