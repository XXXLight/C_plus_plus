#include<bits/stdc++.h>
using namespace std;



// �󷽰���Ŀ�����嶯̬�滮�ĳ�ʼ�����͵��ƹ�ϵ���Ӿ�����

class Solution {
public:
	long long dp1[100002], dp2[100002];
	const int mod = 1e9 + 7;
	int countTexts(string pressedKeys) {
		int n = pressedKeys.size();
		dp1[0] = 1, dp1[1] = 1, dp1[2] = 2;
		for (int i = 3; i <= 100001; i++) {
			dp1[i] = ((dp1[i - 1] % mod) + (dp1[i - 2] % mod) + (dp1[i - 3] % mod)) % mod;
		}
		dp2[0] = 1, dp2[1] = 1, dp2[2] = 2, dp2[3] = 4;
		for (int i = 4; i <= 100001; i++) {
			dp2[i] = ((dp2[i - 1] % mod) + (dp2[i - 2] % mod) + (dp2[i - 3] % mod) + (dp2[i - 4] % mod)) % mod;
		}
		long long  res = 1;
		// ע��forѭ����д��
		for (int i = 0; i < n;) {
			// ��ĸ����Ӧ��Ƶ��
			char cur = pressedKeys[i];
			int cnt = 0;
			while (cur == pressedKeys[i]) {
				cnt++;
				i++;
			}
			int u = cur - '0', v = cnt;
			if (u == 7 || u == 9) {
				res = ((res%mod)*(dp2[v] % mod)) % mod;
			}
			else {
				res = ((res%mod)*(dp1[v] % mod)) % mod;
			}
		}
		return res;
	}
};