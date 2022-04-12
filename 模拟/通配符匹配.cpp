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
			else if (p[pIndex] == '*') {    //跳过并记录*后面开始匹配的索引
				ppre = ++pIndex;
				ipre = sIndex;            //记录s中开始与*后面匹配的索引
				flag = true;
			}
			else {
				if (flag) {                //无法匹配，在出现*情况下用*弥补
					sIndex = ++ipre;
					pIndex = ppre;
				}
				else {
					return false;
				}
			}
		}
		while (p[pIndex] == '*') {          //将剩余的*匹配掉
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