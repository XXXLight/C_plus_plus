#include<bits/stdc++.h>
using namespace std;


#define lson (idx << 1)
#define rson (idx << 1 | 1)
#define MAXN 100005

typedef long long ll;
const int INF = 0x3f3f3f3f;

struct Node {
	int l, r, v, lazy;
} s[MAXN << 2];

void calc(int idx) { s[idx].v = min(s[lson].v, s[rson].v); }

void build(int idx, int l, int r) {
	s[idx].l = l, s[idx].r = r, s[idx].v = INF, s[idx].lazy = 0;
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
}

void pushdown(int idx) {
	if (s[idx].lazy)
		for (int i = lson; i <= rson; ++i) {
			s[i].v += s[idx].lazy;
			s[i].lazy += s[idx].lazy;
		}
	s[idx].lazy = 0;
}

void setp(int idx, int pos, int x) {
	if (s[idx].l == pos && s[idx].r == pos) {
		s[idx].v = x;
		return;
	}
	pushdown(idx);
	int mid = (s[idx].l + s[idx].r) >> 1;
	if (pos <= mid)
		setp(lson, pos, x);
	else
		setp(rson, pos, x);
	calc(idx);
}

void update(int idx, int l, int r, int x) {
	if (s[idx].l >= l && s[idx].r <= r) {
		s[idx].v += x;
		s[idx].lazy += x;
		return;
	}
	pushdown(idx);
	int mid = (s[idx].l + s[idx].r) >> 1;
	if (mid >= l)
		update(lson, l, r, x);
	if (mid + 1 <= r)
		update(rson, l, r, x);
	calc(idx);
}

int query(int idx, int l, int r) {
	if (s[idx].l >= l && s[idx].r <= r)
		return s[idx].v;
	pushdown(idx);
	int mid = (s[idx].l + s[idx].r) >> 1;
	int ans = INF;
	if (mid >= l)
		ans = min(ans, query(lson, l, r));
	if (mid + 1 <= r)
		ans = min(ans, query(rson, l, r));
	return ans;
}

class Solution {
public:
	int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight) {
		int n = boxes.size();
		if (n == 1)
			return 2;
		vector<ll> w(n + 1);
		for (int i = 1; i <= n; ++i)
			w[i] = w[i - 1] + boxes[i - 1][1];
		build(1, 1, n);

		vector<int> dp(n + 1);
		auto valid = [&](int l, int r) {
			return r - l + 1 <= maxBoxes && w[r] - w[l - 1] <= maxWeight;
		};
		int l = 1;
		for (int i = 1; i <= n; ++i) {
			while (l < i && !valid(l, i))
				l++;
			int lo = dp[i - 1] + 2;
			if (l < i)
				lo = min(lo, query(1, l, i - 1));
			dp[i] = lo;
			setp(1, i, dp[i - 1] + 2);
			if (i < n && boxes[i][0] != boxes[i - 1][0])
				update(1, l, i, 1);
		}
		return dp[n];
	}
};

