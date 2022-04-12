#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int P = 131, N = 100010;
ULL h[N], p[N];
class Solution {
public:
	// unsign long long ���Զ�ȡģ!!!!!!!���ull���͵���������ˣ����൱��ȡģ2^64-1�ˡ���Ϊull�ķ�Χ��[0,2^64-1]��
	ULL get(int l, int r) {
		// û�п���l=0����������Ժ�����Ҫ��ȡ���ո�ķ���
		return h[r] - h[l - 1] * p[r - l + 1];
	}
	string longestPrefix(string s) {
		s = " " + s;// ��ֹi=0ʱ��߽����
		int n = s.size();
		p[0] = 1;
		for (int i = 1; i < n; i++) {
			p[i] = p[i - 1] * P;
			h[i] = h[i - 1] * P + s[i];
		}
		// forѭ�����Ը�д��whileѭ����Ҫ�����������֮��ĵȼ۱任
		for (int l1 = 1, r1 = n - 2, l2 = 2, r2 = n - 1; l1 <= r1; r1--, l2++) {
			if (get(l1, r1) == get(l2, r2)) return s.substr(l1, r1 - l1 + 1);
		}
		return "";
	}
};




#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int P = 131, N = 100010;
ULL h[N], p[N];
// unsign long long ���Զ�ȡģ!!!!!!!���ull���͵���������ˣ����൱��ȡģ2^64-1�ˡ���Ϊull�ķ�Χ��[0,2^64-1]��
ULL get(int l, int r) {
	if (l == 0) return h[r];// �ر�l=0ʱ����h[r]�����Ǳ߽����
	return h[r] - h[l - 1] * p[r - l + 1];// ��ʽ
}
void Init(string s) {
	int n = s.size();
	p[0] = 1;
	h[0] = s[0] - 'a';
	for (int i = 1; i < n; i++) {
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + s[i] - 'a';
	}
}
class Solution {
public:
	string longestPrefix(string s) {
		int n = s.size();
		Init(s);
		// [l1,r1]��[l2,r2]֮����ַ�����ϣֵ��ͬ
		for (int l1 = 0, r1 = n - 2, l2 = 1, r2 = n - 1; l1 <= r1; r1--, l2++) {
			if (get(l1, r1) == get(l2, r2)) return s.substr(l1, r1 - l1 + 1);
		}
		return "";
	}
};





// string_view�Ľ��ܣ�https://www.cnblogs.com/yangxunwu1992/p/14018837.html
class Solution {
public:
	string longestPrefix(string s) {
		int n = s.size();
		std::string_view view = s;
		int k;
		for (k = n - 1; k >= 1; k--) {
			if (view.substr(0, k) == view.substr(n - k, k))
				break;
		}
		if (k == 0)
			return "";
		else
			return s.substr(0, k);
	}
};





// KMP�㷨
class Solution {
public:
	string longestPrefix(string s) {
		int n = s.size();
		vector<int> fail(n, -1);
		for (int i = 1; i < n; ++i) {
			int j = fail[i - 1];
			while (j != -1 && s[j + 1] != s[i]) {
				j = fail[j];
			}
			if (s[j + 1] == s[i]) {
				fail[i] = j + 1;
			}
		}
		return s.substr(0, fail[n - 1] + 1);
	}
};

