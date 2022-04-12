#include<bits/stdc++.h>
using namespace std;

// 时间复杂度：O(N * loglogN)
// 记忆方法： 所有true ---->删选----->再统计（类比筛选过程，一模一样）
// 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17...自己模拟一遍
class Solution {
public:
	int countPrimes(int n) {
		// 所有的标记为true
		vector<bool> flag(n + 1, true);
		// 筛选过程 [2,sqrt(n))
		for (int i = 2; i < sqrt(n); i++) {
			if (flag[i]) {
				for (int j = i * i; j < n; j += i) {
					flag[j] = false;
				}
			}
		}
		int cnt = 0;
		for (int i = 2; i < n; i++) {
			if (flag[i])
				cnt++;
		}
		return cnt;
	}
};