#include<bits/stdc++.h>
using namespace std;

// ��ҪΪ����������⣬Ҫ˼��
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int ans = 0;
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				if (dfs(i, j, grid)) ans++;
		return ans;
	}
	// ����һ���򵥵ĵݹ麯��,�����Ƚ��е������
	int dfs(int x, int y, vector<vector<char>>& grid) {
		if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0')
			return 0;
		grid[x][y] = '0';	// ��0��������Ҫ��ֻ����������return
		return 1 + dfs(x - 1, y, grid) + dfs(x, y + 1, grid) + dfs(x + 1, y, grid) + dfs(x, y - 1, grid);
	}
};


// DFS
class Solution {
public:
	// dfs�������ã������ĵ�i,j�����������������������������Χ���á�0��
	void dfs(vector<vector<char>>& grid, int i, int j) {
		int row = grid.size(); //����
		int col = grid[0].size(); //����
		// �ݹ�߽����⣬����˼ά�����ڸ÷�Χ,�ߡ��Թ������������ĵط��ǵû���
		if (not (i >= 0 && i < row) || not (j >= 0 && j < col) || grid[i][j] == '0') return;
		grid[i][j] = '0';
		// �ĸ����򣬼���������
		int di[4] = { 0,0,1,-1 }, dj[4] = { 1,-1,0,0 };
		// dfsģ�� u for(u==>v) 
		// ע��ö�ٱ���
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
		// ����������������1�����Ըõ����DFS�����͸õ���ͨ�����е㡰1����0
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



// BFS+�ṹ��д��
class Solution {
public:
	int m, n, dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} }; // ����4�������x,y����
	struct P { int x, y; }; // �ṹ�巽ʽ
	void BFS(vector<vector<char>>& grid, int sx, int sy) {
		queue<P> q;
		q.push({ sx, sy }); // ��������
		grid[sx][sy] = '0'; // ���½�ظ�Ϊˮ
		while (!q.empty()) {
			P p = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) { // ����4����λ
				int xx = p.x + dir[i][0], yy = p.y + dir[i][1];
				if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == '1') { // ��λ�ò�Խ����Ϊ½��
					q.push({ xx, yy }); // ��λ�������
					grid[xx][yy] = '0'; // ��λ����½�ظ�Ϊˮ
				}
			}
		}
	}
	int numIslands(vector<vector<char>>& grid) {
		int cnt = 0;
		m = grid.size(); n = grid[0].size();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (grid[i][j] == '1') { // ��ǰλ��Ϊ½�ؽ���BFS(��ͨ��½�ض������Ϊˮ),��������+1
					cnt++;
					BFS(grid, i, j);
				}
		return cnt; // ���ص�������
	}
};

// �Լ�д��BFS��ʹ��pair<int,int>д��
class Solution {
public:
	int BFS(vector<vector<char>>& grid, int i, int j) {
		int row = grid.size(), col = grid[0].size(); // ����������
		queue<pair<int, int>> q; // ���д������ֵ
		q.push({ i,j }); // ������
		grid[i][j] = '0'; // ���ʹ�����0
		int dirX[4] = { 0,0,1,-1 }, dirY[4] = { 1,-1,0,0 }; // �ĸ���������
		int cnt = 0; // �������
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




// ���鼯
class UF {
public:
	// ��¼��ͨ��������
	int count;
	// �洢���ɿ���
	vector<int> parent;
	// ��¼���ġ�������
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

	/* �� p �� q ��ͨ */
	void unionAB(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		if (rootP == rootQ)
			return;

		// С���ӵ��������棬��ƽ��
		if (size[rootP] < size[rootQ]) swap(rootP, rootQ);
		size[rootP] += size[rootQ];
		parent[rootQ] = rootP;
		count--;
	}

	/* �ж� p �� q �Ƿ�����ͨ */
	bool connected(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		// ����ͬһ�����ϵĽڵ㣬�໥��ͨ
		return rootP == rootQ;
	}

	/* ���ؽڵ� x �ĸ��ڵ� */
	int find(int x) {
		while (parent[x] != x) {
			// ����·��ѹ��
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
		UF* uf = new UF(row*col); //����һά���飬��СΪrow*col
		//�ϲ�union����
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
		// 0�ĸ���
		int cnt0 = 0;
		for (auto vec : grid) {
			for (auto e : vec) {
				if (e == '0')
					cnt0++;
			}
		}

		// �м���
		return uf->count - cnt0;
	}
};