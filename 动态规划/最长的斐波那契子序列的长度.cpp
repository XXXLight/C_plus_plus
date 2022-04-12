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

// 将数组拉成一维的，建立映射，即i，j映射到i*N+j
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


// 跟最长等差数列一模一样，递推关系变了而已
class Solution {
public:
	unordered_map<int, int> mp;
	int lenLongestFibSubseq(vector<int>& A) {
		int len = A.size();
		vector<vector<int>> dp(len, vector<int>(len, 2));
		int ans = INT_MIN;
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				int value = A[j] - A[i]; // 核心改动地方
				if (mp.count(value))
					dp[i][j] = max(dp[mp[value]][i] + 1, dp[i][j]);
				ans = max(dp[i][j], ans);
			}
			mp[A[i]] = i;
		}
		return ans >= 3 ? ans : 0;
	}
};