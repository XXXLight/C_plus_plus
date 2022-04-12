#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int getf(vector<int>& f, int x) {
		if (f[x] == x) return x;
		int nf = getf(f, f[x]);
		f[x] = nf;
		return nf;
	}

	void add(vector<int>& f, int x, int y) {
		int fx = getf(f, x);
		int fy = getf(f, y);
		f[fx] = fy;
	}

	int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
		int n = source.size();
		vector<int> f(n);
		for (int i = 0; i < n; i++) {
			f[i] = i;
		}
		for (const auto& e : allowedSwaps) {
			add(f, e[0], e[1]);
		}

		unordered_map<int, unordered_multiset<int>> s, t; // Ϊÿ����ͨ��֧ά��λ�õļ���
		for (int i = 0; i < n; i++) {
			int fa = getf(f, i);
			s[fa].insert(source[i]);
			t[fa].insert(target[i]);
		}

		int ret = 0;
		for (int i = 0; i < n; i++) {
			if (s.find(i) == s.end()) continue;
			for (int x : s[i]) {
				if (t[i].find(x) == t[i].end()) {
					ret++;
				}
				else {
					// ����ʹ�� t[i].erase(x)����Ȼ��ɾ�����е� x
					t[i].erase(t[i].find(x));
				}
			}
		}
		return ret;
	}
};
