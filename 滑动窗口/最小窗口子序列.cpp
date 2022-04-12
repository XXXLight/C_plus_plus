#include<bits/stdc++.h>
using namespace std;

// 注意这里是有顺序要求的
class Solution {
public:
	string minWindow(string s1, string s2) {
		// p、q用来匹配s1和s2，p指向s1,q指向s2,left和right用来更新窗口长度的
		int n = s1.length(), m = s2.length(), p = 0, q = 0, left = 0, right = 0, minlen = INT_MAX;
		string ans = "";
		while (p < n) {
			if (s1[p] == s2[q])q++;// 字符匹配，指针移动
			// q==m表示成功匹配，逆向回来
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