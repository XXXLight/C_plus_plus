#include<bits/stdc++.h>
using namespace std;

// 开了四个指针，最好用闭区间进行统一
// 时间复杂度：o(mn)
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int row = matrix.size();
		if (row == 0) return {};
		int col = matrix[0].size();
		int left = 0, right = col - 1, upper = 0, down = row - 1;
		int cnt = 0;
		while (1) {
			for (int i = left; i <= right; i++) { res.push_back(matrix[upper][i]); cnt++; }
			{++upper; if (cnt == row * col) break; }
			for (int i = upper; i <= down; i++) { res.push_back(matrix[i][right]); cnt++; }
			{--right; if (cnt == row * col) break; }
			for (int i = right; i >= left; i--) { res.push_back(matrix[down][i]); cnt++; }
			{--down; if (cnt == row * col) break; }
			for (int i = down; i >= upper; i--) { res.push_back(matrix[i][left]); cnt++; }
			{++left; if (cnt == row * col) break; }
		}
		return res;
	}
};