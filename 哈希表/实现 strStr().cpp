#include<bits/stdc++.h>
using namespace std;


using ULL = unsigned long long;
const int base = 13331;
const int maxn = 5e4 + 50;
ULL h1[maxn], h2[maxn], f[maxn]; //h1 和 h2分别代表主串和模式串的哈希值
ULL get(int l, int r) {
	if (l == 0) return h1[r];
	return h1[r] - h1[l - 1] * f[r - l + 1];
}
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0) return 0;
		int n = haystack.size(), m = needle.size();
		f[0] = 1;
		for (int i = 1; i < max(m, n); i++) {
			f[i] = f[i - 1] * base;
		}
		for (int i = 0; i < n; i++) {
			if (i == 0) h1[i] = haystack[i];
			else h1[i] = h1[i - 1] * base + haystack[i];

		}
		for (int i = 0; i < m; i++) {
			if (i == 0) h2[i] = needle[i];
			else h2[i] = h2[i - 1] * base + needle[i];
		}
		for (int i = 0; i + m - 1 < n; i++) {
			// 长串的[i,i+m-1]和待匹配串的[0,m-1]长度都是m的字符串哈希值相同
			if (get(i, i + m - 1) == h2[m - 1]) {
				return i;
			}
		}
		return -1;
	}
};