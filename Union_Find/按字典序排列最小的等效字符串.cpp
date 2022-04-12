#include<bits/stdc++.h>
using namespace std;


class UNF {
public:
	vector<int>sz;
	vector<int>P;
	int part;
public:
	UNF(int N) {
		sz.resize(N, 1);
		P.resize(N);
		for (int i = 0; i < N; i++) {
			P[i] = i;
		}
		part = N;
	}
	int findP(int x) {
		if (x != P[x]) {
			P[x] = findP(P[x]);
		}
		return P[x];
	}
	bool relation(int x, int y) {
		int Px = findP(x);
		int Py = findP(y);
		if (Px == Py) {
			return false;
		}
		//这里合并两个不连通的分量时,以字典序小的优先;
		if (Px > Py) {
			P[Px] = Py;
			sz[Py] += sz[Px];
		}
		else {
			P[Py] = Px;
			sz[Px] += sz[Py];
		}
		part--;
		return true;
	}
	bool is_same_root(int x, int y) {
		int Pxx = findP(x);
		int Pyy = findP(y);
		if (Pxx == Pyy) {
			return true;
		}
		return false;
	}
	int get_sz(int x) {
		int Px = findP(x);
		return sz[Px];
	}
};
class Solution {
public:
	string smallestEquivalentString(string s1, string s2, string baseStr) {
		int N = s1.size();
		UNF unf(26);
		for (int i = 0; i < N; i++) {
			int v1 = s1[i] - 'a';
			int v2 = s2[i] - 'a';
			unf.relation(v1, v2);
		}
		string res = "";
		for (int i = 0; i < baseStr.size(); i++) {
			int c = unf.findP(baseStr[i] - 'a');
			res += ('a' + c);
		}
		return res;
	}
};

