#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	//DFS + DP ���仯����
	//��ÿ���������̽��dp[x][y] = max(dp[x][y],dfs(x,y)+1)
	int dx[4] = { 0,1,0,-1 };////4�������ƶ� �� ��  �� ��
	int dy[4] = { 1,0,-1,0 };
	int m, n;
	int dp[150][150] = { 0 };
	int dfs(vector<vector<int>>& matrix, int x, int y)
	{
		if (dp[x][y] != 0)
			return dp[x][y];
		//4��������̽
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n || matrix[tx][ty] <= matrix[x][y])
				continue;
			//��û�г����� matrix[tx][ty] >= matrix[x][y]����
			dp[x][y] = max(dp[x][y], dfs(matrix, tx, ty) + 1);//�����dp                
		}
		return dp[x][y];
	}
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		m = matrix.size();
		n = matrix[0].size();
		int maxStep = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				maxStep = max(maxStep, dfs(matrix, i, j)); //��ÿ���������̽

		return maxStep + 1;
	}
};




// �����Ƕ�̬�滮 dp[i][j]=max(dp[newX][newY])+1 newX,newY�ĸ�����
class Solution {
public:
	int memo[200][200] = { 0 }; // ����¼��ʼΪ 0
	int DFS(vector<vector<int>>& matrix, int i, int j) {
		if (memo[i][j] != 0) return memo[i][j];   // �����ֱ��return 
		int row = matrix.size(), col = matrix[0].size();
		int dirX[4] = { 0,0,1,-1 }, dirY[4] = { 1,-1,0,0 };
		int res = 1;
		for (int k = 0; k < 4; k++) {
			int newX = i + dirX[k], newY = j + dirY[k];
			if (newX >= 0 && newX < row&&newY >= 0 && newY<col&&matrix[newX][newY]>matrix[i][j])
				res = max(res, DFS(matrix, newX, newY) + 1);
		}
		memo[i][j] = res;
		return res;
	}
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int res = 0;
		int row = matrix.size(), col = matrix[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				res = max(res, DFS(matrix, i, j));
			}
		}
		return res;
	}
};