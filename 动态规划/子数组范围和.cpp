#include<bits/stdc++.h>
using namespace std;

// 自己动脑子想出来的才是最棒的方法
class Solution {
public:
	long long subArrayRanges(vector<int>& nums) {
		int len = nums.size();
		// dp1[i][j]维护[i,j]范围内的最大值
		// dp2[i][j]维护[i,j]范围内的最小值
		vector<vector<int>> dp1(len, vector<int>(len, 0));
		vector<vector<int>> dp2(len, vector<int>(len, 0));
		// dp数组初始化
		for (int i = 0; i < len; i++) dp1[i][i] = nums[i], dp2[i][i] = nums[i]; // 语句可以写成 , , , ;可以达到缩短代码的目的
		long long res = 0;
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				dp1[i][j] = max(dp1[i][j - 1], nums[j]), dp2[i][j] = min(dp2[i][j - 1], nums[j]);
				res += abs(dp1[i][j] - dp2[i][j]);
			}
		}
		return res;
	}
};