#include<bits/stdc++.h>
using namespace std;


class Solution {
	using ll = long long; // ѧϰ������д��ʽ
public:
	int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
		int n = baseCosts.size(), m = toppingCosts.size();
		ll ret = baseCosts[0], cur = 0;

		// ѡ��� i �ֻ���
		for (int i = 0; i < n; i++) {
			// ��һ��ѡ��
			for (int j = 0; j < (1 << m); j++) {
				// �ڶ���ѡ��
				for (int k = j; k < (1 << m); k++) { // k=0��ʼҲ�У�ʱ�临�Ӷ�����һ��
					// �ȼ���� i �ֻ��ϵĳɱ�
					cur = baseCosts[i];

					// ���� m ������
					for (int l = 0; l < m; l++) {
						if (j & (1 << l)) cur += toppingCosts[l];
						if (k & (1 << l)) cur += toppingCosts[l];
					}
					if (abs(ret - target) > abs(cur - target)) {
						ret = cur;
					}
					else if (abs(ret - target) == abs(cur - target)) {
						// ѡ��ɱ���С��
						ret = min(ret, cur);
					}
				}
			}
		}
		return ret;
	}
};



// ת��Ϊ��������
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
