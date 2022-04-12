#include<bits/stdc++.h>
using namespace std;

// 不要为了做题而做题，要思考
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int ans = 0;
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				if (dfs(i, j, grid)) ans++;
		return ans;
	}
	// 就是一个简单的递归函数,可以先进行单点测试
	int dfs(int x, int y, vector<vector<char>>& grid) {
		if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0')
			return 0;
		grid[x][y] = '0';	// 置0操作很重要，只有这样才能return
		return 1 + dfs(x - 1, y, grid) + dfs(x, y + 1, grid) + dfs(x + 1, y, grid) + dfs(x, y - 1, grid);
	}
};


// DFS
class Solution {
public:
	// dfs函数作用，从中心点i,j出发进行深度优先搜索，将所有周围点置“0”
	void dfs(vector<vector<char>>& grid, int i, int j) {
		int row = grid.size(); //行数
		int col = grid[0].size(); //列数
		// 递归边界问题，逆向思维，不在该范围,走“迷宫”，碰到暗的地方记得回来
		if (not (i >= 0 && i < row) || not (j >= 0 && j < col) || grid[i][j] == '0') return;
		grid[i][j] = '0';
		// 四个方向，即方向数组
		int di[4] = { 0,0,1,-1 }, dj[4] = { 1,-1,0,0 };
		// dfs模板 u for(u==>v) 
		// 注意枚举变量
		for (int k = 0; k < 4; k++)
		{
			int newX = i + di[k], newY = j + dj[k];
			dfs(grid, newX, newY);
		}
	}
	int numIslands(vector<vector<char>>& grid) {
		int row = grid.size();
		if (row == 0) return 0;
		int col = grid[0].size();
		int cnt = 0;
		// 具体做法：碰到“1”，对该点进行DFS，将和该点连通的所有点“1”置0
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == '1')
					cnt++;
				dfs(grid, i, j);
			}
		}
		return cnt;
	}
};



// BFS+结构体写法
class Solution {
public:
	int m, n, dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} }; // 定义4个方向的x,y增量
	struct P { int x, y; }; // 结构体方式
	void BFS(vector<vector<char>>& grid, int sx, int sy) {
		queue<P> q;
		q.push({ sx, sy }); // 起点入队列
		grid[sx][sy] = '0'; // 起点陆地改为水
		while (!q.empty()) {
			P p = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) { // 遍历4个方位
				int xx = p.x + dir[i][0], yy = p.y + dir[i][1];
				if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == '1') { // 新位置不越界且为陆地
					q.push({ xx, yy }); // 新位置入队列
					grid[xx][yy] = '0'; // 新位置由陆地改为水
				}
			}
		}
	}
	int numIslands(vector<vector<char>>& grid) {
		int cnt = 0;
		m = grid.size(); n = grid[0].size();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (grid[i][j] == '1') { // 当前位置为陆地进行BFS(连通的陆地都会更改为水),岛屿数量+1
					cnt++;
					BFS(grid, i, j);
				}
		return cnt; // 返回岛屿数量
	}
};

// 自己写的BFS，使用pair<int,int>写法
class Solution {
public:
	int BFS(vector<vector<char>>& grid, int i, int j) {
		int row = grid.size(), col = grid[0].size(); // 行数和列数
		queue<pair<int, int>> q; // 队列存放坐标值
		q.push({ i,j }); // 起点入队
		grid[i][j] = '0'; // 访问过就置0
		int dirX[4] = { 0,0,1,-1 }, dirY[4] = { 1,-1,0,0 }; // 四个方向向量
		int cnt = 0; // 岛屿面积
		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();
			cnt++;
			for (int k = 0; k < 4; k++) {
				int newX = p.first + dirX[k], newY = p.second + dirY[k];
				if (newX >= 0 && newX < row&&newY >= 0 && newY < col&&grid[newX][newY] == '1') {
					q.push({ newX,newY });
					grid[newX][newY] = '0';
				}
			}
		}
		return cnt;
	}
	int numIslands(vector<vector<char>>& grid) {
		int row = grid.size();
		int col = grid[0].size();
		int cnt = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == '1') {
					cnt++;
					BFS(grid, i, j);
				}
			}
		}
		return cnt;
	}
};




// 并查集
class UF {
public:
	// 记录连通分量个数
	int count;
	// 存储若干棵树
	vector<int> parent;
	// 记录树的“重量”
	vector<int> size;

	UF(int n) {
		this->count = n;
		parent.resize(n);
		size.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	/* 将 p 和 q 连通 */
	void unionAB(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		if (rootP == rootQ)
			return;

		// 小树接到大树下面，较平衡
		if (size[rootP] < size[rootQ]) swap(rootP, rootQ);
		size[rootP] += size[rootQ];
		parent[rootQ] = rootP;
		count--;
	}

	/* 判断 p 和 q 是否互相连通 */
	bool connected(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		// 处于同一棵树上的节点，相互连通
		return rootP == rootQ;
	}

	/* 返回节点 x 的根节点 */
	int find(int x) {
		while (parent[x] != x) {
			// 进行路径压缩
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}

	int count_num() {
		return this->count;
	}
};


class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int row = grid.size();
		if (row == 0) return 0;
		int col = grid[0].size();
		UF* uf = new UF(row*col); //拉成一维数组，大小为row*col
		//合并union操作
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == '1') {
					if (i + 1 < row&&grid[i + 1][j] == '1')uf->unionAB((i)*col + j, (i + 1)*col + j);
					if (i - 1 > 0 && grid[i - 1][j] == '1')uf->unionAB((i)*col + j, (i - 1)*col + j);
					if (j + 1 < col&&grid[i][j + 1] == '1')uf->unionAB((i)*col + j, i*col + j + 1);
					if (j - 1 > 0 && grid[i][j - 1] == '1')uf->unionAB((i)*col + j, i*col + j - 1);
				}
			}
		}
		// 0的个数
		int cnt0 = 0;
		for (auto vec : grid) {
			for (auto e : vec) {
				if (e == '0')
					cnt0++;
			}
		}

		// 有几堆
		return uf->count - cnt0;
	}
};