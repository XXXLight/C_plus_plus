#include<bits/stdc++.h>
using namespace std;


// �� ������Ϊk����ȵ��Ӽ���һģһ��
class Solution {
	int dp[(1 << 16) + 2];
public:
	bool makesquare(vector<int>& nums) {
		int n = nums.size();
		int k = 4;
		fill(dp, dp + (1 << 16) + 2, -1); // dp�����ʼ��Ϊ-1,int dp[(1 << 16) + 2]={-1};ֻ�Ὣ��һ��Ԫ������Ϊ-1
		int sum = accumulate(nums.begin(), nums.end(), 0); // ʹ��accumulate��ʽ���������
		if (sum % k != 0) return false; // ����������ֱ�ӷ���false
		int target = sum / k; // ÿ��ĺ�
		dp[0] = 0;
		// dp[mask]��ʾmask״̬ʱ�ܲ��ܱ�target��������[3,3,2,1] 3ʱ��dp[1100]=0��ʾѡ��2 1��������3
		for (int mask = 0; mask < (1 << n); mask++) {
			if (dp[mask] == -1) continue;
			for (int i = 0; i < n; i++) {
				// ���mask�ĵ�iλ��0����iλû��ѡ����ѡ���iλ�Ļ�������target
				if (!(mask & (1 << i)) && dp[mask] + nums[i] <= target) {
					// ��mask�ĵ�iλ��1����ѡ���iλ,ע�������λ�������λ�Ƿ�������
					dp[mask | (1 << i)] = (dp[mask] + nums[i]) % target; //�ܷ�պ�Ϊ0
					//cout<<bitset<4>(mask | (1 << i))<<" "<<bitset<4>(mask)<<" "<<dp[mask | (1 << i)]<<endl;
				}

			}
		}
		// cout<<"�ָ���"<<endl;
		// for(int i=0;i<(1<<4)+2;i++){
		//     cout<<bitset<4>(i)<<" "<<dp[i]<<endl;
		// }
		return dp[(1 << n) - 1] == 0; //  ������ȡ��
	}
};