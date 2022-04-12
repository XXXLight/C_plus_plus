#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int P = 131, N = 100010;
ULL h[N], p[N];
class Solution {
public:
	// unsign long long 会自动取模!!!!!!!如果ull类型的整数溢出了，就相当于取模2^64-1了。因为ull的范围是[0,2^64-1]。
	ULL get(int l, int r) {
		// 没有考虑l=0的情况，所以后面需要采取补空格的方法
		return h[r] - h[l - 1] * p[r - l + 1];
	}
	string longestPrefix(string s) {
		s = " " + s;// 防止i=0时候边界出错
		int n = s.size();
		p[0] = 1;
		for (int i = 1; i < n; i++) {
			p[i] = p[i - 1] * P;
			h[i] = h[i - 1] * P + s[i];
		}
		// for循环可以改写成while循环，要真正理解两者之间的等价变换
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
// unsign long long 会自动取模!!!!!!!如果ull类型的整数溢出了，就相当于取模2^64-1了。因为ull的范围是[0,2^64-1]。
ULL get(int l, int r) {
	if (l == 0) return h[r];// 特别l=0时返回h[r]，考虑边界情况
	return h[r] - h[l - 1] * p[r - l + 1];// 公式
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
		// [l1,r1]和[l2,r2]之间的字符串哈希值相同
		for (int l1 = 0, r1 = n - 2, l2 = 1, r2 = n - 1; l1 <= r1; r1--, l2++) {
			if (get(l1, r1) == get(l2, r2)) return s.substr(l1, r1 - l1 + 1);
		}
		return "";
	}
};





// string_view的介绍：https://www.cnblogs.com/yangxunwu1992/p/14018837.html
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





// KMP算法
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

