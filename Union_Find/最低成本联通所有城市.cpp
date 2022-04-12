#include<bits/stdc++.h>
using namespace std;


class UnionFind
{
public:
	vector<int> parent;
	vector<int> size;
	int part;

	UnionFind(int n)
	{
		for (int x = 0; x < n; x++)
			parent.push_back(x);
		size.resize(n, 1);
		part = n;
	}
	//---------- 扁平化
	int Find(int x)
	{
		if (parent[x] != x)
			parent[x] = Find(parent[x]);
		return parent[x];
	}
	//---------- size策略
	bool Union(int x, int y)
	{
		int root_x = Find(x);
		int root_y = Find(y);
		if (root_x == root_y)
			return false;
		if (size[root_x] > size[root_y])
			swap(root_x, root_y);
		parent[root_x] = root_y;
		size[root_y] += size[root_x];
		part--;
		return true;
	}

};

class Solution
{
public:
	int minimumCost(int N, vector<vector<int>>& connections)
	{
		//------------------ kruskal算法
		vector<tuple<int, int, int>> edge;
		for (auto v : connections)
		{
			int x = v[0], y = v[1], cost = v[2];
			edge.push_back(tuple<int, int, int>{cost, x - 1, y - 1});
		}
		sort(edge.begin(), edge.end());

		int tot_cost = 0;
		UnionFind MST(N);
		for (auto[cost, x, y] : edge)
		{
			if (MST.Union(x, y) == false)
				continue;
			tot_cost += cost;
			if (MST.part == 1)
				return tot_cost;
		}
		return -1;
	}
};

