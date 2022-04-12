#include<bits/stdc++.h>
using namespace std;

//二维前缀和
class NumMatrix {
public:
	vector<vector<int>> sums;

	NumMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m > 0) {
			int n = matrix[0].size();
			sums.resize(m + 1, vector<int>(n + 1));
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + matrix[i][j];
				}
			}
		}
		for (auto e : sums) {
			for (auto e1 : e) cout << e1 << " ";
			cout << endl;
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
	}
};



//一维前缀和
class NumMatrix {
public:
	vector<vector<int>> sums;

	NumMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m > 0) {
			int n = matrix[0].size();
			sums.resize(m, vector<int>(n + 1));
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					sums[i][j + 1] = sums[i][j] + matrix[i][j];
				}
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int sum = 0;
		for (int i = row1; i <= row2; i++) {
			sum += sums[i][col2 + 1] - sums[i][col1];
		}
		return sum;
	}
};