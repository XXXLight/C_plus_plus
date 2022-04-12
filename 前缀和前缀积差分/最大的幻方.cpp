#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int largestMagicSquare(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		// ÿһ�е�ǰ׺��
		vector<vector<int>> rowsum(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			rowsum[i][0] = grid[i][0];
			for (int j = 1; j < n; ++j) {
				rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
			}
		}
		// ÿһ�е�ǰ׺��
		vector<vector<int>> colsum(m, vector<int>(n));
		for (int j = 0; j < n; ++j) {
			colsum[0][j] = grid[0][j];
			for (int i = 1; i < m; ++i) {
				colsum[i][j] = colsum[i - 1][j] + grid[i][j];
			}
		}

		// �Ӵ�Сö�ٱ߳� edge
		for (int edge = min(m, n); edge >= 2; --edge) {
			// ö�������ε����Ͻ�λ�� (i,j)
			for (int i = 0; i + edge <= m; ++i) {
				for (int j = 0; j + edge <= n; ++j) {
					// ����ÿһ�С��С��Խ��ߵ�ֵӦ���Ƕ��٣��Ե�һ��Ϊ������
					int stdsum = rowsum[i][j + edge - 1] - (j ? rowsum[i][j - 1] : 0);
					bool check = true;
					// ö��ÿһ�в���ǰ׺��ֱ�����
					// ���������Ѿ��õ�һ����Ϊ�����ˣ��������������һ��
					for (int ii = i + 1; ii < i + edge; ++ii) {
						if (rowsum[ii][j + edge - 1] - (j ? rowsum[ii][j - 1] : 0) != stdsum) {
							check = false;
							break;
						}
					}
					if (!check) {
						continue;
					}
					// ö��ÿһ�в���ǰ׺��ֱ�����
					for (int jj = j; jj < j + edge; ++jj) {
						if (colsum[i + edge - 1][jj] - (i ? colsum[i - 1][jj] : 0) != stdsum) {
							check = false;
							break;
						}
					}
					if (!check) {
						continue;
					}
					// d1 �� d2 �ֱ��ʾ�����Խ��ߵĺ�
					// ���� d ��ʾ diagonal
					int d1 = 0, d2 = 0;
					// ��ʹ��ǰ׺�ͣ�ֱ�ӱ������
					for (int k = 0; k < edge; ++k) {
						d1 += grid[i + k][j + k];
						d2 += grid[i + k][j + edge - 1 - k];
					}
					if (d1 == stdsum && d2 == stdsum) {
						return edge;
					}
				}
			}
		}

		return 1;
	}
};

