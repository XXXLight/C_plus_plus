#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
	//����Ե㣨i��j���ͣ�k,l����Χ�ڵľ����Ƿ���0
	//ע��߽綼�ǰ���
	bool check(vector<vector<char>>& mat, int i, int j, int k, int l) {
		for (int r = i; r <= k; r++) {
			for (int c = j; c <= l; c++) {
				if (mat[r][c] == '0') {
					return false;
				}
			}
		}
		return true;
	}
	int numSubmat(vector<vector<char>>& mat) {
		int row = mat.size();
		if (row == 0) return 0;
		int col = mat[0].size();
		int ans = 0;
		//������ά����
		for (int i = 0; i <= row - 1; i++) {
			for (int j = 0; j <= col - 1; j++) {
				for (int k = i; k <= row - 1; k++) {
					for (int l = j; l <= col - 1; l++) {
						if (!check(mat, i, j, k, l)) break;
						ans = max(ans, (k - i + 1)*(l - j + 1));
					}
				}
			}
		}
		return ans;
	}
};

class Solution {
public:
	Solution1 s1;
	int maximalRectangle(vector<vector<char>>& matrix) {
		return s1.numSubmat(matrix);
	}
};