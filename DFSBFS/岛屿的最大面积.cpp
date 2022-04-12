#include<bits/stdc++.h>
using namespace std;


// DFS
class Solution {
public:
	int dirX[4] = { 0,0,1,-1 }, dirY[4] = { 1,-1,0,0 }; // 四个方向向量
	// DFS递归函数中sum含义：grid方格中以i,j坐标为中心的岛屿数量
	// 则：sum=1+DFS(grid,i,j+1)+DFS(grid,i,j-1)+DFS(grid,i+1,j)+DFS(grid,i,j-1)  中心+上下左右
	int DFS(vector<vector<int>>& grid, int i, int j) {
		int row = grid.size(), col = grid[0].size();
		if (not (i >= 0 && i < row) || not (j >= 0 && j < col) || grid[i][j] == 0) return 0; // 递归边界
		grid[i][j] = 0;  // 置0操作很重要
		int sum = 1;	// 以i，j为中心的岛屿数量
		for (int k = 0; k < 4; k++) {
			int newX = i + dirX[k], newY = j + dirY[k];
			if (newX >= 0 && newX < row&&newY >= 0 && newY < col) {
				sum += DFS(grid, newX, newY);
			}
		}
		return sum;
	}
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int row = grid.size(), col = grid[0].size();
		int res = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == 1)
					res = max(res, DFS(grid, i, j));
			}
		}
		return res;
	}
};

// DFS简单的写法
class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int ans = 0;
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				ans = max(ans, dfs(i, j, grid));// 求最值
		return ans;
	}
	// 就是一个简单的递归函数,可以先进行单点测试，求岛屿面积同时将所有岛屿置0
	int dfs(int x, int y, vector<vector<int>>& grid) {
		if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
			return 0;
		grid[x][y] = 0;	// 置0操作很重要，只有这样才能return
		return 1 + dfs(x - 1, y, grid) + dfs(x, y + 1, grid) + dfs(x + 1, y, grid) + dfs(x, y - 1, grid);
	}
};





// BFS,根据岛屿数量改写
class Solution {
public:
	int BFS(vector<vector<int>>& grid, int i, int j) {
		int row = grid.size(), col = grid[0].size(); // 行数和列数
		queue<pair<int, int>> q; // 队列存放坐标值
		q.push({ i,j }); // 起点入队
		grid[i][j] = 0; // 访问过就置0
		int dirX[4] = { 0,0,1,-1 }, dirY[4] = { 1,-1,0,0 }; // 四个方向向量
		int cnt = 0; // 岛屿面积
		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();
			cnt++;
			for (int k = 0; k < 4; k++) {
				int newX = p.first + dirX[k], newY = p.second + dirY[k];
				if (newX >= 0 && newX < row&&newY >= 0 && newY < col&&grid[newX][newY] == 1) {
					q.push({ newX,newY });
					grid[newX][newY] = 0;
				}
			}
		}
		return cnt;
	}
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int row = grid.size(), col = grid[0].size();
		int res = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == 1)
					res = max(res, BFS(grid, i, j));
			}
		}
		return res;
	}
};