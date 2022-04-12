#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res; // ���
		unordered_map<string, int> search;
		for (auto &word : words) ++search[word]; // �������ʼ��
		int n = s.size(), m = words.size(), len = words[0].size(); // ��ȡ���ر���
		for (int i = 0, j = 0; i < n - m * len + 1; ++i) { // ���߼�
			unordered_map<string, int> sub; // ���ַ� ���ҵ��м���
			for (j = 0; j < m; ++j) { // ���ַ��������߼�
				auto word = s.substr(i + j * len, len); // ��ȡ�Ӵ�
				if (!search.count(word)) break; // �Ӵ� ���� words ����
				if (++sub[word] > search[word]) break; // �Ӵ����� �� words ��
			}
			if (j == m) res.push_back(i); // ��ȫƥ��
		}
		return res;
	}
};

