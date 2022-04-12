#include<bits/stdc++.h>
using namespace std;

//��ȫ��������ĳ���ⷨ
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


//���� 0 - 1 ������һά dp ���������ȫ����
int maxValue(int N, int V, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {
		// for (int j = V; j >= v[i]; j--) { // 0-1 ��������
		for (int j = v[i]; j <= V; j++) { // ��ȫ��������
			int n = dp[j]; // ��ѡ����Ʒ
			int y = w[i] + dp[j - v[i]]; // ѡ�����Ʒ
			dp[j] = max(n, y);
		}
	}
	return dp[V];
}



// AC����
#include<bits/stdc++.h>
using namespace std;
// ��ȫ����Ϊʲô���������Ż��� https://blog.csdn.net/qq_35356840/article/details/106493654?spm=1001.2101.3001.6650.5&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-5.pc_relevant_aa&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-5.pc_relevant_aa&utm_relevant_index=9
// ��Ϊ��ȫ�����õ���i��ͬһ���
int maxValue(int N, int V, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {
		for (int j = v[i]; j <= V; j++) { // ��ȫ��������
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




// ��ά��ʱ�汾
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

