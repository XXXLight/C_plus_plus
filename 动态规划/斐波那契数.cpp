#include<bits/stdc++.h>
using namespace std;

// 1�������ݹ�
class Solution {
public:
	int fib(int N) {
		if (N == 0) return 0;
		if (N == 1 || N == 2) return 1;
		return fib(N - 1) + fib(N - 2);
	}
};

// ����¼��mapд
// ��⣬hash��Ҳ�������Ϊ����
const int eps = 1e9 + 7;
class Solution {
public:
	map<int, int> mp; // ������飬��ʵ�������int-��int��ӳ��
	int fib(int N) {
		if (N <= 1) return N;
		// ��N���Ѿ�����ˣ�ֱ���˳�
		if (mp.count(N)) return mp[N] % eps;
		mp[N] = (fib(N - 1) + fib(N - 2)) % eps; // û�����������
		return mp[N];
	}
};

// 2��������¼�ĵݹ�ⷨ
class Solution {
public:
	int fib(int N) {
		if (N == 0) return 0;
		// ����¼ȫ��ʼ��Ϊ 0
		vector<int> memo(N + 1, 0); // �ռ任ʱ��Ŀռ�
		// ���д�����¼�ĵݹ�
		return helper(memo, N);
	}

	int helper(vector<int>& memo, int n) {
		// base case 
		if (n == 1 || n == 2) return 1;
		// �Ѿ����������֦����
		if (memo[n] > 0) return memo[n];
		memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
		return memo[n];
	}
};



// 3��dp ����ĵ����ⷨ,����o(n)�Ŀռ�
//���Ӷȷ���
//ʱ�临�Ӷȣ�O(n)��
//�ռ临�Ӷȣ�O(1)��
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

// ״̬ѹ�������ٿռ�
// prev curr sum(����ƽ�Ƽ���)
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



//���������
//���Ӷȷ���
//ʱ�临�Ӷȣ�O(log n)��
//�ռ临�Ӷȣ�O(1)��
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
