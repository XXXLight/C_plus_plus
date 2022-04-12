#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		int preSum[n + 1][m + 1];
		memset(preSum, 0, sizeof(preSum));
		//前缀和数组
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				preSum[i][j] = matrix[i - 1][j - 1] + preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1];
			}
		}
		vector<int> res(4, 0);
		int max = matrix[0][0];
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				//构建一维最大数组   从i行到j行每列和数组
				int nums[m];
				for (int k = 0; k < m; k++) {
					nums[k] = preSum[j + 1][k + 1] - preSum[i][k + 1] - preSum[j + 1][k] + preSum[i][k];
				}
				//求最大子数组和
				int left = 0;
				int sum = nums[0];
				for (int right = 1; right < m; right++) {
					if (nums[right] > sum + nums[right]) {
						sum = nums[right];
						left = right;
					}
					else {
						sum += nums[right];
					}
					if (sum > max) {
						res[0] = i;
						res[1] = left;
						res[2] = j;
						res[3] = right;
						max = sum;
					}
				}
			}
		}
		return res;
	}
};

