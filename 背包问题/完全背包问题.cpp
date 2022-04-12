#include<bits/stdc++.h>
using namespace std;

//完全背包问题的常规解法
int maxValue(int N, int V, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {
		for (int j = V; j >= v[i]; j--) {
			// k=0,1,2,3,.....
			for (int k = 0;; k++) {
				if (j < v[i] * k) {
					break;
				}
				dp[j] =max(dp[j], dp[j - v[i] * k] + w[i] * k);
			}
		}
	}
	return dp[V];
}


//利用 0 - 1 背包的一维 dp 方法求解完全背包
int maxValue(int N, int V, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {
		// for (int j = V; j >= v[i]; j--) { // 0-1 背包问题
		for (int j = v[i]; j <= V; j++) { // 完全背包问题
			int n = dp[j]; // 不选该物品
			int y = w[i] + dp[j - v[i]]; // 选择该物品
			dp[j] = max(n, y);
		}
	}
	return dp[V];
}



// AC代码
#include<bits/stdc++.h>
using namespace std;
// 完全背包为什么可以这样优化： https://blog.csdn.net/qq_35356840/article/details/106493654?spm=1001.2101.3001.6650.5&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-5.pc_relevant_aa&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-5.pc_relevant_aa&utm_relevant_index=9
// 因为完全背包用到的i是同一层的
int maxValue(int N, int V, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {
		for (int j = v[i]; j <= V; j++) { // 完全背包问题
			dp[j] = max(dp[j], w[i] + dp[j - v[i]]);
		}
	}
	return dp[V];
}


int main() {
	int N, V;
	cin >> N >> V;
	vector<int> vV(N);
	vector<int> vW(N);
	for (int i = 0; i < N; i++) cin >> vV[i] >> vW[i];
	cout << maxValue(N, V, vV, vW) << endl;
	return 0;
}




// 二维超时版本
#include<iostream>
using namespace std;
const int N = 1010;
int n, m;
int dp[N][N], v[N], w[N];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k * v[i] <= j; k++)
				// 这里左边仍然是dp[i][j],01背包是dp[i-1][j]
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
	cout << dp[n][m] << endl;
}

