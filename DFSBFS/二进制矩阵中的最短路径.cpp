#include<bits/stdc++.h>
using namespace std;


// 其实很简单，就是BFS的层数问题
class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		if (grid[0][0] == 1)return -1;
		int n = grid.size(), ans = 1;
		const int dire[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1} };
		queue<pair<int, int>> q;// 坐标使用pair对进行绑定，也可以使用结构体
		q.emplace(0, 0);         //从0,0开始，起点加入队列
		grid[0][0] = 1;           //标记为1代表走过
		while (!q.empty()) {      //bfs
			int m = q.size();
			while (m--) {
				auto[x, y] = q.front();
				q.pop();
				if (x == n - 1 && y == n - 1)return ans;// 递归推出条件是到达终点
				for (int i = 0; i < 8; i++) {                       //遍历八个方向的
					int nx = x + dire[i][0];
					int ny = y + dire[i][1];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;   //判断是否越界
					if (grid[nx][ny] == 0) {        //判断是否能走
						q.emplace(nx, ny);
						grid[nx][ny] = 1;         //标记访问过
					}
				}
			}
			ans++;          //记录循环次数，while循环外面是层数
		}
		return -1;
	}
};







class Solution {
public:
	int dirX[8] = { -1,-1,-1,0,0,1,1,1 };
	int dirY[8] = { -1,0,1,1,-1,-1,0,1 };
	bool vis[101][101] = { false };
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int n = grid.size();
		if (grid[0][0] == 1) return -1;
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		int cnt = 0;
		while (!q.empty()) {
			int len = q.size();
			while (len--) {
				pair<int, int> fr = q.front();
				q.pop();
				if (fr.first == n - 1 && fr.second == n - 1 && grid[n - 1][n - 1] == 0) return cnt + 1;
				for (int i = 0; i < 8; i++) {
					int newX = fr.first + dirX[i];
					int newY = fr.second + dirY[i];
					// 碰到新的坐标，没有访问则进行访问，并进行flag标记
					if (newX >= 0 && newX < n&&newY >= 0 && newY < n&&grid[newX][newY] == 0 && !vis[newX][newY]) {
						q.push({ newX,newY });
						vis[newX][newY] = 1;// 在这里进行标记
					}
				}
			}
			cnt++;
		}
		return -1;
	}
};