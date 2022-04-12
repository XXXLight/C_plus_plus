#include<bits/stdc++.h>
using namespace std;

// DFS传递引用
class Solution {
public:
	int ans = 0;
	int maxProduct(string s) {
		string s1, s2;
		dfs(s, s1, s2, 0);
		return ans;
	}

	void dfs(string &s, string &s1, string &s2, int index) {
		if (check(s1) && check(s2)) ans = max(ans, int(s1.size() * s2.size()));
		if (index == s.size()) return;
		s1.push_back(s[index]);
		dfs(s, s1, s2, index + 1);
		s1.pop_back();
		s2.push_back(s[index]);
		dfs(s, s1, s2, index + 1);
		s2.pop_back();
		dfs(s, s1, s2, index + 1);
	}

	bool check(string &s) {
		int l = 0, r = s.size() - 1;
		while (l < r) {
			if (s[l++] != s[r--]) return false;
		}
		return true;
	}
};


// DFS传值
class Solution {
public:
	int ans = 0;
	int maxProduct(string s) {
		string s1, s2;
		dfs(s, s1, s2, 0);
		return ans;
	}
	// 不变的可以传引用
	void dfs(string &s, string s1, string s2, int index) {
		if (check(s1) && check(s2)) ans = max(ans, int(s1.size() * s2.size()));
		if (index == s.size()) return;
		// 注意对下面这句话的理解，一共有四种情况，s1使用，s2使用(与题意不符)；s1不使用，s2使用；
		// s1使用，s2不使用；s1不使用，s2不使用
		dfs(s, s1 + s[index], s2, index + 1);//子序列s1使用该字符，s2没有使用
		dfs(s, s1, s2 + s[index], index + 1);//子序列s2使用该字符，s1没有使用
		dfs(s, s1, s2, index + 1);//子序列都不使用该字符
	}
	// 判断回文,不传引用会超时
	bool check(string &s) {
		int l = 0, r = s.size() - 1;
		while (l < r) {
			if (s[l++] != s[r--]) return false;
		}
		return true;
	}
};


// 状态压缩
class Solution {
public:
	// 定义 PII
	using PII = std::pair<int, int>;
	bool check(string& s, int state) {
		int left = 0, right = s.length() - 1;
		while (left < right) {
			// state的left位上是0，表示不选择left位，指针移动，直接跳过
			while (left < right && (state & (1 << left)) == 0) {
				left++;
			}
			// state的right位上是0，表示不选择right位，指针移动，直接跳过
			while (left < right && (state & (1 << right)) == 0) {
				right--;
			}
			if (s[left] != s[right]) {
				return false;
			}
			left++;
			right--;
		}

		return true;
	}

	int maxProduct(string s) {
		int n = s.length(), m = 1 << n;
		vector<PII> list;

		for (int i = 1; i < m; i++) {
			if (check(s, i)) {
				// __builtin_popcount 内置函数，用于统计数字二进制中 1 的个数
				list.emplace_back(i, __builtin_popcount(i));
			}
		}
		int cnt = 0;
		for (auto e : list) {
			cout << (bitset<11>)e.first << " " << e.second << endl; // 输出 00001010
		}
		int res = 0, len = list.size();
		for (int i = 0; i < len; i++) {
			int x = list[i].first, len_x = list[i].second;
			for (int j = i + 1; j < len; j++) {
				int y = list[j].first, len_y = list[j].second;
				// (x&y)==0表示两个子序列不相交
				if ((x & y) == 0) {
					res = std::max(res, len_x * len_y);
				}
			}
		}

		return res;
	}
};



