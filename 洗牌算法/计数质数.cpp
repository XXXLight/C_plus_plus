#include<bits/stdc++.h>
using namespace std;

// ʱ�临�Ӷȣ�O(N * loglogN)
// ���䷽���� ����true ---->ɾѡ----->��ͳ�ƣ����ɸѡ���̣�һģһ����
// 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17...�Լ�ģ��һ��
class Solution {
public:
	int countPrimes(int n) {
		// ���еı��Ϊtrue
		vector<bool> flag(n + 1, true);
		// ɸѡ���� [2,sqrt(n))
		for (int i = 2; i < sqrt(n); i++) {
			if (flag[i]) {
				for (int j = i * i; j < n; j += i) {
					flag[j] = false;
				}
			}
		}
		int cnt = 0;
		for (int i = 2; i < n; i++) {
			if (flag[i])
				cnt++;
		}
		return cnt;
	}
};