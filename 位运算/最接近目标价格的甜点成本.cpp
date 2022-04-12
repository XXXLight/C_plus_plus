#include<bits/stdc++.h>
using namespace std;


class Solution {
	using ll = long long; // 学习这种书写方式
public:
	int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
		int n = baseCosts.size(), m = toppingCosts.size();
		ll ret = baseCosts[0], cur = 0;

		// 选择第 i 种基料
		for (int i = 0; i < n; i++) {
			// 第一次选择
			for (int j = 0; j < (1 << m); j++) {
				// 第二次选择
				for (int k = j; k < (1 << m); k++) { // k=0开始也行，时间复杂度增加一半
					// 先加入第 i 种基料的成本
					cur = baseCosts[i];

					// 遍历 m 种配料
					for (int l = 0; l < m; l++) {
						if (j & (1 << l)) cur += toppingCosts[l];
						if (k & (1 << l)) cur += toppingCosts[l];
					}
					if (abs(ret - target) > abs(cur - target)) {
						ret = cur;
					}
					else if (abs(ret - target) == abs(cur - target)) {
						// 选择成本较小的
						ret = min(ret, cur);
					}
				}
			}
		}
		return ret;
	}
};



// 转化为背包问题
class Solution {
public:
	int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
		vector<bool> can(20001);
		for (int base : baseCosts)
			can[base] = true;
		toppingCosts.insert(toppingCosts.end(), toppingCosts.begin(), toppingCosts.end());
		for (int topping : toppingCosts) {
			for (int i = 20000; i >= topping; --i)
				can[i] = can[i] || can[i - topping];
		}
		int min_gap = INT_MAX, ans = 0;
		for (int i = 1; i <= 20000; ++i)
			if (can[i] && abs(i - target) < min_gap) {
				ans = i;
				min_gap = abs(i - target);
			}
		return ans;
	}
};
