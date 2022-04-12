#include<bits/stdc++.h>
using namespace std;

// ţ�ͣ�https://www.nowcoder.com/practice/735a34ff4672498b95660f43b7fcd628?tpId=117&tqId=37869&rp=1&ru=%2Fta%2Fjob-code-high&qru=%2Fta%2Fjob-code-high%2Fquestion-ranking&tab=answerKey
// ��С����������⣺https://blog.csdn.net/a2392008643/article/details/81781766
// Kruskal���ӱ߷�  Prim���ӵ㷨

class Solution {
public:
	// �����д��������
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
		// ���ձߵ�Ȩֵ��С��������
		sort(cost.begin(), cost.end(),
			[](const vector<int>& a, const vector<int>& b)->bool {
			return a[2] < b[2];
		});
		UnionFind u(n + 1);
		int rtn = 0;//��С���������ܱ߳�
		int tmp = 0;//�������
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