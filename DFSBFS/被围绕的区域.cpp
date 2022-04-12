#include<bits/stdc++.h>
using namespace std;


//思路：(1)从边界处的O开始DFS，将O换成U（因为边界的O和里面的O是一个字母，所以要用两个字母加以区分）
//(2)再将里面的O换成X，U换回来即可，交换顺序要注意
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0) return;
		int m = board.size(); //行数
		int n = board[0].size(); //列数
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// 从边缘o开始搜索
				bool isEdge = i == 0 || j == 0 || i == m - 1 || j == n - 1; //边界
				if (isEdge && board[i][j] == 'O') {
					dfs(board, i, j); //将边上的'O'换成‘#’
				}
			}
		}
		// 以下两个换的顺序确实不能颠倒
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// 里面的‘O’换成 ‘X’
				if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
				// 外面的 ‘O’换回来
				if (board[i][j] == '#') {
					board[i][j] = 'O';
				}
			}
		}
	}

	void dfs(vector<vector<char>>& board, int i, int j) {
		// 碰到暗的地方就回来，走到死胡同就回来，逆向思维
		if (not (i >= 0 && i < board.size()) || not (j >= 0 && j < board[0].size()) || board[i][j] != 'O') {//注意这里一定要是！=‘O’,因为新产生了#
			return;//return就是往回走
		}
		board[i][j] = '#';
		// 学会利用方向数组，两种写法而已
		int di[4] = { 0,0,1,-1 }, dj[4] = { 1,-1,0,0 };
		for (int index = 0; index < 4; index++)
			dfs(board, i + di[index], j + dj[index]);
		// dfs(board, i - 1, j); // 上
		// dfs(board, i + 1, j); // 下
		// dfs(board, i, j - 1); // 左
		// dfs(board, i, j + 1); // 右
	}
};