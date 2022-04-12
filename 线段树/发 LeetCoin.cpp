#include<bits/stdc++.h>
using namespace std;


using ll = long long;
const ll M = 1e9 + 7;

class BIT {
public:
	int n;
	vector<ll> sum;
	vector<ll> ntimessum;

	BIT(int _n) : n(_n + 5), sum(_n + 10, 0), ntimessum(_n + 10, 0) {}
	ll lowbit(ll x) {
		return x & (-x);
	}

	void update(int pos, ll k) { // �� pos λ�ü��� k
		ll x = pos;
		while (pos <= n) {
			sum[pos] += k;
			ntimessum[pos] += k * (x - 1);
			pos += lowbit(pos);
		}
	}

	void update_internal(int l, int r, int k) { // �������
		update(l, k);
		update(r + 1, -k);
	}

	ll askis(int pos) { // ������� + �����ѯ 
		if (!pos) return 0;
		ll ret = 0;
		while (pos) {
			ret += sum[pos];
			pos -= lowbit(pos);
		}
		return ret;
	}

	ll asksi(int l, int r) { // ������� + �����ѯ
		if (l > r) {
			return 0;
		}
		return askis(r) - askis(l - 1);
	}

	ll askss(int pos) {	// ������� + �����ѯ
		return askis(pos) - askis(pos - 1);
	}

	ll askii(int pos) { // ������� + ��Χ��ѯ
		if (!pos) return 0;
		ll ret = 0, x = pos;
		while (pos) {
			ret += x * sum[pos] - ntimessum[pos];
			pos -= lowbit(pos);
		}
		return ret;
	}

	ll asklr(int l, int r) { // ������� + �����ѯ
		return askii(r) - askii(l - 1);
	}
};

class Solution {
public:
	int id = 1;

	void dfs(int cur, vector<int>& begin, vector<int>& end, vector<vector<int>>& g) {
		begin[cur] = id;
		for (auto &child : g[cur]) dfs(child, begin, end, g);
		end[cur] = id;
		id++;
	}

	vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
		// �ڽӱ�
		vector<vector<int>> g(n + 1);
		for (auto &l : leadership) g[l[0]].push_back(l[1]);

		// ���ѣ�����
		vector<int> begin(n + 1), end(n + 1);
		dfs(1, begin, end, g);

		// ��״����
		BIT *b = new BIT(n);
		vector<int> ret;
		for (auto &q : operations) {
			if (q[0] == 1) {
				b->update_internal(end[q[1]], end[q[1]], q[2]);
			}
			else if (q[0] == 2) {
				b->update_internal(begin[q[1]], end[q[1]], q[2]);
			}
			else {
				ll ans = b->asklr(begin[q[1]], end[q[1]]);
				ret.push_back((ans % M + M) % M);
			}
		}

		return ret;
	}
};

