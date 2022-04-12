#include<bits/stdc++.h>
using namespace std;

//���벻��
class Solution {
public:
	vector<int> temp; //�м���
	vector<vector<int>> ans; //���н��
	void backtrack(int depth, int n, int k) { //�ݹ���ȣ�����Ԫ�ظ���
		// �������ĵݹ�߽�
		if (temp.size() == k) {//�ﵽk���ˣ����Գ��м�����
			ans.push_back(temp);
			return;
		}
		// �ݹ���Ȳ��ܴ���n
		if (depth > n) {
			return;
		}
		// ����ѡ��ǰλ��
		temp.push_back(depth);
		backtrack(depth + 1, n, k);
		// ���ǲ�ѡ��ǰλ��
		temp.pop_back();
		backtrack(depth + 1, n, k);
	}

	vector<vector<int>> combine(int n, int k) {
		backtrack(1, n, k);
		return ans;
	}
};

//forѭ��������
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


// λ���㼼�ɣ��ǳ��������
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
	int dp[N];// dp[i] ��ʾ ���� i �Ķ����Ʊ�ʾ�� 1 �ĸ���
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



// �ײ⣬�����㷨������
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

