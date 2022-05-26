#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	bool used[105][105][210] = { 0 };
	bool hasValidPath(vector<vector<char>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		return dfs(grid, 0, 0, 0);
	}
	bool dfs(vector<vector<char>>& grid, int x, int y, int score) {
		int m = grid.size();
		int n = grid[0].size();
		score += grid[x][y] == '(' ? 1 : -1;
		if (score < 0) return false;
		if (x == m - 1 && y == n - 1 && score == 0) {
			return true;
		}
		if (used[x][y][score]) return false;// 这是因为所有的结果是a或b或c的关系，返回false对结果是没有影响的
		used[x][y][score] = true;//此点的这个状态已经访问过
		bool res = false;
		int di[2] = { 0,1 }, dj[2] = { 1, 0 };

		for (int k = 0; k < 2; k++)
		{
			int newX = x + di[k], newY = y + dj[k];
			if (newX >= 0 && newX < m&&newY >= 0 && newY < n)
				res = res or dfs(grid, newX, newY, score);
		}
		return res;

	}
};

