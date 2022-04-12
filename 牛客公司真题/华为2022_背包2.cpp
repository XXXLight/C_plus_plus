#include<bits/stdc++.h>
using namespace std;

const int maxn = 200;
const int maxV = 20000;
int main() {
	int n, V;
	cin >> V >> n;
	vector<int> w(n);
	vector<int> c(n);
	vector<int> num(n);
	vector<int> dp(maxV);
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> num[i] >> c[i];
	}
	for (int v = 0; v <= V; v++) dp[v] = 0;
	for (int i = 1; i <= n; i++) {
		for (int v = V; v >= w[i]; v--) {
			dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
		}
	}
	int maxV = 0;
	for (int v = 0; v <= V; v++) {
		if (dp[v] > maxV) {
			maxV = dp[v];
		}
	}
	cout << maxV;
	return 0;
}