#include<bits/stdc++.h>
using namespace std;


class Solution {
	// ���鼯ģ�壨��ϣ��д����
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
		maxSize = max(maxSize, size[y]); // ά����
		--groups;
	}

public:
	vector<int> groupStrings(vector<string> &words) {
		groups = words.size();
		for (auto &word : words) {
			int x = 0;
			for (char ch : word) {
				x |= 1 << (ch - 'a'); // ���� word �Ķ����Ʊ�ʾ
			}
			fa[x] = x;  // ��������鼯
			++size[x];
			maxSize = max(maxSize, size[x]); // ά����
			if (size[x] > 1) --groups;
		}

		for (auto &[x, _] : fa) { // ö�������ַ����������Ʊ�ʾ��
			for (int i = 0; i < 26; ++i) {
				merge(x, x ^ (1 << i)); // ��ӻ�ɾ���ַ� i
				if ((x >> i) & 1) {
					for (int j = 0; j < 26; ++j) {
						if (((x >> j) & 1) == 0) {
							merge(x, x ^ (1 << i) | (1 << j)); // �滻�ַ� i Ϊ j
						}
					}
				}
			}
		}
		return { groups, maxSize };
	}
};

