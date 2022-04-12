#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int memo[200][200] = { 0 }; // 备忘录初始为 0
	int DFS(vector<vector<int>>& matrix, int i, int j) {
		if (memo[i][j] != 0) return memo[i][j];   // 算过了直接return 
		int row = matrix.size(), col = matrix[0].size();
		int dirX[4] = { 0,0,1,-1 }, dirY[4] = { 1,-1,0,0 };
		int res = 1;
		for (int k = 0; k < 4; k++) {
			int newX = i + dirX[k], newY = j + dirY[k];
			if (newX >= 0 && newX < row&&newY >= 0 && newY<col&&matrix[newX][newY]>matrix[i][j])
				res = max(res, DFS(matrix, newX, newY) + 1);
		}
		memo[i][j] = res;
		return res;
	}
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int res = 0;
		int row = matrix.size(), col = matrix[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				res = max(res, DFS(matrix, i, j));
			}
		}
		return res;
	}
};