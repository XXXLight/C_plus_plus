#include<bits/stdc++.h>
using namespace std;

// 开了四个指针，用闭区间统一，要不然很容易乱
// 时间复杂度：o(n^2)
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		int row = matrix.size();
		if (row == 0) return {};
		int col = matrix[0].size();
		int left = 0, right = col - 1, upper = 0, down = row - 1;
		int cnt = 1;
		while (cnt <= n * n) {
			for (int i = left; i <= right; i++) { matrix[upper][i] = cnt++; }
			++upper;
			for (int i = upper; i <= down; i++) { matrix[i][right] = cnt++; }
			--right;
			for (int i = right; i >= left; i--) { matrix[down][i] = cnt++; }
			--down;
			for (int i = down; i >= upper; i--) { matrix[i][left] = cnt++; }
			++left;
		}

		return matrix;
	}
};