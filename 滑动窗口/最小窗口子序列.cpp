#include<bits/stdc++.h>
using namespace std;

// ע����������˳��Ҫ���
class Solution {
public:
	string minWindow(string s1, string s2) {
		// p��q����ƥ��s1��s2��pָ��s1,qָ��s2,left��right�������´��ڳ��ȵ�
		int n = s1.length(), m = s2.length(), p = 0, q = 0, left = 0, right = 0, minlen = INT_MAX;
		string ans = "";
		while (p < n) {
			if (s1[p] == s2[q])q++;// �ַ�ƥ�䣬ָ���ƶ�
			// q==m��ʾ�ɹ�ƥ�䣬�������
			if (q == m) {
				right = p;
				q--;
				while (q >= 0) {
					if (s1[p] == s2[q])q--;
					p--;
				}
				left = ++p;
				q = 0;
				if ((right - left + 1) < minlen) {
					ans = s1.substr(left, right - left + 1);
					minlen = right - left + 1;
				}
			}
			p++;
		}
		return ans;
	}
};