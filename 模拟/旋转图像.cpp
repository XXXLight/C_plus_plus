#include<bits/stdc++.h>
using namespace std;


// 数学上可行，代码上一定可行
// 建立坐标系，从而找规律推导函数关系
// 时间复杂度：o(N^2) 空间复杂度：o(N^2)
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		auto newMatrix = matrix;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				newMatrix[j][n - 1 - i] = matrix[i][j];
			}
		}
		matrix = newMatrix;
	}
};

// 时间复杂度：o(N^2) 空间复杂度：o(1)
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		// 水平翻转
		for (int i = 0; i < n / 2; ++i) {
			for (int j = 0; j < n; ++j) {
				swap(matrix[i][j], matrix[n - i - 1][j]);
			}
		}
		// 主对角线翻转
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};

