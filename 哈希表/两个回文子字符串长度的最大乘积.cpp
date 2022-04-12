#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int P = 131, N = 100010;// 131,1331,13331
ULL h[N], p[N], h1[N], p1[N];
// unsign long long 会自动取模!!!!!!!如果ull类型的整数溢出了，就相当于取模2^64-1了。因为ull的范围是[0,2^64-1]。
ULL get(int l, int r) {
	if (l == 0) return h[r];// 特别l=0时返回h[r]，考虑边界情况
	return h[r] - h[l - 1] * p[r - l + 1];// 公式
}
ULL get1(int l, int r) {
	if (l == 0) return h1[r];// 特别l=0时返回h[r]，考虑边界情况
	return h1[r] - h1[l - 1] * p1[r - l + 1];// 公式
}
void Init(string s) {
	int n = s.size();
	p[0] = 1;
	h[0] = s[0] - 'a' + 3;
	for (int i = 1; i < n; i++) {
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + s[i] - 'a' + 3;
	}
}
void Init1(string s1) {
	int n = s1.size();
	p1[0] = 1;
	h1[0] = s1[0] - 'a' + 3;
	for (int i = 1; i < n; i++) {
		p1[i] = p1[i - 1] * P;
		h1[i] = h1[i - 1] * P + s1[i] - 'a' + 3;
	}
}


// 该算法不适用于偶数长度的回文串
class Solution {
public:
	long long maxProduct(string s) {
		int n = s.size();
		string revS = s;
		reverse(s.begin(), s.end());
		Init(s);
		Init1(revS);
		vector<int> span(s.size(), 1);
		for (int i = 1; i < n; i++) {
			int l = i + 1, r = n;
			while (l <= r) {
				int m = (l + r) / 2;
				if (2 * i - m >= 0 && get1(i + 1, m) == get(n - i, n - 2 * i + m - 1)) {
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
			span[i] = l - i;
		}
		vector<int> pre(n), suf(n);
		for (int i = 0; i < n; ++i) {
			pre[i + span[i] - 1] = max(pre[i + span[i] - 1], span[i] * 2 - 1);
			suf[i - span[i] + 1] = max(suf[i - span[i] + 1], span[i] * 2 - 1);
		}
		// for(auto e:pre) cout<<e<<" ";
		// cout<<endl;
		for (int i = 1; i < n; ++i) {
			pre[i] = max(pre[i], pre[i - 1]);
		}
		// for(auto e:pre) cout<<e<<" ";
		// cout<<endl;
		for (int i = n - 2; i >= 0; --i) {
			pre[i] = max(pre[i], pre[i + 1] - 2);
		}
		// for(auto e:pre) cout<<e<<" ";
		// cout<<endl;
		for (int i = n - 2; i >= 0; --i) {
			suf[i] = max(suf[i], suf[i + 1]);
		}
		for (int i = 1; i < n; ++i) {
			suf[i] = max(suf[i], suf[i - 1] - 2);
		}
		long long ans = 0;
		for (int i = 0; i < n - 1; ++i) {
			ans = max(ans, (long long)pre[i] * suf[i + 1]);
		}
		return ans;
	}
};






// 马拉车
class Solution {
public:
	long long maxProduct(string s) {
		int n = s.size();
		vector<int> span(n);

		// manacher
		for (int i = 0, l = 0, r = -1; i < n; ++i) {
			span[i] = i <= r ? min(span[l + r - i], r - i + 1) : 1;
			while (i - span[i] >= 0 && i + span[i] < n && s[i - span[i]] == s[i + span[i]]) {
				++span[i];
			}
			if (i + span[i] - 1 > r) {
				l = i - span[i] + 1;
				r = i + span[i] - 1;
			}
		}

		vector<int> pre(n), suf(n);
		for (int i = 0; i < n; ++i) {
			pre[i + span[i] - 1] = max(pre[i + span[i] - 1], span[i] * 2 - 1);
			suf[i - span[i] + 1] = max(suf[i - span[i] + 1], span[i] * 2 - 1);
		}

		for (int i = 1; i < n; ++i) {
			pre[i] = max(pre[i], pre[i - 1]);
		}
		for (int i = n - 2; i >= 0; --i) {
			pre[i] = max(pre[i], pre[i + 1] - 2);
		}
		for (int i = n - 2; i >= 0; --i) {
			suf[i] = max(suf[i], suf[i + 1]);
		}
		for (int i = 1; i < n; ++i) {
			suf[i] = max(suf[i], suf[i - 1] - 2);
		}

		long long ans = 0;
		for (int i = 0; i < n - 1; ++i) {
			ans = max(ans, (long long)pre[i] * suf[i + 1]);
		}
		return ans;
	}
};

