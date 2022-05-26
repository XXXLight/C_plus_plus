#include<bits/stdc++.h>
using namespace std;



class Solution {
private:
	using LL = long long;
	static constexpr int mod = 1000000007;

public:
	int maxSumMinProduct(vector<int>& nums) {
		int n = nums.size();
		// ���� left ��ʼ��Ϊ 0������ right ��ʼ��Ϊ n-1
		// ����ΪԪ�ز�����ʱ������ֵ
		vector<int> left(n), right(n, n - 1);
		// ����ջ
		stack<int> s;
		for (int i = 0; i < n; ++i) {
			while (!s.empty() && nums[s.top()] >= nums[i]) {
				// ����� right �Ƿ��ϸ���ģ�right[i] ���Ҳ������С�ڵ��� nums[i] ��Ԫ���±�
				right[s.top()] = i - 1;
				s.pop();
			}
			if (!s.empty()) {
				// ����� left ���ϸ���ģ�left[i] �����������ϸ�С�� nums[i] ��Ԫ���±�
				left[i] = s.top() + 1;
			}
			s.push(i);
		}

		// ǰ׺��
		vector<LL> pre(n + 1);
		for (int i = 1; i <= n; ++i) {
			pre[i] = pre[i - 1] + nums[i - 1];
		}

		LL best = 0;
		for (int i = 0; i < n; ++i) {
			best = max(best, (pre[right[i] + 1] - pre[left[i]]) * nums[i]);
		}
		return best % mod;
	}
};

