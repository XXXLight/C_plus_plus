#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//   k i j
// dp[i][j]=dp[][]
//  ʹ��memset()������ʼ����ά����ʱҪǧ��С�ģ�
//	1.��ά������������memset()������ʼ��ʱ��ֻ�ܳ�ʼ��Ϊ0���� - 1�������ά���������ֵ��Ϊ�������
//	2.��άchar��������memset()������ʼ��ʱ�������ƣ��ɳ�ʼ��Ϊ�����ַ���
class Solution {
public:
	int longestArithSeqLength(vector<int>& A) {
		unordered_map<int, int> mp;
		int n = A.size();
		vector<vector<int>> dp(n, vector<int>(n, 2));
		int ans = 0;
		// ��������������Ҫ��0��ʼ
		for (int i = 0; i < n; i++) {
			// ��ʱ��dp [0,i-1]
			for (int j = i + 1; j < n; j++) {
				int target = 2 * A[i] - A[j];  // �Ȳ����й�ʽ��2*A[i]=A[k]+A[j]
				// if (mp.count(target))������������
				// ֻ�������ϵ�Ÿ���dp���飬����dp����
				if (mp.count(target)) dp[i][j] = dp[mp[target]][i] + 1;
				ans = max(ans, dp[i][j]);
			}
			mp[A[i]] = i;
		}
		return ans;
	}
};