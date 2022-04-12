#include<bits/stdc++.h>
using namespace std;


const int dx[5] = { 0, 1, -1, 0, 0 };
const int dy[5] = { 0, 0, 0, 1, -1 };
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

class Solution {
public:
	int minCost(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector<vector<int>> dist(n, vector<int>(m, INF));
		dist[0][0] = 0;
		priority_queue<pii, vector<pii>, greater<>> pq;
		pq.push(make_pair(0, 0));
		vector<bool> vis(n * m);
		while (!pq.empty()) {
			pii f = pq.top();
			pq.pop();
			if (vis[f.second]) continue;
			vis[f.second] = true;
			int y = f.second / m, x = f.second % m;
			for (int k = 1; k <= 4; ++k) {
				int nx = x + dx[k], ny = y + dy[k];
				if (nx < 0 || nx >= m || ny < 0 || ny >= n)
					continue;
				int nd = f.first + (grid[y][x] == k ? 0 : 1);
				if (nd < dist[ny][nx]) {
					dist[ny][nx] = nd;
					pq.push(make_pair(dist[ny][nx], ny * m + nx));
				}
			}
		}
		return dist[n - 1][m - 1];
	}
};

