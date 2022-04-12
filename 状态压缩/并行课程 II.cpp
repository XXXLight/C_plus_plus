#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
		vector<int> prerequisite(n, 0);
		for (const auto& pair : relations) {
			int pre = pair[0] - 1;
			int after = pair[1] - 1;
			// ������prerequisite[1] = 0110 ��ʾ1�����޿�Ϊ2��3
			prerequisite[after] |= 1 << pre;
		}

		int totalState = 1 << n;
		vector<int> dp(totalState, 16);
		// 0Ϊ����Ҫ���κοε�״̬����˲���Ҫѧ��
		dp[0] = 0;

		vector<int> cnt(totalState);
		cnt[0] = 0;
		// С���ɣ�����ÿ�����ֵĶ��������У�1�ĸ���
		for (int i = 1; i < totalState; ++i) {
			cnt[i] = cnt[i >> 1] + (i & 1);
		}

		// taken��ʾ�Ѿ��Ϲ��ĿΣ�����taken = 0111����ʾ�γ�1 2 3�Ѿ��Ϲ���
		for (int taken = 0; taken < totalState; ++taken) {
			if (dp[taken] > n) continue;
			int cur = 0;
			// ���Ϲ�taken�Ļ����ϣ�������Щ�ο����ϣ�Ҫ������������
			// 1. ((taken & (1 << j)) == 0) ��ʾ�������taken��û�Ϲ�
			// 2. ((prerequisite[j] & taken) == prerequisite[j]) ��ʾ����ε����޿��Ѿ�������
			for (int j = 0; j < n; ++j) {
				if (((taken & (1 << j)) == 0) && ((prerequisite[j] & taken) == prerequisite[j])) {
					// ����ѧ�ڿ����ϵĿΣ�ע�⣬�����ϲ�����һ��Ҫ�ϣ�Ҳ��һ��Ҫ����������ı�����NPC���⣬�κ�̰�ĵ�˼�붼�Ǵ�ģ�ѡ��cur�еĿ����ϵ����������������ö���Ӽ��ķ���ʵ��
					cur |= (1 << j);
				}
			}
			// ö��cur���Ӽ�������cur = 111��������mask���Ͼ���{111, 110, 101 011, 100, 010, 001}
			for (int subMask = cur; subMask != 0; subMask = subMask - 1 & cur) {
				// ��ѧ���ϵĿε��������ܳ���k
				if (cnt[subMask] <= k) {
					// ֮ǰ����taken����ѧ������subMask�������᲻�����
					dp[taken | subMask] = min(dp[taken | subMask], dp[taken] + 1);
				}
			}
		}

		return dp[totalState - 1];
	}
};

