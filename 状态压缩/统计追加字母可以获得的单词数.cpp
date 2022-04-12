#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


class Solution {
public:
	int wordCount(vector<string>& startWords, vector<string>& targetWords) {
		// 将 word 转化为表示包含字母状态的二进制整数
		auto mask = [](const string& word) -> int {
			int res = 0;
			for (char ch : word) {
				res |= 1 << (ch - 'a');
			}
			return res;
		};

		unordered_set<int> masks;   // 所有可以获得的状态
		for (const string& start : startWords) {
			// 遍历初始单词，根据其状态值构造所有可以获得的状态
			int msk = mask(start);
			for (int i = 0; i < 26; ++i) {
				if (((msk >> i) & 1) == 0) {
					masks.insert(msk | (1 << i));
				}
			}
		}
		int cnt = 0;   // 可以获得的单词数
		for (const string& target : targetWords) {
			if (masks.count(mask(target))) {
				++cnt;
			}
		}
		return cnt;
	}
};

