#include<bits/stdc++.h>
using namespace std;


const int N = 3e4 + 10, P = 131;

typedef unsigned long long ULL;

class Solution {
private:
	string res = "";
	string s;
	int n;
	ULL h[N] = { 0 }, p[N] = { 0 };//h存储字符串哈希的前缀数组，p[i]表示P的i次方的值
public:
	string longestDupSubstring(string s)
	{
		this->s = s;
		n = s.size();
		p[0] = 1;
		for (int i = 1; i <= n; i++)//字符串哈希的前缀和
		{
			h[i] = h[i - 1] * P + s[i - 1];
			p[i] = p[i - 1] * P;
		}

		int l = 0, r = n;
		while (l < r)//二分查找最长重复串
		{
			int mid = l + r + 1 >> 1;
			if (check(mid)) l = mid;
			else r = mid - 1;
		}

		return res;
	}

	ULL get(int l, int r)//求出区间[l, r]的哈希值
	{
		return h[r] - h[l - 1] * p[r - l + 1];
	}

	bool check(int len)
	{
		unordered_set<ULL> S;//记录哈希值
		for (int i = len; i <= n; i++)
		{
			ULL num = get(i - len + 1, i);//求出哈希值
			if (S.count(num))//存在重复串
			{
				res = s.substr(i - len, len);//更新重复串并返回true
				return true;
			}
			else S.insert(num);//加入哈希表
		}

		return false;//不存在重复串
	}
};

