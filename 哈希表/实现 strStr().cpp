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





//	https://www.zhihu.com/question/21923021/answer/281346746
class Solution {
public:
// i 指向后缀末尾
// j 指向前缀末尾
	vector<int> Getnext(string s)
	{
		int len = s.size();
		vector<int> next(len + 1);//多分配一个空间，下面是++i，++j不然数组下标越界
		int j = -1, i = 0;
		next[0] = -1;
		while (i < len)
		{
			if (j == -1 || s[i] == s[j])
			{
				++i;
				++j;
				next[i] = j;//next[1]必为0
			}
			else
			{
				j = next[j];//找next数组就是模式串前后缀自匹配，如果失败就回溯,回溯看的不就是自己的next下标，所以才有这个等式
			}

		}
		return next;
	}
	int strStr(string haystack, string needle)
	{
		int len1 = haystack.size();
		int len2 = needle.size();
		if (len2 == 0) return 0;
		vector<int> next = Getnext(needle);//拿到next数组
		int j = 0, i = 0;
		while (i < len1&&j < len2)
		{
			if (j == -1 || haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else {
				j = next[j];
			}
		}
		if (j >= len2)
		{
			return i - len2;
		}
		else {
			return -1;
		}
	}
};