#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	bool DFS(vector<vector<char>>& board, string word, int i, int j, int k) {
		int row = board.size();
		int col = board[0].size();
		if ((not (i >= 0 && i < row&&j >= 0 && j < col)) || (word[k] != board[i][j])) return false;
		// 此时i,j的index符合要求且word[k]==board[i][j]
		if (k == word.size() - 1) return true;
		board[i][j] = '0';
		bool res = DFS(board, word, i + 1, j, k + 1) || DFS(board, word, i - 1, j, k + 1) || DFS(board, word, i, j + 1, k + 1) || DFS(board, word, i, j - 1, k + 1);
		board[i][j] = word[k];
		return res;
	}
	bool exist(vector<vector<char>>& board, string word) {
		int row = board.size();
		int col = board[0].size();
		if (row*col < word.size()) return false;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (DFS(board, word, i, j, 0))
					return true;
			}
		}
		return false;
	}
};