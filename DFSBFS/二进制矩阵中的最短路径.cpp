#include<bits/stdc++.h>
using namespace std;


// ��ʵ�ܼ򵥣�����BFS�Ĳ�������
class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		if (grid[0][0] == 1)return -1;
		int n = grid.size(), ans = 1;
		const int dire[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1} };
		queue<pair<int, int>> q;// ����ʹ��pair�Խ��а󶨣�Ҳ����ʹ�ýṹ��
		q.emplace(0, 0);         //��0,0��ʼ�����������
		grid[0][0] = 1;           //���Ϊ1�����߹�
		while (!q.empty()) {      //bfs
			int m = q.size();
			while (m--) {
				auto[x, y] = q.front();
				q.pop();
				if (x == n - 1 && y == n - 1)return ans;// �ݹ��Ƴ������ǵ����յ�
				for (int i = 0; i < 8; i++) {                       //�����˸������
					int nx = x + dire[i][0];
					int ny = y + dire[i][1];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;   //�ж��Ƿ�Խ��
					if (grid[nx][ny] == 0) {        //�ж��Ƿ�����
						q.emplace(nx, ny);
						grid[nx][ny] = 1;         //��Ƿ��ʹ�
					}
				}
			}
			ans++;          //��¼ѭ��������whileѭ�������ǲ���
		}
		return -1;
	}
};







class Solution {
public:
	int dirX[8] = { -1,-1,-1,0,0,1,1,1 };
	int dirY[8] = { -1,0,1,1,-1,-1,0,1 };
	bool vis[101][101] = { false };
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int n = grid.size();
		if (grid[0][0] == 1) return -1;
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		int cnt = 0;
		while (!q.empty()) {
			int len = q.size();
			while (len--) {
				pair<int, int> fr = q.front();
				q.pop();
				if (fr.first == n - 1 && fr.second == n - 1 && grid[n - 1][n - 1] == 0) return cnt + 1;
				for (int i = 0; i < 8; i++) {
					int newX = fr.first + dirX[i];
					int newY = fr.second + dirY[i];
					// �����µ����꣬û�з�������з��ʣ�������flag���
					if (newX >= 0 && newX < n&&newY >= 0 && newY < n&&grid[newX][newY] == 0 && !vis[newX][newY]) {
						q.push({ newX,newY });
						vis[newX][newY] = 1;// ��������б��
					}
				}
			}
			cnt++;
		}
		return -1;
	}
};