// 5����Ʒ����������Ϊ8
// ������Ʒ������3 5 1 2 2
//	������Ʒ��ֵ��4 5 2 1 3
#include<bits/stdc++.h>
using namespace std;

const int maxN = 100;
const int maxV = 1000;
vector<int> w(maxN), c(maxN), dp(maxN);


//0 - 1 ��������� dp[N][V + 1] �ⷨ
//dp[i][j]�ĺ�����ǰ0~i����Ʒ������������j����������ܻ�õ�����ֵ
int maxValue01_1(int N, int V, vector<int>& v, vector<int>& w) {
	vector<vector<int>> dp(N, vector<int>(V + 1));
	dp[0][0] = 0;
	for (int i = 0; i < V + 1; i++) {
		// ֻ�е�0����Ʒ������������i����i>=v[0]ʱ��ʾ���Է��µ�һ����Ʒ
		dp[0][i] = i >= v[0] ? w[0] : 0;
	}
	for (int i = 1; i < N; i++) {// ��1��ʼ����ö��N����Ʒ
		for (int j = 0; j < V + 1; j++) {// ����ö�ٱ���������ע���������������������ö�ٶ����ԣ�for (int j = V; j >=0; j--)Ҳ�ǿ��Ե�
			if (j >= v[i]) {
				dp[i][j] = w[i] + dp[i - 1][j - v[i]]; // ѡ�����Ʒ
			}
			// ע�����������dp[i-1][j],��ȫ������dp[i][j]
			dp[i][j] = max(dp[i - 1][j], dp[i][j]);
		}
	}
	return dp[N - 1][V];// 0~N-1����Ʒ������������Vʱ������ֵ
}


//0 - 1 ��������� dp[2][V + 1] �ⷨ
int maxValue01_2(int N, int V, vector<int>& v, vector<int>& w) {
	vector<vector<int>> dp(2, vector<int>(V + 1));
	dp[0][0] = 0;
	for (int i = 0; i < V + 1; i++) {
		dp[0][i] = i >= v[0] ? w[0] : 0;
	}
	for (int i = 1; i < N; i++) {// ��1��ʼ����ö��N����Ʒ
		for (int j = 0; j < V + 1; j++) {// ����ö�ٱ�������
			int n = dp[(i - 1) % 2][j]; // ��ѡ����Ʒ
			int y = 0;
			if (j >= v[i]) {
				y = w[i] + dp[(i - 1) % 2][j - v[i]]; // ѡ�����Ʒ
			}
			dp[i % 2][j] = max(n, y);
		}
	}
	return dp[(N - 1) % 2][V];
}


// ΪʲôҪ����ö��j�����⣺ https://blog.csdn.net/weixin_44176696/article/details/105209974
// ��������ö�٣��ҵ�ǰ���ڵ�i�㣬j����ö�ٵĻ��õ����ǵ�i�е����ݣ�����ö�ٲ����õ�i-1�е�����
//0-1 ��������� dp[V + 1] �ⷨ
int maxValue01_3(int N, int V, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < V + 1; i++) {
		dp[i] = i >= v[0] ? w[0] : 0;
	}
	for (int i = 1; i < N; i++) {// ��1��ʼ����ö��N����Ʒ
		for (int j = V; j >= 0; j--) {// ����ö�ٱ�������
			if (j >= v[i]) {
				dp[j] = max(dp[j], w[i] + dp[j - v[i]]);
			}

		}
	}
	return dp[V];
}


//0-1 ��������� dp[V + 1] �ⷨ �򻯣���׼�棩
int maxValue01_4(int N, int V, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {// ��0��ʼ����ö��N����Ʒ
		for (int j = V; j >= v[i]; j--) {// ����ö�ٱ�������
			dp[j] = max(dp[j], w[i] + dp[j - v[i]]);
		}
	}
	return dp[V];
}

int main() {
	int n, V;
	cin >> n >> V;
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int v = 0; v <= V; v++) dp[v] = 0;
	for (int i = 1; i <= n; i++) {
		for (int v = V; v >= w[i]; v--) {
			dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
		}
	}
	int res = 0;
	for (int v = 0; v <= V; v++) {
		res = max(res, dp[v]);
	}
	cout << res << endl;
	cout << maxValue01_1(n, V, w, c) << endl;
	cout << maxValue01_2(n, V, w, c) << endl;
	cout << maxValue01_3(n, V, w, c) << endl;
	cout << maxValue01_4(n, V, w, c) << endl;
	return 0;
}






//	AC����
#include<bits/stdc++.h>
using namespace std;
//	0-1 ��������� dp[V + 1] �ⷨ �򻯣���׼�棩
int maxValue01_4(int N, int V, vector<int>& v, vector<int>& w) {
	vector<int> dp(V + 1);
	for (int i = 0; i < N; i++) {// ��0��ʼ����ö��N����Ʒ
		for (int j = V; j >= v[i]; j--) {// ����ö�ٱ�������
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
	cout << maxValue01_4(N, V, vV, vW);
	return 0;
}





//���Ż���
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


