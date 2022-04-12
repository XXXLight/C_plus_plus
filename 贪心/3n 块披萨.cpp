#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int maxSizeSlices(vector<int>& slices) {
		int n = slices.size();
		// 使用数组模拟双向链表
		vector<int> linkL(n);
		vector<int> linkR(n);
		for (int i = 0; i < n; ++i) {
			linkL[i] = (i == 0 ? n - 1 : i - 1);
			linkR[i] = (i == n - 1 ? 0 : i + 1);
		}
		// 将初始的元素放入优先队列中
		vector<int> valid(n, 1);
		priority_queue<pair<int, int>> q;
		for (int i = 0; i < n; ++i) {
			q.emplace(slices[i], i);
		}

		int ans = 0;
		for (int i = 0; i < n / 3; ++i) {
			// 从优先队列中取出元素时要判断其是否已被删除
			while (!valid[q.top().second]) {
				q.pop();
			}
			int pos = q.top().second;
			q.pop();
			ans += slices[pos];
			// 更新当前位置的值
			slices[pos] = slices[linkL[pos]] + slices[linkR[pos]] - slices[pos];
			q.emplace(slices[pos], pos);
			// 删去左右两侧的值
			valid[linkL[pos]] = valid[linkR[pos]] = 0;
			// 修改双向链表
			linkR[linkL[linkL[pos]]] = pos;
			linkL[linkR[linkR[pos]]] = pos;
			linkL[pos] = linkL[linkL[pos]];
			linkR[pos] = linkR[linkR[pos]];
		}
		return ans;
	}
};





class Solution {
public:
	int calculate(const vector<int>& slices) {
		int n = slices.size();
		int choose = (n + 1) / 3;
		vector<vector<int>> dp(n + 1, vector<int>(choose + 1));
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= choose; ++j) {
				dp[i][j] = max(dp[i - 1][j], (i - 2 >= 0 ? dp[i - 2][j - 1] : 0) + slices[i - 1]);
			}
		}
		return dp[n][choose];
	}

	int maxSizeSlices(vector<int>& slices) {
		vector<int> v1(slices.begin() + 1, slices.end());
		vector<int> v2(slices.begin(), slices.end() - 1);
		int ans1 = calculate(v1);
		int ans2 = calculate(v2);
		return max(ans1, ans2);
	}
};

