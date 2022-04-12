#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	int cost(string& s, int l, int r) {
		int ret = 0;
		for (int i = l, j = r; i < j; ++i, --j) {
			if (s[i] != s[j]) {
				++ret;
			}
		}
		return ret;
	}

	int palindromePartition(string& s, int k) {
		int n = s.size();
		vector<vector<int>> f(n + 1, vector<int>(k + 1, INT_MAX));
		f[0][0] = 0;
		// ע��i��1~n���ǰ�����
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= min(k, i); ++j) {
				// �ֳ�1�Σ�ֱ�ӽ�[0,i-1]Ҳ����ԭʼ�ַ����޸ĳɻ��ľͿ�����
				if (j == 1) {
					f[i][j] = cost(s, 0, i - 1);
				}
				else {
					for (int i0 = j - 1; i0 < i; ++i0) {
						// ǰi���ֳ�j�Σ�ǰi0���ֳ�j-1�Σ�[i0,i-1]֮����ַ����޸ĳɻ��Ĵ�����Ҫ�Ĵ���
						f[i][j] = min(f[i][j], f[i0][j - 1] + cost(s, i0, i - 1));
					}
				}
			}
		}

		return f[n][k];
	}
};

