#include<bits/stdc++.h>
using namespace std;


class Solution {
	// 并查集模板（哈希表写法）
	unordered_map<int, int> fa, size;
	int groups, maxSize = 0;

	int find(int x) {
		return fa[x] != x ? fa[x] = find(fa[x]) : x;
	}

	void merge(int x, int y) {
		if (!fa.count(y)) return;
		x = find(x);
		y = find(y);
		if (x == y) return;
		fa[x] = y;
		size[y] += size[x];
		maxSize = max(maxSize, size[y]); // 维护答案
		--groups;
	}

public:
	vector<int> groupStrings(vector<string> &words) {
		groups = words.size();
		for (auto &word : words) {
			int x = 0;
			for (char ch : word) {
				x |= 1 << (ch - 'a'); // 计算 word 的二进制表示
			}
			fa[x] = x;  // 添加至并查集
			++size[x];
			maxSize = max(maxSize, size[x]); // 维护答案
			if (size[x] > 1) --groups;
		}

		for (auto &[x, _] : fa) { // 枚举所有字符串（二进制表示）
			for (int i = 0; i < 26; ++i) {
				merge(x, x ^ (1 << i)); // 添加或删除字符 i
				if ((x >> i) & 1) {
					for (int j = 0; j < 26; ++j) {
						if (((x >> j) & 1) == 0) {
							merge(x, x ^ (1 << i) | (1 << j)); // 替换字符 i 为 j
						}
					}
				}
			}
		}
		return { groups, maxSize };
	}
};

