#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


class Solution {
private:
	vector<vector<int>> edges;
	vector<int> visited;
	bool valid = true;

public:
	void dfs(int u) {
		visited[u] = 1;
		for (int v : edges[u]) {
			if (visited[v] == 0) {
				dfs(v);
				if (!valid) {
					return;
				}
			}
			else if (visited[v] == 1) {
				valid = false;
				return;
			}
		}
		visited[u] = 2;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		edges.resize(numCourses);
		visited.resize(numCourses);
		for (const auto& info : prerequisites) {
			edges[info[1]].push_back(info[0]);
		}
		for (int i = 0; i < numCourses && valid; ++i) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		return valid;
	}
};


// 拓扑排序的广度优先遍历方法
class Solution {
private:
	vector<vector<int>> edges;// 边集数组，可以使用二维vector方法，也可以使用unordered_map<int, vector<int>> 这种方法
	vector<int> indeg;  // 入度数组
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		// 两数组的大小都是图中节点的数量
		edges.resize(numCourses);
		indeg.resize(numCourses);
		for (const auto& info : prerequisites) {
			edges[info[1]].push_back(info[0]); // 由 info[1] ----> info[0]
			++indeg[info[0]]; // info[0]的入度++
		}
		// 广度优先遍历依赖的数据结构是队列
		queue<int> q;
		for (int i = 0; i < numCourses; ++i) {
			if (indeg[i] == 0) {// 入度为0的节点全部入队
				q.push(i);
			}
		}
		int visited = 0;
		// 模拟广度优先遍历的思想进行遍历
		while (!q.empty()) {
			++visited;
			int u = q.front();
			q.pop();
			for (int v : edges[u]) {
				--indeg[v];
				if (indeg[v] == 0) {
					q.push(v);
				}
			}
		}

		return visited == numCourses;
	}
};



class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, vector<int>> edges; // 边集数组
		vector<int> indeg(numCourses, 0); // 入度数组
		for (auto& e : prerequisites) {
			edges[e[1]].push_back(e[0]); // e[1]-----> e[0]
			indeg[e[0]]++; // e[0]的入度++
		}
		queue<int> q;// BFS所需的数据结构
		for (int i = 0; i < numCourses; i++) {
			if (indeg[i] == 0) q.push(i);// 将入度为0的节点放到队列中，作为队列的初始元素值
		}
		int cnt = 0;// 当遍历的节点个数就是课程节点个数返回真
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			cnt++;
			for (auto e : edges[cur]) {
				indeg[e]--;
				if (indeg[e] == 0) q.push(e);
			}
		}
		return cnt == numCourses;
	}
};