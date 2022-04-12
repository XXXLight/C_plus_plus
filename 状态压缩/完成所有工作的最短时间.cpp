#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minimumTimeRequired(vector<int>& jobs, int k) {
		int n = jobs.size();
		vector<int> tot(1 << n, 0);
		for (int i = 1; i < (1 << n); i++) {
			for (int j = 0; j < n; j++) {
				if ((i & (1 << j)) == 0) continue;
				int left = (i - (1 << j));
				tot[i] = tot[left] + jobs[j];
				break;
			}
		}

		vector<vector<int>> dp(k, vector<int>(1 << n, -1));
		for (int i = 0; i < (1 << n); i++) {
			dp[0][i] = tot[i];
		}

		for (int j = 1; j < k; j++) {
			for (int i = 0; i < (1 << n); i++) {
				int minv = INT_MAX;
				for (int s = i; s; s = (s - 1) & i) { // 枚举 i 的全部子集
					int left = i - s;
					int val = max(dp[j - 1][left], tot[s]);
					minv = min(minv, val);
				}
				dp[j][i] = minv;
			}
		}
		return dp[k - 1][(1 << n) - 1];
	}
};




class Solution {
public:
	bool backtrack(vector<int>& jobs, vector<int>& workloads, int idx, int limit) {
		if (idx >= jobs.size()) {
			return true;
		}
		int cur = jobs[idx];
		for (auto& workload : workloads) {
			if (workload + cur <= limit) {
				workload += cur;
				if (backtrack(jobs, workloads, idx + 1, limit)) {
					return true;
				}
				workload -= cur;
			}
			// 如果当前工人未被分配工作，那么下一个工人也必然未被分配工作
			// 或者当前工作恰能使该工人的工作量达到了上限
			// 这两种情况下我们无需尝试继续分配工作
			if (workload == 0 || workload + cur == limit) {
				break;
			}
		}
		return false;
	}

	bool check(vector<int>& jobs, int k, int limit) {
		vector<int> workloads(k, 0);
		return backtrack(jobs, workloads, 0, limit);
	}

	int minimumTimeRequired(vector<int>& jobs, int k) {
		sort(jobs.begin(), jobs.end(), greater<int>());
		int l = jobs[0], r = accumulate(jobs.begin(), jobs.end(), 0);
		while (l < r) {
			int mid = (l + r) >> 1;
			if (check(jobs, k, mid)) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		return l;
	}
};

