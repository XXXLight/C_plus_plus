#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		if (row == 0) return false;
		int col = matrix[0].size();
		// ÆðÊ¼µã
		int r = 0, c = col - 1;
		while (r < row && c >= 0) {
			if (matrix[r][c] == target) return true;
			else if (matrix[r][c] > target) c--;
			else r++;
		}
		return false;
	}
};