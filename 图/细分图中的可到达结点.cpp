#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;



class Solution
{
public:
	int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n)
	{
		unordered_map<int, vector<pair<int, int>>> adjvex;
		for (auto & e : edges)
		{
			int x = e[0], y = e[1], cnt = e[2];
			adjvex[x].push_back({ y, cnt });
			adjvex[y].push_back({ x, cnt });
		}

		vector<int> dist(n, maxMoves + 1);
		dist[0] = 0;

		map<pair<int, int>, int> used;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
		minHeap.push({ 0, 0 });
		vector<bool> visited(n, false);
		while (minHeap.size())
		{
			auto[d, x] = minHeap.top();    minHeap.pop();
			if (visited[x] == true)
				continue;
			visited[x] = true;              //x正式加入MST，dist[x] == d
			for (auto[y, cnt] : adjvex[x])
			{
				if (dist[x] + cnt + 1 < dist[y])
				{
					dist[y] = dist[x] + cnt + 1;
					minHeap.push({ dist[y], y });
				}
				used[{x, y}] = min(cnt, maxMoves - dist[x]);
			}
		}

		int res = 0;
		for (int x = 0; x < n; x++)
			res += (dist[x] <= maxMoves);
		for (auto & e : edges)
		{
			int x = e[0], y = e[1], cnt = e[2];
			res += min(cnt, used[{x, y}] + used[{y, x}]);
		}
		return res;
	}
};

