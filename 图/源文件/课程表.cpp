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


// ��������Ĺ�����ȱ�������
class Solution {
private:
	vector<vector<int>> edges;// �߼����飬����ʹ�ö�άvector������Ҳ����ʹ��unordered_map<int, vector<int>> ���ַ���
	vector<int> indeg;  // �������
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		// ������Ĵ�С����ͼ�нڵ������
		edges.resize(numCourses);
		indeg.resize(numCourses);
		for (const auto& info : prerequisites) {
			edges[info[1]].push_back(info[0]); // �� info[1] ----> info[0]
			++indeg[info[0]]; // info[0]�����++
		}
		// ������ȱ������������ݽṹ�Ƕ���
		queue<int> q;
		for (int i = 0; i < numCourses; ++i) {
			if (indeg[i] == 0) {// ���Ϊ0�Ľڵ�ȫ�����
				q.push(i);
			}
		}
		int visited = 0;
		// ģ�������ȱ�����˼����б���
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
		unordered_map<int, vector<int>> edges; // �߼�����
		vector<int> indeg(numCourses, 0); // �������
		for (auto& e : prerequisites) {
			edges[e[1]].push_back(e[0]); // e[1]-----> e[0]
			indeg[e[0]]++; // e[0]�����++
		}
		queue<int> q;// BFS��������ݽṹ
		for (int i = 0; i < numCourses; i++) {
			if (indeg[i] == 0) q.push(i);// �����Ϊ0�Ľڵ�ŵ������У���Ϊ���еĳ�ʼԪ��ֵ
		}
		int cnt = 0;// �������Ľڵ�������ǿγ̽ڵ����������
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