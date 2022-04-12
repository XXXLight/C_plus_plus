#include<bits/stdc++.h>
using namespace std;

// �ѵ㣺����ĳ�ʼ��
// PS��Ϊɶ dp �����ʼ��Ϊ amount + 1 �أ���Ϊ�ճ� amount ����Ӳ�������ֻ���ܵ��� amount��ȫ�� 1 Ԫ��ֵ��Ӳ�ң���
// ���Գ�ʼ��Ϊ amount + 1 ���൱�ڳ�ʼ��Ϊ��������ں���ȡ��Сֵ��
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		// �����СΪ amount + 1����ʼֵҲΪ amount + 1
		vector<int> dp(amount + 1, amount + 1);
		// base case
		dp[0] = 0;
		// ��� for ѭ���ڱ�������״̬������ȡֵ
		for (int i = 0; i <= amount; i++) {
			// �ڲ� for ѭ����������ѡ�����Сֵ
			for (int coin : coins) {
				// �������޽⣬����
				if (i - coin < 0) continue;
				dp[i] = min(dp[i], 1 + dp[i - coin]);
			}
		}
		return (dp[amount] == amount + 1) ? -1 : dp[amount];
	}
};