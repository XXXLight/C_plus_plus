//参考文档：https://zhuanlan.zhihu.com/p/93857890			
// https://leetcode-cn.com/circle/discuss/GWpXCM/
// https://leetcode-cn.com/problems/last-stone-weight-ii/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-5lfv/
#include<bits/stdc++.h>
using namespace std;


// 只有压缩到一维的时候才需要进行枚举顺序的区分，01和k的时候需要逆向枚举，也就是有限件的时候需要逆向枚举


//对比,一维数组方式解决背包问题
// 0-1，只有一件物品，放与不放
int maxValue01_4(int N, int V, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {// 从0开始正向枚举N件物品,i++
		for (int j = V; j >= v[i]; j--) {// 逆向枚举背包容量,j--
			dp[j] = max(dp[j], w[i] + dp[j - v[i]]);
		}
	}
	return dp[V];
}
// 完全，有无数件物品
int maxValue(int N, int V, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {// 从0开始正向枚举N件物品,i++
		for (int j = v[i]; j <= V; j++) { // 正向枚举背包容量,j++
			dp[j] = max(dp[j], w[i] + dp[j - v[i]]);
		}
	}
	return dp[V];
}
// 多重，有k件物品
int maxValue(int N, int V, vector<int>& s, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {	// 从0开始正向枚举N件物品,i++
		for (int j = V; j >= v[i]; j--) {	// 逆向枚举背包容量，j--
			for (int k = 0; k <= s[i] && j >= k * v[i]; k++) {
				dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
			}
		}
	}
	return dp[V];
}




// 最朴素解法，二维方式，物品从1~N件进行输入，全部正向枚举就可以了++++++++++++
// 01背包
#include <iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];
int f[N][N];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			f[i][j] = f[i - 1][j];
			if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
		}
	}
	cout << f[n][m] << endl;
	return 0;
}
//完全背包
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
// 多维背包问题，与完全背包代码完全一样，只不过多了一个k <= s[i]
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int v[N], w[N], s[N];
int f[N][N];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];
	for (int i = 1; i <= n; i++) {//枚举背包
		for (int j = 1; j <= m; j++) {//枚举体积
			for (int k = 0; k <= s[i] && k*v[i] <= j; k++) {
				// k=0时包含f[i-1][j]
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}
