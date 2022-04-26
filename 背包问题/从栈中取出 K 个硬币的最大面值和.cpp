#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	int maxValueOfCoins(vector<vector<int>> &piles, int k) {
		vector<int> f(k + 1);
		int sumN = 0;
		for (auto &pile : piles) {
			int n = pile.size();
			for (int i = 1; i < n; ++i)
				pile[i] += pile[i - 1]; // pile ǰ׺��
			sumN = min(sumN + n, k); // �Ż���j ��ǰ i ��ջ�Ĵ�С֮�Ϳ�ʼö�٣������� k��
			for (int j = sumN; j; --j)
				for (int w = 0; w < min(n, j); ++w)
					f[j] = max(f[j], f[j - w - 1] + pile[w]); // w �� 0 ��ʼ����Ʒ���Ϊ w+1
		}
		return f[k];
	}
};





const int N = 2010;
class Solution {
	int f[N][N], v[N][N], w[N][N], s[N];
public:
	int maxValueOfCoins(vector<vector<int>>& p, int m) {
		int res = 0;
		for (int i = 0; i < p.size(); i++) {
			for (int j = 1; j < p[i].size(); j++) {
				p[i][j] = p[i][j - 1] + p[i][j];
			}
		}
		int n = p.size();
		// vector<int> v, w;

		for (int i = 0; i < p.size(); i++) {
			s[i + 1] = p[i].size();
			for (int j = 0; j < p[i].size(); j++) {
				v[i + 1][j + 1] = j + 1;     //���
				w[i + 1][j + 1] = p[i][j]; //��ֵ
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				f[i][j] = f[i - 1][j];
				for (int k = 1; k <= s[i]; k++) {
					if (v[i][k] <= j) {
						f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
					}
				}
			}
		}
		return f[n][m];
	}
};

