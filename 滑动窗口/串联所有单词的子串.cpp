#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res; // 结果
		unordered_map<string, int> search;
		for (auto &word : words) ++search[word]; // 参照物初始化
		int n = s.size(), m = words.size(), len = words[0].size(); // 获取隐藏变量
		for (int i = 0, j = 0; i < n - m * len + 1; ++i) { // 主逻辑
			unordered_map<string, int> sub; // 子字符 查找的中间结果
			for (j = 0; j < m; ++j) { // 子字符串查找逻辑
				auto word = s.substr(i + j * len, len); // 获取子串
				if (!search.count(word)) break; // 子串 不在 words 里面
				if (++sub[word] > search[word]) break; // 子串个数 比 words 多
			}
			if (j == m) res.push_back(i); // 完全匹配
		}
		return res;
	}
};

