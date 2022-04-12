#include<bits/stdc++.h>
using namespace std;

// ÿһ��(x,y)�����״̬��k
struct Nagato {
	int x, y;
	int rest;
	Nagato(int _x, int _y, int _r) : x(_x), y(_y), rest(_r) {}
};

class Solution {
private:
	static constexpr int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

public:
	int shortestPath(vector<vector<int>>& grid, int k) {
		int m = grid.size(), n = grid[0].size();
		if (m == 1 && n == 1) {
			return 0;
		}

		k = min(k, m + n - 3);
		bool visited[m][n][k + 1];
		memset(visited, false, sizeof(visited));
		queue<Nagato> q;
		q.emplace(0, 0, k);
		visited[0][0][k] = true;
		int step = 1;
		while (!q.empty()) {
			int cnt = q.size();
			while (cnt--) {
				Nagato cur = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i) {
					int nx = cur.x + dirs[i][0];
					int ny = cur.y + dirs[i][1];
					if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
						// �������0����kû������
						if (grid[nx][ny] == 0 && !visited[nx][ny][cur.rest]) {
							// �����յ㣨�����£�
							if (nx == m - 1 && ny == n - 1) {
								return step;
							}
							// û�е����յ㣬��Ϊ��ǰ������0������k����
							q.emplace(nx, ny, cur.rest);// ��û��ʹ���ȹ���ṹ��ķ�ʽֱ������ʵ��������
							visited[nx][ny][cur.rest] = true;
						}
						// �������1
						else if (grid[nx][ny] == 1 && cur.rest > 0 && !visited[nx][ny][cur.rest - 1]) {
							// ��Ϊ������1����������һ��
							q.emplace(nx, ny, cur.rest - 1);
							visited[nx][ny][cur.rest - 1] = true;
						}
					}
				}
			}
			step++;
		}
		return -1;
	}
};




// �߼������Խ���������ʵ����������ĸ��ʾ�ԽС������һ�����������������������Ĳ��������͹�����

// ʹ��class����ʽ���������public�Ϳ�����
class Node {
public:
	int x, y, cnt;
	Node(int _x, int _y, int _cnt) :x(_x), y(_y), cnt(_cnt) {};
};
class Solution {
public:
	int dirX[4] = { 0,0,1,-1 }, dirY[4] = { 1,-1,0,0 };
	int shortestPath(vector<vector<int>>& grid, int k) {
		int row = grid.size(), col = grid[0].size();
		if (row == 1 && col == 1) return 0;
		int flag[row][col][k + 1];
		memset(flag, false, sizeof(flag));
		flag[0][0][k] = true;
		queue<Node> q;
		Node n1 = Node(0, 0, k);// ʹ�ù��캯����������
		q.push(n1);// ���������
		int res = 0;
		while (!q.empty()) {
			int len = q.size();
			while (len--) {
				Node n2 = q.front();
				q.pop();
				for (int kk = 0; kk < 4; kk++) {
					int newX = n2.x + dirX[kk], newY = n2.y + dirY[kk];
					if (newX >= 0 && newX < row&&newY >= 0 && newY < col) {// �߽���
						if (newX == row - 1 && newY == col - 1) return res + 1;// �����յ�return���
						if (grid[newX][newY] == 0 && !flag[newX][newY][n2.cnt]) {
							flag[newX][newY][n2.cnt] = true;
							// �µĽڵ����
							Node n3 = Node(newX, newY, n2.cnt);
							q.push(n3);
						}
						else if (grid[newX][newY] == 1 && n2.cnt - 1 >= 0 && !flag[newX][newY][n2.cnt - 1]) {
							flag[newX][newY][n2.cnt - 1] = true;
							// �µĽڵ����
							Node n3 = Node(newX, newY, n2.cnt - 1);
							q.push(n3);
						}
					}
				}
			}
			res++;// ��¼BFS�Ĳ���
		}
		return -1;
	}
};