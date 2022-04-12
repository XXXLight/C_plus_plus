#include<bits/stdc++.h>
using namespace std;


const int N = 3e4 + 10, P = 131;

typedef unsigned long long ULL;

class Solution {
private:
	string res = "";
	string s;
	int n;
	ULL h[N] = { 0 }, p[N] = { 0 };//h�洢�ַ�����ϣ��ǰ׺���飬p[i]��ʾP��i�η���ֵ
public:
	string longestDupSubstring(string s)
	{
		this->s = s;
		n = s.size();
		p[0] = 1;
		for (int i = 1; i <= n; i++)//�ַ�����ϣ��ǰ׺��
		{
			h[i] = h[i - 1] * P + s[i - 1];
			p[i] = p[i - 1] * P;
		}

		int l = 0, r = n;
		while (l < r)//���ֲ�����ظ���
		{
			int mid = l + r + 1 >> 1;
			if (check(mid)) l = mid;
			else r = mid - 1;
		}

		return res;
	}

	ULL get(int l, int r)//�������[l, r]�Ĺ�ϣֵ
	{
		return h[r] - h[l - 1] * p[r - l + 1];
	}

	bool check(int len)
	{
		unordered_set<ULL> S;//��¼��ϣֵ
		for (int i = len; i <= n; i++)
		{
			ULL num = get(i - len + 1, i);//�����ϣֵ
			if (S.count(num))//�����ظ���
			{
				res = s.substr(i - len, len);//�����ظ���������true
				return true;
			}
			else S.insert(num);//�����ϣ��
		}

		return false;//�������ظ���
	}
};

