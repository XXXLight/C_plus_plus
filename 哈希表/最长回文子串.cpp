#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	static const int p = 131;
	static const int N = 1005;
	typedef unsigned long long ull;
	ull sum1[N], sum2[N], pe[N];
	int n;
	ull gets(int l, int r) {
		return sum1[r + 1] - sum1[l] * pe[r + 1 - l];
	}
	ull getrs(int l, int r) {
		int tmp = l;
		l = n - r - 1;
		r = n - tmp - 1;
		return sum2[r + 1] - sum2[l] * pe[r + 1 - l];
	}
	bool check(int l, int r) {
		int m = (l + r) >> 1;
		if ((r - l) & 1) {
			if (gets(l, m) == getrs(m + 1, r))   return true;
			else    return false;
		}
		else {
			if (gets(l, m - 1) == getrs(m + 1, r))   return true;
			else    return false;
		}
	}
	string longestPalindrome(string s) {
		n = s.size();
		pe[0] = 1;
		for (int i = 0; i < s.size(); i++) {
			sum1[i + 1] = sum1[i] * p + s[i] - 'a' + 1;
			pe[i + 1] = pe[i] * p;
		}
		string rs = "";
		for (int i = s.size() - 1; i >= 0; i--)  rs += s[i];
		for (int i = 0; i < rs.size(); i++) {
			sum2[i + 1] = sum2[i] * p + rs[i] - 'a' + 1;
		}
		string ans = "";
		int flag = 0;
		for (int i = n; i >= 1; i--) {//���ȴӴ�ö�ٵ�С���ҵ�ֱ���˳�
			for (int j = 0; j < n - i + 1; j++) {
				if (check(j, j + i - 1)) {
					for (int k = j; k < j + i; k++) ans += s[k];
					flag = 1;
					break;
				}
			}
			if (flag)    break;
		}
		return ans;
	}
};





// �������㷨,���㷨�ĺ���˼��������֮ǰ��Ľ������������Ľ������������������֮��ǳ��������
// https://www.bilibili.com/video/BV187411B79Q?spm_id_from=333.337.search-card.all.click
// �벻�����������������ˣ�Ϊʲô������Ϊ������������̫�ࣩ
class Solution {
public:
	string longestPalindrome(string s) {
		string t("@#");
		for (const char& c : s) {
			t += c;
			t += '#';
		}
		t += '!';
		int n = t.size();
		vector<int> f(n, 0);
		// rmax��ʾ���ұ߽磬imax��ʾ���ұ߽�����Ӧ�����ĵ㣬maxidx���ԭʼ�ַ����������Ӵ�����߽磬maxlen���任���ַ����������İ뾶��Ҳ��ԭʼ�ַ����������Ӵ��ĳ���
		int imax = 0, rmax = 0, maxidx = 0, maxlen = 1;
		for (int i = 1; i < n; ++i) {
			f[i] = i <= rmax ? min(rmax - i + 1, f[2 * imax - i]) : 1;
			while (t[i + f[i]] == t[i - f[i]]) ++f[i];
			if (rmax < i + f[i] - 1) {
				rmax = i + f[i] - 1;
				imax = i;
			}
			if (maxlen < f[i] - 1) {
				maxlen = f[i] - 1;
				maxidx = (i - f[i]) / 2;//��t���±�תΪs��Ӧ�Ļ��Ĵ���ʼ�±�
			}
		}
		return s.substr(maxidx, maxlen);
	}
};