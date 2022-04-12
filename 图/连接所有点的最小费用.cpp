#include<bits/stdc++.h>
using namespace std;
//https://blog.csdn.net/a2392008643/article/details/81781766


// Kruskal算法的核心思想：贪心选择边权较小的边直到所有顶点都加进来
// 并查集模板
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
// 用结构体表示边
struct Edge {
	int len, x, y;
	Edge(int len, int x, int y) : len(len), x(x), y(y) {
	}
};

class Solution {
public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		// 将dist自动类型推导成函数
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
		// 贪心前先排序
		sort(edges.begin(), edges.end(), [](Edge a, Edge b) -> int { return a.len < b.len; });
		int ret = 0, num = 1;
		// 遍历所有的边
		for (auto&[len, x, y] : edges) {
			// 如果两个顶点之间没有连通
			if (dsu.unionSet(x, y)) {
				ret += len;
				num++;
				// 所有边全部都包含了，从1-n一共n-1条边
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


// prim算法
// Q1:dis数组的含义是什么？
// A1:集合u====》集合v之间边权的最小边距离
class Solution {
public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		int n = points.size(), res = 0, gra[1005][1005], dis[1005], flag[1005] = { 0 };
		memset(dis, 0x3f, sizeof dis);//memset不能放在函数外类内
		for (int i = 0; i < points.size(); i++) {
			for (int j = 0; j < points.size(); j++) {
				gra[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
			}
		}
		// 加点法，flag表示加点的过程，所以一共加了n个点
		for (int i = 0; i < n; i++) {
			int t = -1;
			for (int j = 0; j < n; j++) {
				// j=0时，t=-1,t=j被执行，t=0,这样第0个顶点就是被加进来的顶点
				if (!flag[j] && (t == -1 || dis[t] > dis[j])) t = j;
			}
			if (i) res += dis[t];
			flag[t] = 1; // 这里表示加点的过程
			for (int j = 0; j < n; j++) if (!flag[j]) dis[j] = min(dis[j], gra[t][j]);
		}
		return res;
	}
};



// prim调试代码
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
		cout << "距离矩阵" << endl;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << gra[i][j] << " ";
			}
			cout << endl;
		}
		// 加点法，flag表示加点的过程，所以一共加了n个点
		for (int i = 0; i < n; i++) {
			int t = -1;
			for (int i = 0; i < 5; i++) cout << dis[i] << " ";
			for (int j = 0; j < n; j++) {
				if (!flag[j] && (t == -1 || dis[t] > dis[j])) t = j;
			}
			cout << "选取顶点：";
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
		memset(Flag, 0, sizeof Flag);// memset不能写在外边，只能写在里面
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