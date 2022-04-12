#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	unordered_map<string, string> p;
	string find(string x) {
		if (p[x] != x) p[x] = find(p[x]);
		return p[x];
	}
	bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
		int n = sentence1.size(), m = sentence2.size();
		if (n != m) return false;
		for (auto& v : similarPairs) {
			string a = v[0], b = v[1];
			if (!p.count(a)) p[a] = a;
			if (!p.count(b)) p[b] = b;
			p[find(a)] = find(b);
		}
		for (int i = 0; i < n; i++) {
			string a = sentence1[i], b = sentence2[i];
			if ((!p.count(a) || !p.count(b)) && a != b) return false;
			if (p.count(a) && p.count(b) && find(a) != find(b)) return false;
		}
		return true;
	}
};

