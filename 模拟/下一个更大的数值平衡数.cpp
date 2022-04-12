#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> permutation(string s) {
		vector<string> ans;
		sort(s.begin(), s.end());
		do {
			ans.push_back(s);
		} while (next_permutation(s.begin(), s.end()));

		return ans;
	}
	int nextBeautifulNumber(int n) {
		if (n == 0) return 1;
		if (n >= 1 && n < 21) return 22;
		vector<string> r1 = permutation("22");
		vector<string> r2 = permutation("122");
		vector<string> r3 = permutation("333");
		vector<string> r4 = permutation("1333");
		vector<string> r5 = permutation("4444");
		vector<string> r6 = permutation("14444");
		vector<string> r7 = permutation("22333");
		vector<string> r8 = permutation("55555");
		vector<string> r9 = permutation("122333");
		vector<string> r10 = permutation("224444");
		vector<string> r11 = permutation("155555");
		vector<string> r12 = permutation("666666");
		vector<string> r13 = permutation("1224444");
		vector<string> res;
		for (auto e : r1) res.push_back(e);
		for (auto e : r2) res.push_back(e);
		for (auto e : r3) res.push_back(e);
		for (auto e : r4) res.push_back(e);
		for (auto e : r5) res.push_back(e);
		for (auto e : r6) res.push_back(e);
		for (auto e : r7) res.push_back(e);
		for (auto e : r8) res.push_back(e);
		for (auto e : r9) res.push_back(e);
		for (auto e : r10) res.push_back(e);
		for (auto e : r11) res.push_back(e);
		for (auto e : r12) res.push_back(e);
		for (auto e : r13) res.push_back(e);
		sort(res.begin(), res.end(), [](string s1, string s2) {
			if (s1.size() != s2.size()) return s1.size() < s2.size();
			else {
				return s1 < s2;
			}
		});
		for (int i = 0; i < res.size() - 1; i++) {
			if (n >= stoi(res[i]) && n < stoi(res[i + 1]))
				return stoi(res[i + 1]);
		}
		return 0;
	}
};



class Solution {
public:
	bool ok(int n) {
		int C[10];
		for (int i = 0; i < 10; ++i) C[i] = 0;
		while (n > 0) {
			++C[n % 10];
			n /= 10;
		}
		for (int i = 0; i < 10; ++i) {
			if (C[i] && C[i] != i)   return 0;
		}
		return 1;
	}
	int nextBeautifulNumber(int n) {
		++n;
		while (!ok(n))   ++n;
		return n;
	}
};