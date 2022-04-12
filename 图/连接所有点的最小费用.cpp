#include<bits/stdc++.h>
using namespace std;
//https://blog.csdn.net/a2392008643/article/details/81781766


// Kruskal�㷨�ĺ���˼�룺̰��ѡ���Ȩ��С�ı�ֱ�����ж��㶼�ӽ���
// ���鼯ģ��
class DisjointSetUnion {
private:
	vector<int> f, rank;
	int n;

public:
	DisjointSetUnion(int _n) {
		n = _n;
		rank.resize(n, 1);
		f.resize(n);
		for (int i = 0; i < n; i++) {
			f[i] = i;
		}
	}

	int find(int x) {
		return f[x] == x ? x : f[x] = find(f[x]);
	}

	int unionSet(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) {
			return false;
		}
		if (rank[fx] < rank[fy]) {
			swap(fx, fy);
		}
		rank[fx] += rank[fy];
		f[fy] = fx;
		return true;
	}
};
// �ýṹ���ʾ��
struct Edge {
	int len, x, y;
	Edge(int len, int x, int y) : len(len), x(x), y(y) {
	}
};

class Solution {
public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		// ��dist�Զ������Ƶ��ɺ���
		auto dist = [&](int x, int y) -> int {
			return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
		};
		int n = points.size();
		DisjointSetUnion dsu(n);
		vector<Edge> edges;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				edges.emplace_back(dist(i, j), i, j);
			}
		}
		// ̰��ǰ������
		sort(edges.begin(), edges.end(), [](Edge a, Edge b) -> int { return a.len < b.len; });
		int ret = 0, num = 1;
		// �������еı�
		for (auto&[len, x, y] : edges) {
			// �����������֮��û����ͨ
			if (dsu.unionSet(x, y)) {
				ret += len;
				num++;
				// ���б�ȫ���������ˣ���1-nһ��n-1����
				if (num == n) {
					break;
				}
			}
		}
		return ret;
	}
};



class Solution {
public:
	struct edge {
		int s, e, w;
		edge(int a, int b, int c) :s(a), e(b), w(c) {}
		bool operator <(const edge& g) { return w < g.w; }
	};
	int find(int n) {
		if (fa[n] == n) return n;
		fa[n] = find(fa[n]);
		return fa[n];
	}
	vector<int> fa;
	vector<edge> nums;
	int minCostConnectPoints(vector<vector<int>>& points) {
		for (int i = 0; i < points.size(); i++) fa.push_back(i);
		for (int i = 0; i < points.size(); i++) {
			for (int j = i + 1; j < points.size(); j++) {
				nums.push_back(edge(i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])));
			}
		}
		sort(nums.begin(), nums.end());
		int cnt = 0, res = 0;
		for (int i = 0; i < nums.size(); i++) {
			int a = nums[i].s, b = nums[i].e, c = nums[i].w;
			int na = find(a), nb = find(b);
			if (na != nb) {
				cnt++;
				res += c;
				fa[na] = nb;
			}
			if (cnt == points.size() - 1) break;
		}
		return res;
	}
};


// prim�㷨
// Q1:dis����ĺ�����ʲô��
// A1:����u====������v֮���Ȩ����С�߾���
class Solution {
public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		int n = points.size(), res = 0, gra[1005][1005], dis[1005], flag[1005] = { 0 };
		memset(dis, 0x3f, sizeof dis);//memset���ܷ��ں���������
		for (int i = 0; i < points.size(); i++) {
			for (int j = 0; j < points.size(); j++) {
				gra[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
			}
		}
		// �ӵ㷨��flag��ʾ�ӵ�Ĺ��̣�����һ������n����
		for (int i = 0; i < n; i++) {
			int t = -1;
			for (int j = 0; j < n; j++) {
				// j=0ʱ��t=-1,t=j��ִ�У�t=0,������0��������Ǳ��ӽ����Ķ���
				if (!flag[j] && (t == -1 || dis[t] > dis[j])) t = j;
			}
			if (i) res += dis[t];
			flag[t] = 1; // �����ʾ�ӵ�Ĺ���
			for (int j = 0; j < n; j++) if (!flag[j]) dis[j] = min(dis[j], gra[t][j]);
		}
		return res;
	}
};



// prim���Դ���
// [[0,0],[2,2],[3,10],[5,2],[7,0]]
class Solution {
public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		int n = points.size(), res = 0, gra[5][5], dis[5], flag[5] = { 0 };
		memset(dis, 0x3f, sizeof dis);
		for (int i = 0; i < points.size(); i++) {
			for (int j = 0; j < points.size(); j++) {
				gra[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
			}
		}
		cout << "�������" << endl;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << gra[i][j] << " ";
			}
			cout << endl;
		}
		// �ӵ㷨��flag��ʾ�ӵ�Ĺ��̣�����һ������n����
		for (int i = 0; i < n; i++) {
			int t = -1;
			for (int i = 0; i < 5; i++) cout << dis[i] << " ";
			for (int j = 0; j < n; j++) {
				if (!flag[j] && (t == -1 || dis[t] > dis[j])) t = j;
			}
			cout << "ѡȡ���㣺";
			cout << t << " "; cout << endl;
			if (i) res += dis[t];
			flag[t] = 1;
			for (int j = 0; j < n; j++) if (!flag[j]) dis[j] = min(dis[j], gra[t][j]);
		}
		return res;
	}
};

class Solution {
public:
	const int inf = 0x3f;
	int gra[1000][1000];
	int Flag[1000];
	int dis[1000];
	int minCostConnectPoints(vector<vector<int>>& points) {
		memset(Flag, 0, sizeof Flag);// memset����д����ߣ�ֻ��д������
		memset(dis, inf, sizeof dis);
		int res = 0;
		int n = points.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				gra[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
			}
		}

		for (int i = 0; i < n; i++) {
			int t = -1;
			for (int j = 0; j < n; j++) {
				if (!Flag[j] && (t == -1 || dis[j] < dis[t])) t = j;
			}
			if (i) res += dis[t];
			Flag[t] = 1;
			for (int j = 0; j < n; j++) {
				if (!Flag[j]) dis[j] = min(dis[j], gra[t][j]);
			}
		}
		return res;
	}
};