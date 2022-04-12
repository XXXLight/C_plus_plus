#include<bits/stdc++.h>
using namespace std;


//˼·��(1)�ӱ߽紦��O��ʼDFS����O����U����Ϊ�߽��O�������O��һ����ĸ������Ҫ��������ĸ�������֣�
//(2)�ٽ������O����X��U���������ɣ�����˳��Ҫע��
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0) return;
		int m = board.size(); //����
		int n = board[0].size(); //����
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// �ӱ�Եo��ʼ����
				bool isEdge = i == 0 || j == 0 || i == m - 1 || j == n - 1; //�߽�
				if (isEdge && board[i][j] == 'O') {
					dfs(board, i, j); //�����ϵ�'O'���ɡ�#��
				}
			}
		}
		// ������������˳��ȷʵ���ܵߵ�
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// ����ġ�O������ ��X��
				if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
				// ����� ��O��������
				if (board[i][j] == '#') {
					board[i][j] = 'O';
				}
			}
		}
	}

	void dfs(vector<vector<char>>& board, int i, int j) {
		// �������ĵط��ͻ������ߵ�����ͬ�ͻ���������˼ά
		if (not (i >= 0 && i < board.size()) || not (j >= 0 && j < board[0].size()) || board[i][j] != 'O') {//ע������һ��Ҫ�ǣ�=��O��,��Ϊ�²�����#
			return;//return����������
		}
		board[i][j] = '#';
		// ѧ�����÷������飬����д������
		int di[4] = { 0,0,1,-1 }, dj[4] = { 1,-1,0,0 };
		for (int index = 0; index < 4; index++)
			dfs(board, i + di[index], j + dj[index]);
		// dfs(board, i - 1, j); // ��
		// dfs(board, i + 1, j); // ��
		// dfs(board, i, j - 1); // ��
		// dfs(board, i, j + 1); // ��
	}
};