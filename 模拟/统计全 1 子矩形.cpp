#include<bits/stdc++.h>
using namespace std;

// �������漣
class Solution {
public:
	//����Ե㣨i��j���ͣ�k,l����Χ�ڵľ����Ƿ���0
	//ע��߽綼�ǰ���
	bool check(vector<vector<int>>& mat, int i, int j, int k, int l) {
		for (int r = i; r <= k; r++) {
			for (int c = j; c <= l; c++) {
				if (mat[r][c] == 0) {
					return false;
				}
			}
		}
		return true;
	}
	int numSubmat(vector<vector<int>>& mat) {
		int row = mat.size();
		int col = mat[0].size();
		int ans = 0;
		//������ά����
		for (int i = 0; i <= row - 1; i++) {
			for (int j = 0; j <= col - 1; j++) {
				for (int k = i; k <= row - 1; k++) {
					for (int l = j; l <= col - 1; l++) {
						if (!check(mat, i, j, k, l)) break;
						ans++;
					}
				}
			}
		}
		return ans;
	}
};