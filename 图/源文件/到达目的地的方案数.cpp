#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
class Solution {
public:
	long long g[210][210];
	bool vis[210];
	long long dist[210];
	long long cnt[210];
	int n;

	void dijkstra(int x)
	{
		memset(dist, inf, sizeof dist);
		dist[x] = 0;
		cnt[x] = 1;


		for (int i = 0; i < n; i++)
		{
			int t = -1;
			for (int j = 0; j < n; j++)
			{
				if (!vis[j] && (t == -1 || dist[t] > dist[j]))
				{
					t = j;
				}
			}

			if (t == -1) break;
			vis[t] = true;

			for (int j = 0; j < n; j++)
			{
				if (!vis[j])
				{
					if (dist[j] > dist[t] + g[t][j])
					{
						dist[j] = dist[t] + g[t][j];
						cnt[j] = cnt[t];
					}
					else if (dist[j] == dist[t] + g[t][j])
					{
						cnt[j] = (cnt[j] + cnt[t]) % mod;

					}
				}
			}
		}
	}



	int countPaths(int n, vector<vector<int>>& roads) {
		this->n = n;
		memset(g, inf, sizeof g);
		memset(vis, 0, sizeof vis);
		memset(cnt, 0, sizeof cnt);
		// for(int i=0;i<n;i++) g[i][i]=0;
		for (auto road : roads)
		{
			int x = road[0];
			int y = road[1];
			g[x][y] = g[y][x] = min(g[x][y], 1LL * road[2]);
		}
		dijkstra(0);
		// cout<<dist[n-1]<<endl;
		return cnt[n - 1] % mod;

	}
};



class Solution
{
public:
	int countPaths(int n, vector<vector<int>>& roads)
	{
		long long INF = 1e16;
		long long MOD = 1e9 + 7;

		unordered_map<int, vector<pair<int, int>>> adjvex;
		for (auto v : roads)
		{
			int x = v[0], y = v[1], cost = v[2];
			adjvex[x].push_back({ y, cost });
			adjvex[y].push_back({ x, cost });
		}

		vector<long long> dist(n, INF);
		dist[0] = 0;
		vector<long long> f(n, 0L);
		f[0] = 1;
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;
		minHeap.push({ 0, 0 });
		while (!minHeap.empty())
		{
			auto[d, x] = minHeap.top();    minHeap.pop();
			if (d > dist[x])
				continue;
			for (auto[y, cost] : adjvex[x])
			{
				if (dist[x] + cost < dist[y])
				{
					dist[y] = dist[x] + cost;
					f[y] = f[x];
					minHeap.push({ dist[y], y });
				}
				else if (dist[x] + cost == dist[y])
				{
					f[y] += f[x];
					f[y] %= MOD;
				}
			}
		}
		return f[n - 1] % MOD;
	}
};
