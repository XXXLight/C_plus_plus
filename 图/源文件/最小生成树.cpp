#include<bits/stdc++.h>
using namespace std;

// 牛客：https://www.nowcoder.com/practice/735a34ff4672498b95660f43b7fcd628?tpId=117&tqId=37869&rp=1&ru=%2Fta%2Fjob-code-high&qru=%2Fta%2Fjob-code-high%2Fquestion-ranking&tab=answerKey
// 最小生成树的理解：https://blog.csdn.net/a2392008643/article/details/81781766
// Kruskal：加边法  Prim：加点法

class Solution {
public:
	// 类可以写在类里面
	class UnionFind {
	private:
		vector<int> v;
	public:
		UnionFind(int n) :v(n, -1) {}
		int Find(int i) {
			return (v[i] == -1) ? i : (Find(v[i]));
		}
		void Union(int i, int j) {
			int x = Find(i);
			int y = Find(j);
			if (x != y) {
				v[x] = y;
			}
		}
		bool sameset(int i, int j) {
			return (Find(i) == Find(j));
		}
	};

	int miniSpanningTree(int n, int m, vector<vector<int> >& cost) {
		// write code here
		// 按照边的权值大小进行排序
		sort(cost.begin(), cost.end(),
			[](const vector<int>& a, const vector<int>& b)->bool {
			return a[2] < b[2];
		});
		UnionFind u(n + 1);
		int rtn = 0;//最小生成树的总边长
		int tmp = 0;//顶点个数
		for (vector<int>& v : cost) {
			int a = u.Find(v[0]);
			int b = u.Find(v[1]);
			if (a != b) {
				u.Union(a, b);
				rtn += v[2];
				tmp++;
				if (tmp == n - 1) {
					break;
				}
			}
		}
		return rtn;
	}
};