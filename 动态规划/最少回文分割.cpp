#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		int len = s.size();
		vector<vector<bool>> isPal(len, vector<bool>(len)); //������j��i֮�䣬�Ƿ��ǻ��ġ�����n2�ռ���ʱ�䡣
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j <= i; ++j) {//Ҫ��¼���а����Լ�������ĸ�������������ͷ���Ǳ�����
			//��β����Ǳ�Ҫ�������ټ�һ��Ҫô���߼�е���ĸС��2  ���� ���߼���ֶ�ȷ���ǻ��ģ����ɳ��������
				if (s[i] == s[j] && (i - j <= 1 || isPal[j + 1][i - 1]))//�������isPal����ȷ��i-1ʱ�Ѿ��洢�˽��
					isPal[j][i] = true;
			}
		}

		vector<int> dp(len);
		for (int i = 0; i < len; ++i) {
			if (isPal[0][i])
				dp[i] = 0;//�ȿ���ò��÷ָ����������У�����ͷ�����б������������ O(n2)
			else {
				dp[i] = i;//�����У�������
				for (int j = 1; j <= i; ++j) {
					if (isPal[j][i])// 0�������ˣ���1��i��ʼ�������п��������и�Ŀ���
						dp[i] = min(dp[i], dp[j - 1] + 1);// һ���ҵ������ϣ��Ǿ���֮ǰ����̼�����һ�ε�1
				}
			}
		}
		return dp[len - 1];
	}
};

