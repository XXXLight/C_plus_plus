#include<bits/stdc++.h>
using namespace std;

// û���뵽�ַ�������ѽ������

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		sort(strs.begin(), strs.end());
		string st = strs.front(), en = strs.back();
		int i, num = min(st.size(), en.size());
		for (i = 0; i < num && st[i] == en[i]; i++);  // �˴��ֺŲ����٣������٣�����
		return string(st, 0, i);
	}
};

//	����ȡ��һ�������һ��Ԫ�صĹ���ǰ׺����
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		sort(strs.begin(), strs.end());
		string st = strs[0];
		string en = strs[strs.size() - 1];
		int len = 0;
		for (int i = 0; i < st.size(); i++) {
			if (st[i] == en[i]) len++;
			else break;
		}
		return st.substr(0, len);
	}
};