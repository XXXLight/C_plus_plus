//�ο��ĵ���https://zhuanlan.zhihu.com/p/93857890			
// https://leetcode-cn.com/circle/discuss/GWpXCM/
// https://leetcode-cn.com/problems/last-stone-weight-ii/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-5lfv/
#include<bits/stdc++.h>
using namespace std;


// ֻ��ѹ����һά��ʱ�����Ҫ����ö��˳������֣�01��k��ʱ����Ҫ����ö�٣�Ҳ�������޼���ʱ����Ҫ����ö��


//�Ա�,һά���鷽ʽ�����������
// 0-1��ֻ��һ����Ʒ�����벻��
int maxValue01_4(int N, int V, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {// ��0��ʼ����ö��N����Ʒ,i++
		for (int j = V; j >= v[i]; j--) {// ����ö�ٱ�������,j--
			dp[j] = max(dp[j], w[i] + dp[j - v[i]]);
		}
	}
	return dp[V];
}
// ��ȫ������������Ʒ
int maxValue(int N, int V, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {// ��0��ʼ����ö��N����Ʒ,i++
		for (int j = v[i]; j <= V; j++) { // ����ö�ٱ�������,j++
			dp[j] = max(dp[j], w[i] + dp[j - v[i]]);
		}
	}
	return dp[V];
}
// ���أ���k����Ʒ
int maxValue(int N, int V, vector<int>& s, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {	// ��0��ʼ����ö��N����Ʒ,i++
		for (int j = V; j >= v[i]; j--) {	// ����ö�ٱ���������j--
			for (int k = 0; k <= s[i] && j >= k * v[i]; k++) {
				dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
			}
		}
	}
	return dp[V];
}




// �����ؽⷨ����ά��ʽ����Ʒ��1~N���������룬ȫ������ö�پͿ�����++++++++++++
// 01����
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
//��ȫ����
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
				// ���������Ȼ��dp[i][j],01������dp[i-1][j]
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
	cout << dp[n][m] << endl;
}
// ��ά�������⣬����ȫ����������ȫһ����ֻ��������һ��k <= s[i]
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
	for (int i = 1; i <= n; i++) {//ö�ٱ���
		for (int j = 1; j <= m; j++) {//ö�����
			for (int k = 0; k <= s[i] && k*v[i] <= j; k++) {
				// k=0ʱ����f[i-1][j]
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}
