#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// �ڽӾ�����vector<vector<int>>
// �ڽӱ���unordered_map<int, vector<int>> ?�����ָ�����ֻ��ʹ�ù�ϣ��

class Solution {
public:
	vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
		unordered_map<int, vector<int>> adj;//�ڽӱ���ӡ������֪����ʲô������
		unordered_map<int, int> in_deg; //ÿ���ڵ�����
		// ����ͼ��˫������
		for (auto &v : adjacentPairs) { // v��adjacentPairs��Ԫ�أ���һ��vector<int>
			adj[v[0]].emplace_back(v[1]);
			adj[v[1]].emplace_back(v[0]);
			in_deg[v[0]]++;
			in_deg[v[1]]++;
		}
		int start;
		for (auto [num, deg] : in_deg) { //����===>C++====>����=====>C++17���У�����ᱨ����һ�ַ�ʽ����map
			if (deg == 1) { //���Ϊ1�ǿ�ʼ�ڵ�
				start = num;
				break;
			}
		}
		//������BFS�����˿�ʼ�ڵ�start���ڽӱ�
		queue<int> q;
		q.emplace(start);
		vector<int> ans;
		unordered_set<int> vis;
		vis.emplace(start);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			ans.emplace_back(u);
			for (int v : adj[u]) {
				if (!vis.count(v)) { //û�з��ʹ�
					vis.emplace(v); //���Ϊ�Ѿ����ʹ�
					q.emplace(v);
				}
			}
		}
		return ans;
	}
};