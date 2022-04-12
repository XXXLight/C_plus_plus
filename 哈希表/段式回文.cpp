#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 10;
typedef unsigned long long ull;
ull p[N], h[N];
int base = 13331;
ull query(int l, int r) {
	return p[r] - p[l - 1] * h[r - l + 1];
}
class Solution {
public:
	int longestDecomposition(string text) {
		//匹配应该是贪心的，假如说第一个字符满足，第二个拆开也行
		int n = text.size();
		h[0] = 1, p[0] = 0;
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] * base + text[i];
			h[i + 1] = h[i] * base;
		}
		int ans = 0;
		for (int l1 = 0, r1 = 0, l2 = n - 1, r2 = n - 1; r1 <= l2; ) {
			while (r1 < l2 && query(l1 + 1, r1 + 1) != query(l2 + 1, r2 + 1)) r1++, l2--;
			if (r1 >= l2) {
				ans++;
				break;
			}
			if (query(l1 + 1, r1 + 1) == query(l2 + 1, r2 + 1)) ans += 2;
			r1++, l2--;
			l1 = r1, r2 = l2;
		}
		return ans;
	}
};

