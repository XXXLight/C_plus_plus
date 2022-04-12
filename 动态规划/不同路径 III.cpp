#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	// ������0�ĸ���
	int zero_grid = 0;

	int uniquePathsIII(vector<vector<int>>& grid) {
		int res = 0;
		int row = 0;
		int col = 0;
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == 1) {
					row = i;
					col = j;
				}
				else if (grid[i][j] == 0)
					zero_grid++;
				else {};
			}
		backtrack(grid, res, 0, row, col);

		return res;
	}

	void backtrack(vector<vector<int>>& grid, int& res, int step, int row, int col) {
		// ������������
		// ע��ϲ�һЩ�ж�����
		if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == -1)
			return;
		if (grid[row][col] == 2) {
			if (step > zero_grid)
				res++;
			return;
		}
		// ����ѡ��
		grid[row][col] = -1;
		// ��ѡ���б��н��еݹ�ѭ��
		backtrack(grid, res, step + 1, row - 1, col);
		backtrack(grid, res, step + 1, row, col + 1);
		backtrack(grid, res, step + 1, row + 1, col);
		backtrack(grid, res, step + 1, row, col - 1);
		// ����ѡ��
		grid[row][col] = 0;

	}
};
