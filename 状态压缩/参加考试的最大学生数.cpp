#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int maxStudents(vector<vector<char>>& seats) {
		int m = seats.size();
		if (m == 0) return 0;
		int n = seats[0].size();
		int ans = 0;
		vector<vector<int>>dp(m, vector<int>(1 << n, 0));//ÿһ����(1<<n)-1�����
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 1 << n; j++) {
				if (!check(j, seats, i) || !ok(j)) continue;//�ж��Ƿ�Ϸ�
				int num = __builtin_popcount(j);//��һ�п�������
				if (i == 0) dp[i][j] = num;//��һ��ֻ��Ҫ���Լ����м���
				else {
					for (int k = 0; k < 1 << n; k++) {//�ж�j|k�Ƿ�Ϸ�
						if (ok(j | k)) dp[i][j] = max(dp[i][j], dp[i - 1][k] + num);
					}
				}
				ans = max(ans, dp[i][j]);
			}
		}
		return ans;
	}
	bool check(int k, vector<vector<char>>& seats, int pos) {//�жϸ�״̬�Ƿ���ʵ��������ϣ�����1��λ�õ���λ�Ƿ��ˣ����˸�״̬�Ͳ���
		int i = 0;
		while (k) {
			int a = k % 2;
			if (a == 1 && seats[pos][i] == '#') return false;
			k /= 2;
			i++;
		}
		return true;
	}
	bool ok(int p) {//�жϸ�״̬�Ƿ���2��1���ڣ�������1���ڱ�ʾ����˵��Ա߻�����ǰ������ǰ���ˣ���ô��״̬����
		int pre = 0;
		while (p) {
			int a = p % 2;
			if (a == 1 && pre == 1) return false;
			if (a == 1) pre = 1;
			else pre = 0;
			p /= 2;
		}
		return true;
	}
};