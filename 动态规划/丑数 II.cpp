#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> v;
		for (long long a = 1; a <= INT_MAX; a = a * 2)
			for (long long b = a; b <= INT_MAX; b = b * 3)
				for (long long c = b; c <= INT_MAX; c = c * 5)
					v.push_back(c);
		sort(v.begin(), v.end());
		return v[n - 1];
	}
};

//正常思路：2^i*3^j*5^k		
//所以容易写出对 i,j,k进行枚举的写法，但是实际上是对阶乘进行枚举
//class Solution {
//public:
//	int nthUglyNumber(int n) {
//		vector<long long> v;
//		for (int i = 0; i < 100; i++) {
//			for (int j = 0; j < 100; j++) {
//				for (int k = 0; k < 100; k++) {
//					if (pow(2, i)*pow(3, j)*pow(5, k) < INT_MAX)
//						v.push_back(pow(2, i)*pow(3, j)*pow(5, k));
//				}
//			}
//		}
//		sort(v.begin(), v.end());
//
//		return v[n - 1];
//	}
//};

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<long long> v;
		for (long long a = 1; a <= INT_MAX; a = a * 2)
			for (long long b = 1; b <= INT_MAX && (a*b < INT_MAX); b = b * 3)
				for (long long c = 1; c <= INT_MAX && (a*b*c < INT_MAX); c = c * 5)
				{
					// (a^i)*(b^j)*(c^k)
					v.push_back(a*b*c);
				}
		sort(v.begin(), v.end());
		return v[n - 1];
	}
};

// 时间复杂度：o(nlogn)
// 空间复杂度：o(n)
class Solution {
public:
	int nthUglyNumber(int n) {
		// greater对应小根堆
		priority_queue <long long, vector<long long>, greater<long long> > q;
		long long answer = 1;
		// while(1) 好理解
		for (int i = 1; i < n; ++i)
		{
			q.push(answer * 2);
			q.push(answer * 3);
			q.push(answer * 5);
			answer = q.top();
			q.pop();
			// 去重,弹之前确保非空
			while (!q.empty() && answer == q.top())
				q.pop();
		}
		return answer;
	}
};
// while(1)版
class Solution {
public:
	priority_queue<long long, vector<long long>, greater<long long>> p;
	int nthUglyNumber(int n) {
		int cnt = 0;
		p.emplace(1);
		vector<long long> v;
		while (1) {
			long long  t = p.top();
			p.emplace(t * 2);
			p.emplace(t * 3);
			p.emplace(t * 5);
			v.push_back(p.top());
			cnt++;
			if (cnt == n) break;
			long long  t1 = p.top();
			while (!p.empty() && p.top() == t1) p.pop();
		}
		for (auto e : v) cout << e << " ";
		return v.back();
	}
};



// 时间复杂度：o(n)
// 空间复杂度：o(n)
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> dp(n, 1);
		int p_2, p_3, p_5;
		p_2 = p_3 = p_5 = 0;
		for (int i = 1; i < n; ++i)
		{
			dp[i] = min(min(2 * dp[p_2], 3 * dp[p_3]), 5 * dp[p_5]);
			if (dp[i] == 2 * dp[p_2])
				++p_2;
			if (dp[i] == 3 * dp[p_3])
				++p_3;
			if (dp[i] == 5 * dp[p_5])
				++p_5;
		}
		return dp[n - 1];
	}
};

