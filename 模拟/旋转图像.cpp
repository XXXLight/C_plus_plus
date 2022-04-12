#include<bits/stdc++.h>
using namespace std;


// ��ѧ�Ͽ��У�������һ������
// ��������ϵ���Ӷ��ҹ����Ƶ�������ϵ
// ʱ�临�Ӷȣ�o(N^2) �ռ临�Ӷȣ�o(N^2)
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

// ʱ�临�Ӷȣ�o(N^2) �ռ临�Ӷȣ�o(1)
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		// ˮƽ��ת
		for (int i = 0; i < n / 2; ++i) {
			for (int j = 0; j < n; ++j) {
				swap(matrix[i][j], matrix[n - i - 1][j]);
			}
		}
		// ���Խ��߷�ת
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};

