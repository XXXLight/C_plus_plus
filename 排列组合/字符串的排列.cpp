#include<bits/stdc++.h>
using namespace std;

//�����������𣿣�����
//  {a,b,c}��ȫ���У�abc��acb��bac��bca��cab��cba
//  1.abcû��prev_permutation��cbaû��next_permutation
//  2.���ɵ�ȫ�����ǰ����ֵ�˳��������е�
class Solution {
public:
	vector<string> permutation(string s) {
		vector<string> ans;
		// sort�Ժ����ĸ���ֵ�����С����ĸ����������next_permutation�ģ����Ա����������
		sort(s.begin(), s.end());
		do {
			ans.push_back(s);
		} while (next_permutation(s.begin(), s.end()));
		return ans;
	}
};



class Solution {
public:
	vector<string> res;
	set<string> st;
	// ���������봫���ã�����
	// ������ʱ�������봫��ȥ
	void backtrack(string& s, string& tmp, int depth) {
		if (depth == s.size()) {
			res.push_back(tmp);
			return;
		}
		for (int i = depth; i < s.size(); i++) {
			swap(s[i], s[depth]);
			backtrack(s, tmp, depth + 1);
			swap(s[i], s[depth]);
		}
	}
	vector<string> permutation(string s) {
		backtrack(s, s, 0);
		// ȥ��
		for (auto e : res) st.insert(e);
		res.clear();
		for (auto e : st) res.push_back(e);
		return res;
	}
};