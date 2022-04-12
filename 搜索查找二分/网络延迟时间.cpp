#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<int> dis(N + 1, -1);
		dis[K] = 0;
		using Pair = pair<int, int>;//first�Ǿ��룬second��Ŀ���
		priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
		pq.emplace(0, K);//��������

		while (!pq.empty()) {
			auto e = pq.top(); pq.pop();//eΪ����visited��unvisited����С��
			if (e.first > dis[e.second]) continue;//���e��Ȩ��K��e.second���󣬾Ͳ���������·����
			for (int i = 0; i < times.size(); i++) {
				if (times[i][0] == e.second) {//����һ��������e.secondΪ���ıߣ���relax������relax֮��ĵ����
					int v = times[i][1];
					int w = e.first + times[i][2];
					if (dis[v] == -1 || dis[v] > w) {
						dis[v] = w;
						pq.emplace(w, v);
					}
				}
			}

		}

		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (dis[i] == -1) return -1;
			ans = max(ans, dis[i]);
		}
		return ans;
	}
};



class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<vector<long long>> graph(N + 1, vector<long long>(N + 1, INT_MAX));
		for (int i = 1; i <= N; i++)    graph[i][i] = 0;
		for (auto e : times)    graph[e[0]][e[1]] = e[2];
		vector<bool> visited(N + 1, false);    visited[K] = true;

		for (int i = 1; i < N; i++) {//����һ�α�ʾ����K��j������һ�����ܲ�������·����һ������N-1�Ϳ��ԡ�
			int min_id = 0, min_dis = INT_MAX;//ÿ����unused�ĵ����ҵ�K������Ǹ�
			for (int j = 1; j <= N; j++) {
				if (visited[j] == false && graph[K][j] < min_dis) {
					min_dis = graph[K][j];
					min_id = j;
				}
			}
			visited[min_id] = true;//���������Ϊ��ʹ�ù��ˡ�
			for (int j = 1; j <= N; j++) {//relax
				if (graph[K][min_id] + graph[min_id][j] < graph[K][j]) {
					graph[K][j] = graph[K][min_id] + graph[min_id][j];
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (graph[K][i] == INT_MAX) return -1;
			ans = max(ans, (int)graph[K][i]);
		}
		return ans;
	}
};



class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<vector<long long>> graph(N + 1, vector<long long>(N + 1, INT_MAX));
		for (int i = 1; i <= N; i++)    graph[i][i] = 0;
		for (auto e : times)    graph[e[0]][e[1]] = e[2];

		for (int k = 1; k <= N; k++)//k���������
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (graph[K][i] == INT_MAX) return -1;
			ans = max(ans, (int)graph[K][i]);
		}
		return ans;
	}
};



class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<vector<long long>> graph(N + 1, vector<long long>(N + 1, INT_MAX));
		for (int i = 1; i <= N; i++)    graph[i][i] = 0;
		for (auto e : times)    graph[e[0]][e[1]] = e[2];

		vector<int> disToK(N + 1, INT_MAX);
		queue<int> q;
		q.push(K); disToK[K] = 0;
		while (!q.empty()) {
			int front = q.front();    q.pop();
			for (int target = 1; target <= N; ++target) {//���Զ����еĵ����relax
				if (disToK[front] + graph[front][target] < disToK[target]) {
					disToK[target] = disToK[front] + graph[front][target];
					q.push(target);
				}
			}
		}

		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (disToK[i] == INT_MAX) return -1;
			ans = max(ans, disToK[i]);
		}
		return ans;

	}
};