#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int totalStrength(vector<int> &strength) {
		const int mod = 1e9 + 7;

		int n = strength.size();
		vector<int> left(n, -1); // left[i] Ϊ����ϸ�С�� strength[i] �����Ԫ��λ�ã�������ʱΪ -1��
		vector<int> right(n, n); // right[i] Ϊ�Ҳ�С�ڵ��� strength[i] �����Ԫ��λ�ã�������ʱΪ n��
		stack<int> st;
		for (int i = 0; i < n; ++i) {
			while (!st.empty() && strength[st.top()] >= strength[i]) {
				right[st.top()] = i;
				st.pop();
			}
			if (!st.empty()) left[i] = st.top();
			st.push(i);
		}

		long s = 0L; // ǰ׺��
		vector<int> ss(n + 2); // ǰ׺�͵�ǰ׺��
		for (int i = 1; i <= n; ++i) {
			s += strength[i - 1];
			ss[i + 1] = (ss[i] + s) % mod;
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			long l = left[i] + 1, r = right[i] - 1; // [l,r] ����ұ�
			long tot = ((i - l + 1) * (ss[r + 2] - ss[i + 1]) - (r - i + 1) * (ss[i + 1] - ss[l])) % mod;
			ans = (ans + strength[i] * tot) % mod; // �ۼӹ���
		}
		return (ans + mod) % mod; // ��ֹ�����������Ϊ������ tot �и�������
	}
};
