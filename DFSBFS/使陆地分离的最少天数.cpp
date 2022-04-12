#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	bool check(const vector<vector<int>>& grid) {
		int x = 0, y = 0;
		int cnt = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == 0) continue;
				cnt++;
				x = i;
				y = j;
			}
		}
		if (cnt == 0) {
			return true;
		}
		queue<pair<int, int>> q;
		bool mark[30][30] = { 0 };
		q.push(make_pair(x, y));
		mark[x][y] = true;
		cnt--;
		while (q.empty() == false) {
			auto f = q.front();
			q.pop();
			int dx[] = { -1,  1, 0, 0 };
			int dy[] = { 0, 0, -1, 1 };
			for (int i = 0; i < 4; i++) {
				int nx = dx[i] + f.first;
				int ny = dy[i] + f.second;
				if (0 <= nx && nx < grid.size() && 0 <= ny && ny < grid[0].size() && grid[nx][ny] == 1) {
					auto p = make_pair(nx, ny);
					if (mark[nx][ny]) { continue; }
					mark[nx][ny] = true;
					q.push(p);
					cnt--;
				}
			}
		}
		return cnt != 0;
	}
	int minDays(vector<vector<int>>& grid) {
		if (check(grid)) {
			return 0;
		}
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 0) {
					continue;
				}
				grid[i][j] = 0;
				if (check(grid)) {
					return 1;
				}
				grid[i][j] = 1;
			}
		}
		return 2;
	}
};




// 逻辑错误，可以尝试对的逻辑

// Solution1是求岛屿数量
class Solution1 {
public:
	int numIslands(vector<vector<int>>& grid) {
		int ans = 0;
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				if (dfs(i, j, grid)) ans++;
		return ans;
	}
	// 就是一个简单的递归函数,可以先进行单点测试
	int dfs(int x, int y, vector<vector<int>>& grid) {
		if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
			return 0;
		grid[x][y] = 0;	// 置0操作很重要，只有这样才能return
		return 1 + dfs(x - 1, y, grid) + dfs(x, y + 1, grid) + dfs(x + 1, y, grid) + dfs(x, y - 1, grid);
	}
};
class Solution {
public:
	bool check(vector<vector<int>> grid) {
		// 岛屿数量是0或者岛屿数量>=2
		return Solution1().numIslands(grid) != 1;
	}
	int minDays(vector<vector<int>>& grid) {
		int row = grid.size();
		int col = grid[0].size();
		if (check(grid)) return 0;
		else {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (grid[i][j] == 1) {
						// 回溯法的思想
						grid[i][j] = 0;
						if (check(grid)) return 1;
						grid[i][j] = 1;
					}
				}
			}
			return 2;
		}
	}
};