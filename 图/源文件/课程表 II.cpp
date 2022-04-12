#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


// ���������DFS�ⷨ
// ����ͼ
class Solution {
private:
	// �洢����ͼ,�ڽӱ�
	vector<vector<int>> edges;
	// ���ÿ���ڵ��״̬��0=δ������1=�����У�2=�����
	vector<int> visited;
	// ��������ģ��ջ���±� 0 Ϊջ�ף�n-1 Ϊջ��
	vector<int> result;
	// �ж�����ͼ���Ƿ��л���true��ʾû�л�
	bool valid = true;

public:
	void dfs(int u) {
		// ���ڵ���Ϊ�������С�
		visited[u] = 1;
		// ���������ڽڵ�
		// ֻҪ�����л�������ֹͣ����
		for (int v : edges[u]) {
			// �����δ��������ô�������ڽڵ�
			if (visited[v] == 0) {
				dfs(v);
				if (!valid) {
					return;
				}
			}
			// ����������С�˵���ҵ��˻�
			else if (visited[v] == 1) {
				valid = false;
				return;
			}
		}
		// ���ڵ���Ϊ������ɡ�
		visited[u] = 2;
		// ���ڵ���ջ
		result.push_back(u);
	}

	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		edges.resize(numCourses);
		visited.resize(numCourses);
		for (const auto& info : prerequisites) {
			edges[info[1]].push_back(info[0]); // info[1]����㣬info[0]���յ㣬�뵽�ڽӱ����
		}
		// ÿ����ѡһ����δ�������Ľڵ㣬��ʼ���������������
		for (int i = 0; i < numCourses && valid; ++i) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		if (!valid) {
			return {};
		}
		// ���û�л�����ô������������
		// ע���±� 0 Ϊջ�ף������Ҫ�����鷴�����
		reverse(result.begin(), result.end());
		return result;
	}
};


// ���������Kahn�ⷨ
class Solution {
private:
	// �洢����ͼ
	vector<vector<int>> edges;
	// �洢ÿ���ڵ�����
	vector<int> indeg;
	// �洢��
	vector<int> result;

public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		edges.resize(numCourses);
		indeg.resize(numCourses);
		for (const auto& info : prerequisites) {
			edges[info[1]].push_back(info[0]); // info[1] =====> info[0]
			++indeg[info[0]]; // info[1] =====> info[0],������info[0]��ȼ�1
		}

		queue<int> q;
		// ���������Ϊ 0 �Ľڵ���������
		for (int i = 0; i < numCourses; ++i) {
			if (indeg[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			// �Ӷ���ȡ��һ���ڵ�
			int u = q.front();
			q.pop();
			// �������
			result.push_back(u);
			for (int v : edges[u]) {
				--indeg[v];
				// ������ڽڵ� v �����Ϊ 0���Ϳ���ѡ v ��Ӧ�Ŀγ���
				if (indeg[v] == 0) {
					q.push(v);
				}
			}
		}

		if (result.size() != numCourses) {
			return {};
		}
		return result;
	}
};




// �Լ�д�����Ĵ�����Ǻô���
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, vector<int>> edges;
		vector<int> indeg(numCourses, 0);
		vector<int> res;
		for (auto& e : prerequisites) {
			edges[e[1]].push_back(e[0]), indeg[e[0]]++;
		}
		queue<int> q;
		for (int i = 0; i < numCourses; i++) {
			if (indeg[i] == 0) q.push(i);
		}
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			res.push_back(cur);
			for (auto e : edges[cur]) {
				indeg[e]--;
				if (indeg[e] == 0) q.push(e);
			}
		}
		if (res.size() == numCourses) return res;
		else return {};
	}
};
