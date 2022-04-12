#include<bits/stdc++.h>
using namespace std;

// ÓÐµãÅ£Åú
class Solution {
public:
	int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
		int dp[501][501];
		for (int i = 0; i <= nums1.size(); i++) {
			for (int j = 0; j <= nums2.size(); j++) {
				dp[i][j] = -1000 * 1000 * 500;
			}
		}
		for (int i = 1; i <= nums1.size(); i++) {
			for (int j = 1; j <= nums2.size(); j++) {
				int a = nums1[i - 1];
				int b = nums2[j - 1];
				dp[i][j] = max(dp[i][j], a*b);
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a * b);
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			}
		}
		return dp[nums1.size()][nums2.size()];
	}
};