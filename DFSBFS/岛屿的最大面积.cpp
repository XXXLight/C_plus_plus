#include<bits/stdc++.h>
using namespace std;


// DFS
class Solution {
public:
	int dirX[4] = { 0,0,1,-1 }, dirY[4] = { 1,-1,0,0 }; // �ĸ���������
	// DFS�ݹ麯����sum���壺grid��������i,j����Ϊ���ĵĵ�������
	// ��sum=1+DFS(grid,i,j+1)+DFS(grid,i,j-1)+DFS(grid,i+1,j)+DFS(grid,i,j-1)  ����+��������
	int DFS(vector<vector<int>>& grid, int i, int j) {
		int row = grid.size(), col = grid[0].size();
		if (not (i >= 0 && i < row) || not (j >= 0 && j < col) || grid[i][j] == 0) return 0; // �ݹ�߽�
		grid[i][j] = 0;  // ��0��������Ҫ
		int sum = 1;	// ��i��jΪ���ĵĵ�������
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

// DFS�򵥵�д��
class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int ans = 0;
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				ans = max(ans, dfs(i, j, grid));// ����ֵ
		return ans;
	}
	// ����һ���򵥵ĵݹ麯��,�����Ƚ��е�����ԣ��������ͬʱ�����е�����0
	int dfs(int x, int y, vector<vector<int>>& grid) {
		if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
			return 0;
		grid[x][y] = 0;	// ��0��������Ҫ��ֻ����������return
		return 1 + dfs(x - 1, y, grid) + dfs(x, y + 1, grid) + dfs(x + 1, y, grid) + dfs(x, y - 1, grid);
	}
};





// BFS,���ݵ���������д
class Solution {
public:
	int BFS(vector<vector<int>>& grid, int i, int j) {
		int row = grid.size(), col = grid[0].size(); // ����������
		queue<pair<int, int>> q; // ���д������ֵ
		q.push({ i,j }); // ������
		grid[i][j] = 0; // ���ʹ�����0
		int dirX[4] = { 0,0,1,-1 }, dirY[4] = { 1,-1,0,0 }; // �ĸ���������
		int cnt = 0; // �������
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