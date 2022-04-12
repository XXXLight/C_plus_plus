#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
using ull = unsigned long long;
const int N = 1e5 + 10;
ull p[N], h[N];
int base = 1331;
ull query(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}
class Solution {
public:
	int distinctEchoSubstrings(string text) {
		//字符串哈希
		int n = text.size();
		unordered_set <ull> S;
		h[0] = 0, p[0] = 1;
		for (int i = 0; i < n; i++) {
			h[i + 1] = h[i] * base + text[i];
			p[i + 1] = p[i] * base;
		}
		for (int i = 2; i <= n; i += 2) {
			//枚举长度
			for (int j = 0; j + i <= n; j++) {
				//枚举起点
				int len = i / 2;
				ull a = query(j + 1, j + len), b = query(j + len + 1, j + 2 * len);
				if (a == b && !S.count(a)) {
					S.insert(a);
				}
			}
		}
		return S.size();
	}
};




// 根据模板编写
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int P = 1333331, N = 100010;
ULL h[N], p[N];
// unsign long long 会自动取模!!!!!!!如果ull类型的整数溢出了，就相当于取模2^64-1了。因为ull的范围是[0,2^64-1]。
ULL get(int l, int r) {
	if (l == 0) return h[r];// 特别l=0时返回h[r]，考虑边界情况
	return h[r] - h[l - 1] * p[r - l + 1];// 公式
}
void Init(string& s) {
	int n = s.size();
	p[0] = 1;
	h[0] = s[0] - 'a' + 1;
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + s[i] - 'a' + 1;
	}
}
class Solution {
public:
	int distinctEchoSubstrings(string text) {
		int len = text.size();
		int cnt = 0;
		Init(text);
		set<ULL> st;
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if ((j - i + 1) % 2 == 0) {
					int m = (i + j) / 2;
					ULL im = get(i, m), mj = get(m + 1, j);
					if (!st.count(im) && im == mj) {
						cnt++;
						st.insert(im);
					}

				}
			}
		}
		return cnt;
	}
};