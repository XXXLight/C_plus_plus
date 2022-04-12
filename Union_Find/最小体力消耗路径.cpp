#include<bits/stdc++.h>
using namespace std;

// 并查集模板
class UnionFind {
public:
	vector<int> parent;
	vector<int> size;
	int n;
	// 当前连通分量数目
	int setCount;

public:
	UnionFind(int _n) : n(_n), setCount(_n), parent(_n), size(_n, 1) {
		iota(parent.begin(), parent.end(), 0);
	}

	int findset(int x) {
		return parent[x] == x ? x : parent[x] = findset(parent[x]);
	}

	void unite(int x, int y) {
		x = findset(x);
		y = findset(y);
		if (x != y) {
			parent[y] = x;
		}
		// 这样写setCount是有问题的，这里只是没有用到才没有出错
		--setCount;
	}

	bool connected(int x, int y) {
		x = findset(x);
		y = findset(y);
		return x == y;
	}
};

class Solution {
public:
	int minimumEffortPath(vector<vector<int>>& heights) {
		int m = heights.size();
		int n = heights[0].size();
		vector<tuple<int, int, int>> edges;
		// 初始化边集
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				int id = i * n + j;
				if (i > 0) {
					edges.emplace_back(id - n, id, abs(heights[i][j] - heights[i - 1][j]));
				}
				if (j > 0) {
					edges.emplace_back(id - 1, id, abs(heights[i][j] - heights[i][j - 1]));
				}
			}
		}
		// 按边的权重排序
		sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2) {
			auto&&[x1, y1, v1] = e1;//解构赋值
			auto&&[x2, y2, v2] = e2;//解构赋值
			return v1 < v2;
		});

		UnionFind uf(m * n);
		int ans = 0;
		for (const auto[x, y, v] : edges) {
			uf.unite(x, y);
			if (uf.connected(0, m * n - 1)) {
				ans = v;
				break;
			}
		}
		return ans;
	}
};




// 二分查找
class Solution {
private:
	static constexpr int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

public:
	int minimumEffortPath(vector<vector<int>>& heights) {
		int m = heights.size();
		int n = heights[0].size();
		int left = 0, right = 999999, ans = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			queue<pair<int, int>> q;
			q.emplace(0, 0);
			vector<int> seen(m * n);
			seen[0] = 1;
			while (!q.empty()) {
				auto[x, y] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i) {
					int nx = x + dirs[i][0];
					int ny = y + dirs[i][1];
					if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx * n + ny] && abs(heights[x][y] - heights[nx][ny]) <= mid) {
						q.emplace(nx, ny);
						seen[nx * n + ny] = 1;
					}
				}
			}
			if (seen[m * n - 1]) {
				ans = mid;
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return ans;
	}
};


