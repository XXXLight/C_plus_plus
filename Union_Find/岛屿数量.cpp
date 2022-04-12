#include<bits/stdc++.h>
using namespace std;

// UF  3+5
// 记忆方法： count parent size(3数据)
//  方法：构造函数+连通pq+判断是否连通+找根节点+返回连通数(5方法)

// 超时就要考虑换另一个模板
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


//	DFS
class Solution {
public:
	void DFS(vector<vector<char>>& grid, int i, int j) {
		int row = grid.size();
		if (row == 0) return;
		int col = grid[0].size();
		if (not (i >= 0 && i < row&&j >= 0 && j < col) || grid[i][j] == '0') return;
		grid[i][j] = '0';
		DFS(grid, i + 1, j);
		DFS(grid, i - 1, j);
		DFS(grid, i, j + 1);
		DFS(grid, i, j - 1);
	}
	int numIslands(vector<vector<char>>& grid) {
		int row = grid.size();
		if (row == 0) return 0;
		int col = grid[0].size();
		int res = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == '1') {
					res++;
					DFS(grid, i, j);
				}
			}
		}
		return res;
	}
};
// 简写版的DFS
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



// BFS
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int nr = grid.size();
		if (!nr) return 0;
		int nc = grid[0].size();

		int num_islands = 0;
		for (int r = 0; r < nr; ++r) {
			for (int c = 0; c < nc; ++c) {
				if (grid[r][c] == '1') {
					++num_islands;
					grid[r][c] = '0';
					queue<pair<int, int>> neighbors;
					neighbors.push({ r, c });
					while (!neighbors.empty()) {
						auto rc = neighbors.front();
						neighbors.pop();
						int row = rc.first, col = rc.second;
						if (row - 1 >= 0 && grid[row - 1][col] == '1') {
							neighbors.push({ row - 1, col });
							grid[row - 1][col] = '0';
						}
						if (row + 1 < nr && grid[row + 1][col] == '1') {
							neighbors.push({ row + 1, col });
							grid[row + 1][col] = '0';
						}
						if (col - 1 >= 0 && grid[row][col - 1] == '1') {
							neighbors.push({ row, col - 1 });
							grid[row][col - 1] = '0';
						}
						if (col + 1 < nc && grid[row][col + 1] == '1') {
							neighbors.push({ row, col + 1 });
							grid[row][col + 1] = '0';
						}
					}
				}
			}
		}

		return num_islands;
	}
};

