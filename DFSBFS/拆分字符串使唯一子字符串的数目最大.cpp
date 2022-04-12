#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

// ��׼�и�����

class Solution {
public:
	// Ψһ�뵽set
	unordered_set<string> st;
	int res = 0;
	void DFS(string s, int idx, int depth) {
		// �и�ַ�����β�����´�
		if (idx == s.size()) {
			res = max(res, depth);
		}
		// �и��[index,i]λ�õ��ַ���
		for (int i = idx; i < s.size(); i++) {
			string str = s.substr(idx, i - idx + 1);
			if (st.find(str) == st.end()) {
				st.insert(str);
				DFS(s, i + 1, depth + 1);
				st.erase(str);
			}
		}
	}
	int maxUniqueSplit(string s) {
		DFS(s, 0, 0);
		return res;
	}
};