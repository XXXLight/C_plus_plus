#include<bits/stdc++.h>
using namespace std;


class UnionFind {
public:
	UnionFind(int n)
	{
		for (int i = 0; i < n; i++) {
			m_pre.emplace_back(i);
		}
	}

	~UnionFind()
	{
		m_pre.clear();
	}

	int GetFather(const int idx) {
		int r = idx;
		while (m_pre[r] != r) {
			r = m_pre[r];
		}

		int cur = idx;
		int upper;
		while (cur != r) {
			upper = m_pre[cur];
			m_pre[cur] = r;
			cur = upper;
		}

		return r;
	}

	void UninSet(const int a, const int b) {
		int af = GetFather(a);
		int bf = GetFather(b);

		if (af == bf) {
			return;
		}

		if (af > bf) {
			swap(af, bf);
		}

		m_pre[bf] = af;
	}
private:
	vector<int> m_pre;
};

class Solution {
public:
	struct Vertex {
		int i;
		int j;
		int val;
		bool operator<(const Vertex& rhs) const { return val < rhs.val; }
	};

	int maximumMinimumPath(vector<vector<int>>& A)
	{
		int rn = A.size();
		int cn = A[0].size();

		const vector<pair<int, int>> dirs = { {0,1},{0,-1},{-1,0},{1,0} };
		UnionFind uf(rn * cn);

		int maxVal = min(A[0][0], A[rn - 1][cn - 1]);
		priority_queue<Vertex> myQ;
		vector<vector<int>> coloredSet(rn, vector<int>(cn, 0));

		for (int i = 0; i < rn; ++i) {
			for (int j = 0; j < cn; ++j) {
				myQ.push({ i,j,A[i][j] });
			}
		}

		while (uf.GetFather(0) != uf.GetFather(rn * cn - 1)) {
			Vertex node = myQ.top();
			myQ.pop();
			auto x = node.i;
			auto y = node.j;

			maxVal = min(node.val, maxVal);
			coloredSet[x][y] = 1;
			for (auto& dir : dirs) {
				int nx = x + dir.first;
				int ny = y + dir.second;

				if (nx < 0 || nx >= rn || ny < 0 || ny >= cn ||
					coloredSet[nx][ny] == 0) {
					continue;
				}
				uf.UninSet(x * cn + y, nx * cn + ny);
			}
		}

		return maxVal;
	}
};

