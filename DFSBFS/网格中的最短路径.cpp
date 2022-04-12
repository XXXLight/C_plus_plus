#include<bits/stdc++.h>
using namespace std;

// 每一个(x,y)坐标的状态是k
struct Nagato {
	int x, y;
	int rest;
	Nagato(int _x, int _y, int _r) : x(_x), y(_y), rest(_r) {}
};

class Solution {
private:
	static constexpr int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

public:
	int shortestPath(vector<vector<int>>& grid, int k) {
		int m = grid.size(), n = grid[0].size();
		if (m == 1 && n == 1) {
			return 0;
		}

		k = min(k, m + n - 3);
		bool visited[m][n][k + 1];
		memset(visited, false, sizeof(visited));
		queue<Nagato> q;
		q.emplace(0, 0, k);
		visited[0][0][k] = true;
		int step = 1;
		while (!q.empty()) {
			int cnt = q.size();
			while (cnt--) {
				Nagato cur = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i) {
					int nx = cur.x + dirs[i][0];
					int ny = cur.y + dirs[i][1];
					if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
						// 坐标点是0，且k没有用完
						if (grid[nx][ny] == 0 && !visited[nx][ny][cur.rest]) {
							// 到达终点（最右下）
							if (nx == m - 1 && ny == n - 1) {
								return step;
							}
							// 没有到达终点，因为当前坐标是0，所以k不变
							q.emplace(nx, ny, cur.rest);// 都没有使用先构造结构体的方式直接生成实例化对象
							visited[nx][ny][cur.rest] = true;
						}
						// 坐标点是1
						else if (grid[nx][ny] == 1 && cur.rest > 0 && !visited[nx][ny][cur.rest - 1]) {
							// 因为坐标是1，所以用了一个
							q.emplace(nx, ny, cur.rest - 1);
							visited[nx][ny][cur.rest - 1] = true;
						}
					}
				}
			}
			step++;
		}
		return -1;
	}
};




// 逻辑上想的越清楚，代码实现起来出错的概率就越小，卡在一个测试用例，并不代表后面的测试用例就过不了

// 使用class的形式来定义加上public就可以了
class Node {
public:
	int x, y, cnt;
	Node(int _x, int _y, int _cnt) :x(_x), y(_y), cnt(_cnt) {};
};
class Solution {
public:
	int dirX[4] = { 0,0,1,-1 }, dirY[4] = { 1,-1,0,0 };
	int shortestPath(vector<vector<int>>& grid, int k) {
		int row = grid.size(), col = grid[0].size();
		if (row == 1 && col == 1) return 0;
		int flag[row][col][k + 1];
		memset(flag, false, sizeof(flag));
		flag[0][0][k] = true;
		queue<Node> q;
		Node n1 = Node(0, 0, k);// 使用构造函数构造出起点
		q.push(n1);// 起点加入队列
		int res = 0;
		while (!q.empty()) {
			int len = q.size();
			while (len--) {
				Node n2 = q.front();
				q.pop();
				for (int kk = 0; kk < 4; kk++) {
					int newX = n2.x + dirX[kk], newY = n2.y + dirY[kk];
					if (newX >= 0 && newX < row&&newY >= 0 && newY < col) {// 边界检测
						if (newX == row - 1 && newY == col - 1) return res + 1;// 到达终点return结果
						if (grid[newX][newY] == 0 && !flag[newX][newY][n2.cnt]) {
							flag[newX][newY][n2.cnt] = true;
							// 新的节点入队
							Node n3 = Node(newX, newY, n2.cnt);
							q.push(n3);
						}
						else if (grid[newX][newY] == 1 && n2.cnt - 1 >= 0 && !flag[newX][newY][n2.cnt - 1]) {
							flag[newX][newY][n2.cnt - 1] = true;
							// 新的节点入队
							Node n3 = Node(newX, newY, n2.cnt - 1);
							q.push(n3);
						}
					}
				}
			}
			res++;// 记录BFS的层数
		}
		return -1;
	}
};