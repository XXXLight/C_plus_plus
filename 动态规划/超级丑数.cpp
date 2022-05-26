#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


// 为什么不好二分？因为数组长度primes太长

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(1);

		int cnt = 1;
		unordered_set<long> visited;
		while (cnt < n) {
			int cur = pq.top(); pq.pop();
			cnt++;
			for (const auto& p : primes) {
				long next = (long)cur * p;
				if (!visited.count(next) && next <= INT_MAX) {
					visited.insert(next);
					pq.push(next);
				}
			}
		}

		return pq.top();
	}
};


class Solution {
public:
	int res[1000001]; // 记录结果
	priority_queue<long long, vector<long long>, greater<>> p;
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		p.emplace(1);
		int cnt = 0;
		while (1) {
			long long t = p.top();
			while (!p.empty() && t == p.top()) {
				p.pop();
			}
			for (auto& e : primes) {
				p.emplace(e*t);
			}
			res[cnt] = t;
			if (cnt == n) break;
			cnt++;
		}
		return res[n - 1];
	}
};



class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<long> dp(n + 1);
		int m = primes.size();
		vector<int> pointers(m, 0);
		vector<long> nums(m, 1);
		for (int i = 1; i <= n; i++) {
			long minNum = INT_MAX;
			for (int j = 0; j < m; j++) {
				minNum = min(minNum, nums[j]);
			}
			dp[i] = minNum;
			for (int j = 0; j < m; j++) {
				if (nums[j] == minNum) {
					pointers[j]++;
					nums[j] = dp[pointers[j]] * primes[j];
				}
			}
		}
		return dp[n];
	}
};

