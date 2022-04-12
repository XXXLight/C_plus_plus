#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		int sLen = strlen(s), sIndex = 0;
		int pLen = strlen(p), pIndex = 0;
		int ppre = 0, ipre = 0;
		bool flag = false;
		while (sIndex < sLen) {
			if (s[sIndex] == p[pIndex] || p[pIndex] == '?') {
				++sIndex, ++pIndex;
			}
			else if (p[pIndex] == '*') {    //��������¼*���濪ʼƥ�������
				ppre = ++pIndex;
				ipre = sIndex;            //��¼s�п�ʼ��*����ƥ�������
				flag = true;
			}
			else {
				if (flag) {                //�޷�ƥ�䣬�ڳ���*�������*�ֲ�
					sIndex = ++ipre;
					pIndex = ppre;
				}
				else {
					return false;
				}
			}
		}
		while (p[pIndex] == '*') {          //��ʣ���*ƥ���
			++pIndex;
		}
		return pIndex == pLen && sIndex == sLen;
	}
};


class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		const char* star = NULL;
		const char* ss = s;
		while (*s) {
			if ((*p == '?') || (*p == *s)) { s++; p++; continue; }
			if (*p == '*') { star = p++; ss = s; continue; }
			if (star) { s = ++ss; p = star + 1; continue; }
			return false;
		}
		while (*p == '*') { p++; }
		return !*p;
	}
};