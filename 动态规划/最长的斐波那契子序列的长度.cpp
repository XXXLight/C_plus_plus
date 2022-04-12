#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


class Solution {
public:
	int lenLongestFibSubseq(vector<int>& A) {
		int N = A.size();
		unordered_map<int, int> index;
		vector<vector<int>> dp(N, vector<int>(N, 0));
		int ans = 0;
		for (int k = 0; k < N; ++k) {
			for (int j = 0; j < k; ++j) {
				if (A[k] - A[j] < A[j] && index.count(A[k] - A[j])) {
					dp[j][k] = dp[index[A[k] - A[j]]][j] + 1;
					ans = max(ans, dp[j][k] + 2);
				}
			}
			index[A[k]] = k;
		}
		return ans >= 3 ? ans : 0;
	}
};

// ����������һά�ģ�����ӳ�䣬��i��jӳ�䵽i*N+j
class Solution {
public:
	int lenLongestFibSubseq(vector<int>& A) {
		int N = A.size();
		unordered_map<int, int> index;
		for (int i = 0; i < N; ++i)
			index[A[i]] = i;

		unordered_map<int, int> longest;
		int ans = 0;
		for (int k = 0; k < N; ++k)
			for (int j = 0; j < k; ++j) {
				if (A[k] - A[j] < A[j] && index.count(A[k] - A[j])) {
					int i = index[A[k] - A[j]];
					longest[j * N + k] = longest[i * N + j] + 1;
					ans = max(ans, longest[j * N + k] + 2);
				}
			}

		return ans >= 3 ? ans : 0;
	}
};


// ����Ȳ�����һģһ�������ƹ�ϵ���˶���
class Solution {
public:
	unordered_map<int, int> mp;
	int lenLongestFibSubseq(vector<int>& A) {
		int len = A.size();
		vector<vector<int>> dp(len, vector<int>(len, 2));
		int ans = INT_MIN;
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				int value = A[j] - A[i]; // ���ĸĶ��ط�
				if (mp.count(value))
					dp[i][j] = max(dp[mp[value]][i] + 1, dp[i][j]);
				ans = max(dp[i][j], ans);
			}
			mp[A[i]] = i;
		}
		return ans >= 3 ? ans : 0;
	}
};