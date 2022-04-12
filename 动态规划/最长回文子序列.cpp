#include<bits/stdc++.h>
using namespace std;


// ��ⷴ�������б�����
// ���ò�˵����д����������ģ�ѧ���ھ�
// �Ա�����������к�������Ӵ���һ����������չ��һ��������dp


// ����˼ά������ɾ�������ɻ���   �ȼ���  �����������
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int n = s.size();
		// dp ����ȫ����ʼ��Ϊ 0
		vector<vector<int>> dp(n, vector<int>(n, 0));
		// base case
		for (int i = 0; i < n; i++)
			dp[i][i] = 1;
		// ���ű�����֤��ȷ��״̬ת��
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				// ״̬ת�Ʒ���
				if (s[i] == s[j])
					dp[i][j] = dp[i + 1][j - 1] + 2;
				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
		// ���� s ��������Ӵ�����
		return dp[0][n - 1];
	}
};



//             i,j-1     i,j
//		       i+1,j-1   i+1,j   �����������������Ͻǣ������������Ե����ϱ�����
// Ҳ��������д
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int n = s.size();
		// dp ����ȫ����ʼ��Ϊ 0
		vector<vector<int>> dp(n, vector<int>(n, 0));
		// base case
		for (int i = 0; i < n; i++)
			dp[i][i] = 1;
		// ���ű�����֤��ȷ��״̬ת��
		int ans = 1;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				// ״̬ת�Ʒ���
				if (s[i] == s[j]) {
					// j<i�Ļ�dp[i][j]=0
					dp[i][j] = dp[i + 1][j - 1] + 2;
					ans = max(ans, dp[i][j]);
				}

				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
		// ���� s ��������Ӵ�����
		return ans;
	}
};


class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int n = s.size();
		// dp�������������
		int dp[1001][1001] = { 0 };
		for (int i = 0; i < n; i++) dp[i][i] = 1;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[0][n - 1];
	}
};



// ���Կ�����ĸ��¹���
class Solution {
public:
	void printV(vector<vector<int>>& dp) {
		int len = dp.size();
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	int longestPalindromeSubseq(string s) {
		int n = s.size();
		// dp ����ȫ����ʼ��Ϊ 0
		vector<vector<int>> dp(n, vector<int>(n, 0));
		// base case
		for (int i = 0; i < n; i++)
			dp[i][i] = 1;
		// ���ű�����֤��ȷ��״̬ת��
		printV(dp);// ����ԭʼ״̬
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				// ״̬ת�Ʒ���
				if (s[i] == s[j])
					dp[i][j] = dp[i + 1][j - 1] + 2;
				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				printV(dp);// ÿ����һ�Σ��Ѿ����ӡ����
			}
		}
		// ���� s ��������Ӵ�����
		return dp[0][n - 1];
	}
};