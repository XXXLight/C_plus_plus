#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int P = 131, N = 100010;// 131,1331,13331
ULL h[N], p[N];
// unsign long long 会自动取模!!!!!!!如果ull类型的整数溢出了，就相当于取模2^64-1了。因为ull的范围是[0,2^64-1]。
ULL get(int l, int r) {
	if (l == 0) return h[r];// 特别l=0时返回h[r]，考虑边界情况
	return h[r] - h[l - 1] * p[r - l + 1];// 公式
}
void Init(string s) {
	int n = s.size();
	p[0] = 1;
	h[0] = s[0] - 'a' + 1;
	for (int i = 1; i < n; i++) {
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + s[i] - 'a' + 1;
	}
}
