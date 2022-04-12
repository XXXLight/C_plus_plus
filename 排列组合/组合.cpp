#include<bits/stdc++.h>
using namespace std;

//放与不放
class Solution {
public:
	vector<int> temp; //中间结果
	vector<vector<int>> ans; //所有结果
	void backtrack(int depth, int n, int k) { //递归深度，所有元素个数
		// 组合问题的递归边界
		if (temp.size() == k) {//达到k个了，可以出中间结果了
			ans.push_back(temp);
			return;
		}
		// 递归深度不能大于n
		if (depth > n) {
			return;
		}
		// 考虑选择当前位置
		temp.push_back(depth);
		backtrack(depth + 1, n, k);
		// 考虑不选择当前位置
		temp.pop_back();
		backtrack(depth + 1, n, k);
	}

	vector<vector<int>> combine(int n, int k) {
		backtrack(1, n, k);
		return ans;
	}
};

//for循环三段论
class Solution {
public:
	vector<vector<int>> res;
	vector<int> temp;
	vector<vector<int>> combine(int n, int k) {
		backtrack(n, k, 1);
		return res;
	}
	void backtrack(int n, int k, int depth) {
		if (temp.size() == k) {
			res.push_back(temp);
			return;
		}
		for (int i = depth; i <= n; i++) {
			temp.push_back(i);
			backtrack(n, k, i + 1);
			temp.pop_back();
		}
	}
};


// 位运算技巧，非常易于理解
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		int max = 1 << n;
		vector<vector<int>> res;
		for (int mark = 0; mark < max; ++mark)
		{
			if (__builtin_popcount(mark) == k)
			{
				vector<int> temp;
				for (int j = 0; j < n; ++j)
					if (mark & 1 << j) temp.push_back(j + 1);
				res.push_back(temp);
			}
		}
		return res;
	}
};



const int N = 1048577;
class Solution {
public:
	int dp[N];// dp[i] 表示 数字 i 的二进制表示中 1 的个数
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		if (k == 0) return res;
		dp[0] = 0;
		for (int i = 1; i < (1 << n); i++) {
			dp[i] = dp[(i & (i - 1))] + 1;
			if (dp[i] == k) {
				vector<int> t;
				for (int j = 0; j < n; j++) {
					if (i >> j & 1) t.push_back(j + 1);
				}
				res.push_back(t);
			}
		}
		return res;
	}
};



// 亲测，以下算法是最快的
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		auto next_n = [](int n) -> int {
			return (n + (n&(-n))) | ((n ^ (n + (n&(-n)))) / (n&(-n))) >> 2;
		};
		auto gen = [](int c, vector<int>& v) {
			int i = 0, j;
			for (; (j = (1 << i)) <= c; i++) {
				if ((c & j) != 0) v.push_back(i + 1);
			}
		};
		vector<vector<int>> res;
		int c = (1 << k) - 1;
		while (c <= ((1 << n) - (1 << (n - k)))) {
			vector<int> v;
			v.reserve(k);
			gen(c, v);
			res.emplace_back(std::move(v));
			c = next_n(c);
		}
		return res;
	}
};

