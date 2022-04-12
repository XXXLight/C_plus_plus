#include<bits/stdc++.h>
using namespace std;


int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
struct item {
	int x, y, value, dis;// x,yºá×Ý×ø±ê  value¼ÛÖµ dis¾àÀë
	item(int _x, int _y, int _value, int _dis) {
		x = _x; y = _y; value = _value; dis = _dis;
	}
};
class Solution {
public:
	vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
		int m = grid.size(), n = grid[0].size();
		bool isVisited[m][n];
		memset(isVisited, false, sizeof(isVisited));
		queue<pair<int, int>> q;
		q.push({ start[0],start[1] });
		isVisited[start[0]][start[1]] = true;
		vector<item> res;
		int startX = start[0], startY = start[1];
		if (grid[startX][startY] >= pricing[0] && grid[startX][startY] <= pricing[1] && grid[startX][startY] != 1) {
			res.push_back({ startX,startY,grid[startX][startY],0 });
		}
		int dis = 1;
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				auto[x, y] = q.front(); q.pop();
				for (int i = 0; i < 4; ++i) {
					int newx = x + dx[i], newy = y + dy[i];
					if (newx < 0 || newx >= m || newy < 0 || newy >= n)continue;
					if (isVisited[newx][newy] == true || grid[newx][newy] == 0)continue;
					if (grid[newx][newy] >= pricing[0] && grid[newx][newy] <= pricing[1] && grid[newx][newy] != 1)                     res.push_back({ newx,newy,grid[newx][newy],dis });
					isVisited[newx][newy] = true;
					q.push({ newx,newy });
				}
			}
			++dis;
		}
		sort(res.begin(), res.end(), [](auto &lhs, auto &rhs) {
			if (lhs.dis < rhs.dis)return true;
			if (lhs.dis == rhs.dis) {
				if (lhs.value < rhs.value)return true;
				if (lhs.value == rhs.value) {
					if (lhs.x < rhs.x)return true;
					if (lhs.x == rhs.x)return lhs.y < rhs.y;
					return false;
				}
				return false;
			}
			return false;
		});
		vector<vector<int>> ans;
		for (int i = 0; i < res.size() && i < k; ++i) {
			ans.push_back({ res[i].x,res[i].y });
		}
		return ans;
	}
};

