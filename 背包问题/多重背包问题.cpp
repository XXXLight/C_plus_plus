#include<bits/stdc++.h>
using namespace std;

//���ر�������ĳ���ⷨ
// ����:N����Ʒ	 ��������V  �� i ����Ʒ����� s[i] ����ÿ������� v[i]����ֵ�� w[i]��
int maxValue(int N, int V, vector<int>& s, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {	// ö����Ʒ����
		for (int j = V; j >= v[i]; j--) {	// ö�ٱ�������
			for (int k = 0; k <= s[i] && j >= k * v[i]; k++) {
				dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
			}
		}
	}
	return dp[V];
}


//���ر�������ġ��������Ż����ⷨ
int maxValue(int N, int V, vector<int>& s, vector<int>& v, vector<int>& w) {
	// ��ƽ��
	vector<int> worth, volume;
	// ����ϣ��ÿ����Ʒ�����б�ƽ�����������ȱ������е���Ʒ
	for (int i = 0; i < N; i++) {
		// ��ȡÿ����Ʒ�ĳ��ִ���
		int val = s[i];
		// ���б�ƽ�������һ����Ʒ�涨��ʹ�ô���Ϊ 7 �Σ����ǽ����ƽ��Ϊ������Ʒ��1*����&1*��ֵ��2*����&2*��ֵ��4*����&4*��ֵ
		// ������Ʒ����ѡ��Ӧ������ʹ�ø���Ʒ 0 �ε������ֻѡ���һ����ƽ��Ʒ��Ӧʹ�ø���Ʒ 1 �ε������ֻѡ��ڶ�����ƽ��Ʒ��Ӧʹ�ø���Ʒ 2 �ε������ֻѡ���һ���͵ڶ�����ƽ��Ʒ��Ӧ��ʹ�ø���Ʒ 3 �ε���� ... 
		for (int k = 1; k <= val; k *= 2) {
			val -= k;
			worth.push_back(w[i] * k);
			volume.push_back(v[i] * k);
		}
		if (val > 0) {
			worth.push_back(w[i] * val);
			volume.push_back(v[i] * val);
		}
	}
	
	// 0-1 ��������������
	vector<int> dp(V + 1);
	for (int i = 0; i < worth.size(); i++) {
		for (int j = V; j >= volume[i]; j--) {
			dp[j] = max(dp[j], dp[j - volume[i]] + worth[i]);
		}
	}
	return dp[V];
}


//���ر�������ġ��������С��ⷨ
int maxValue(int N, int V, vector<int>& s, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	vector<int> g(V + 1);// �������У���¼������һ�εĽ��
	vector<int> q(V + 1);// �����У���¼���Ǳ��εĽ��

	// ö����Ʒ
	for (int i = 0; i < N; i++) {
		int vi = v[i];
		int wi = w[i];
		int si = s[i];
		// ���ϴ���Ľ�����븨��������
		g = dp;

		// ö������
		for (int j = 0; j < vi; j++) {
			int hh = 0, tt = -1;
			// ö��ͬһ��������£��ж����ַ�������������Ϊ 1 ��������У�1��vi + 1��2 * vi + 1��3 * vi + 1 ...
			for (int k = j; k <= V; k += vi) {
				dp[k] = g[k];
				if (hh <= tt && q[hh] < k - si * vi) hh++;
				if (hh <= tt) dp[k] = max(dp[k], g[q[hh]] + (k - q[hh]) / vi * wi);
				while (hh <= tt && g[q[tt]] - (q[tt] - j) / vi * wi <= g[k] - (k - j) / vi * wi) tt--;
				q[++tt] = k;
			}
		}
	}
	return dp[V];
}




// ���ذ汾
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
