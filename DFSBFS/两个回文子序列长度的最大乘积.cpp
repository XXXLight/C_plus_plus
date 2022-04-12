#include<bits/stdc++.h>
using namespace std;

// DFS��������
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


// DFS��ֵ
class Solution {
public:
	int ans = 0;
	int maxProduct(string s) {
		string s1, s2;
		dfs(s, s1, s2, 0);
		return ans;
	}
	// ����Ŀ��Դ�����
	void dfs(string &s, string s1, string s2, int index) {
		if (check(s1) && check(s2)) ans = max(ans, int(s1.size() * s2.size()));
		if (index == s.size()) return;
		// ע���������仰����⣬һ�������������s1ʹ�ã�s2ʹ��(�����ⲻ��)��s1��ʹ�ã�s2ʹ�ã�
		// s1ʹ�ã�s2��ʹ�ã�s1��ʹ�ã�s2��ʹ��
		dfs(s, s1 + s[index], s2, index + 1);//������s1ʹ�ø��ַ���s2û��ʹ��
		dfs(s, s1, s2 + s[index], index + 1);//������s2ʹ�ø��ַ���s1û��ʹ��
		dfs(s, s1, s2, index + 1);//�����ж���ʹ�ø��ַ�
	}
	// �жϻ���,�������ûᳬʱ
	bool check(string &s) {
		int l = 0, r = s.size() - 1;
		while (l < r) {
			if (s[l++] != s[r--]) return false;
		}
		return true;
	}
};


// ״̬ѹ��
class Solution {
public:
	// ���� PII
	using PII = std::pair<int, int>;
	bool check(string& s, int state) {
		int left = 0, right = s.length() - 1;
		while (left < right) {
			// state��leftλ����0����ʾ��ѡ��leftλ��ָ���ƶ���ֱ������
			while (left < right && (state & (1 << left)) == 0) {
				left++;
			}
			// state��rightλ����0����ʾ��ѡ��rightλ��ָ���ƶ���ֱ������
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
				// __builtin_popcount ���ú���������ͳ�����ֶ������� 1 �ĸ���
				list.emplace_back(i, __builtin_popcount(i));
			}
		}
		int cnt = 0;
		for (auto e : list) {
			cout << (bitset<11>)e.first << " " << e.second << endl; // ��� 00001010
		}
		int res = 0, len = list.size();
		for (int i = 0; i < len; i++) {
			int x = list[i].first, len_x = list[i].second;
			for (int j = i + 1; j < len; j++) {
				int y = list[j].first, len_y = list[j].second;
				// (x&y)==0��ʾ���������в��ཻ
				if ((x & y) == 0) {
					res = std::max(res, len_x * len_y);
				}
			}
		}

		return res;
	}
};



