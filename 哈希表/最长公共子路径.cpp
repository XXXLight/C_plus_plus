#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


class Solution {
public:
	using ull = uint64_t;
	ull b = 97755331, q = 2333;
	int longestCommonSubpath(int n, vector<vector<int>>& paths) {
		sort(begin(paths), end(paths), [](auto&& x, auto&& y) {return x.size() < y.size(); });
		for (auto&& xx : paths) for (auto&& x : xx) x ^= q;

		int minSize = paths.front().size(), pSize = paths.size();
		vector<ull> p(minSize + 1, 1);
		for (int i = 1; i <= minSize; ++i) p[i] = p[i - 1] * b;

		auto check = [&](int len) {
			unordered_set<ull> pass[2];
			ull sum = 0;
			for (int i = 0; i < len; ++i)
				sum = sum * b + paths[0][i];
			pass[0].insert(sum);
			for (int i = len; i < minSize; ++i) {
				sum = sum * b + paths[0][i] - paths[0][i - len] * p[len];
				pass[0].insert(sum);
			}
			for (int i = 1; i < pSize; ++i) {
				auto&& rear = pass[i & 1 ^ 1];
				auto&& now = pass[i & 1];
				auto&& path = paths[i];
				now.clear(); sum = 0;
				for (int i = 0; i < len; ++i)
					sum = sum * b + path[i];
				if (rear.count(sum))
					now.insert(sum);
				for (int i = len; i < path.size(); ++i) {
					sum = sum * b + path[i] - path[i - len] * p[len];
					if (rear.count(sum))
						now.insert(sum);
				}
				if (now.empty()) return false;
			}
			return true;
		};

		int l = 0, r = minSize;
		while (l < r) {
			int m = (l + r + 1) >> 1;
			if (check(m)) l = m;
			else r = m - 1;
		}
		return l;
	}
};

