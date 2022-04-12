#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	bool possibleToStamp(vector<vector<int>> &grid, int stampHeight, int stampWidth) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> sum(m + 1, vector<int>(n + 1)), diff(m + 1, vector<int>(n + 1));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) { // grid �Ķ�άǰ׺��
				sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
			}
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				int x = i + stampHeight, y = j + stampWidth; // ע�����Ǿ������½Ǻ������궼 +1 ���λ��
				if (x <= m && y <= n && sum[x][y] - sum[x][j] - sum[i][y] + sum[i][j] == 0) {
					++diff[i][j];
					--diff[i][y];
					--diff[x][j];
					++diff[x][y]; // ���¶�ά���
				}
			}
		}

		// ��ԭ��ά��־����Ӧ�ļ������������ù�������ʵ��
		vector<int> cnt(n + 1), pre(n + 1);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cnt[j + 1] = cnt[j] + pre[j + 1] - pre[j] + diff[i][j];
				if (cnt[j + 1] == 0 && grid[i][j] == 0) {
					return false;
				}
			}
			swap(cnt, pre);
		}
		return true;
	}
};

