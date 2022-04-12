#include<bits/stdc++.h>
using namespace std;

// 1、暴力递归
class Solution {
public:
	int fib(int N) {
		if (N == 0) return 0;
		if (N == 1 || N == 2) return 1;
		return fib(N - 1) + fib(N - 2);
	}
};

// 备忘录用map写
// 理解，hash表也可以理解为数组
const int eps = 1e9 + 7;
class Solution {
public:
	map<int, int> mp; // 类比数组，其实数组就是int-》int的映射
	int fib(int N) {
		if (N <= 1) return N;
		// 第N项已经算过了，直接退出
		if (mp.count(N)) return mp[N] % eps;
		mp[N] = (fib(N - 1) + fib(N - 2)) % eps; // 没有算过继续算
		return mp[N];
	}
};

// 2、带备忘录的递归解法
class Solution {
public:
	int fib(int N) {
		if (N == 0) return 0;
		// 备忘录全初始化为 0
		vector<int> memo(N + 1, 0); // 空间换时间的空间
		// 进行带备忘录的递归
		return helper(memo, N);
	}

	int helper(vector<int>& memo, int n) {
		// base case 
		if (n == 1 || n == 2) return 1;
		// 已经计算过，剪枝操作
		if (memo[n] > 0) return memo[n];
		memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
		return memo[n];
	}
};



// 3、dp 数组的迭代解法,开了o(n)的空间
//复杂度分析
//时间复杂度：O(n)。
//空间复杂度：O(1)。
class Solution {
public:
	int fib(int N) {
		if (N == 0) return 0;
		if (N == 1) return 1;
		vector<int> dp(N + 1, 0);
		// base case
		dp[1] = dp[2] = 1;
		for (int i = 3; i <= N; i++)
			dp[i] = dp[i - 1] + dp[i - 2];
		return dp[N];
	}
};

// 状态压缩，减少空间
// prev curr sum(向右平移即可)
//      prev curr sum     prev=curr=sum
class Solution {
public:
	int fib(int n) {
		if (n == 0) return 0;
		if (n == 2 || n == 1)
			return 1;
		int prev = 1, curr = 1;
		for (int i = 3; i <= n; i++) {
			int sum = prev + curr;
			prev = curr;
			curr = sum;
		}
		return curr;
	}
};



//矩阵快速幂
//复杂度分析
//时间复杂度：O(log n)。
//空间复杂度：O(1)。
class Solution {
public:
	const int MOD = 1000000007;

	int fib(int n) {
		if (n < 2) {
			return n;
		}
		vector<vector<long>> q{ {1, 1}, {1, 0} };
		vector<vector<long>> res = pow(q, n - 1);
		return res[0][0];
	}

	vector<vector<long>> pow(vector<vector<long>>& a, int n) {
		vector<vector<long>> ret{ {1, 0}, {0, 1} };
		while (n > 0) {
			if (n & 1) {
				ret = multiply(ret, a);
			}
			n >>= 1;
			a = multiply(a, a);
		}
		return ret;
	}

	vector<vector<long>> multiply(vector<vector<long>>& a, vector<vector<long>>& b) {
		vector<vector<long>> c{ {0, 0}, {0, 0} };
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
			}
		}
		return c;
	}
};
