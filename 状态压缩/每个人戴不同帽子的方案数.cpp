#include<bits/stdc++.h>
using namespace std;


using LL = long long;

class Solution {
private:
	static constexpr int mod = 1000000007;

public:
	int numberWays(vector<vector<int>>& hats) {
		int n = hats.size();
		// �ҵ�ñ�ӱ�ŵ����ֵ����������ֻ��Ҫ��� $f[maxhatid][2^n - 1]$ ��Ϊ��
		int maxHatId = 0;
		for (int i = 0; i < n; ++i) {
			for (int h : hats[i]) {
				maxHatId = max(maxHatId, h);
			}
		}

		// ����ÿһ��ñ�� h��hatToPerson[h] �д洢��ϲ���ⶥñ�ӵ������ˣ�������ж�̬�滮
		vector<vector<int>> hatToPerson(maxHatId + 1);
		for (int i = 0; i < n; ++i) {
			for (int h : hats[i]) {
				hatToPerson[h].push_back(i);
			}
		}

		vector<vector<int>> f(maxHatId + 1, vector<int>(1 << n));
		// �߽�����
		f[0][0] = 1;
		for (int i = 1; i <= maxHatId; ++i) {
			for (int mask = 0; mask < (1 << n); ++mask) {
				f[i][mask] = f[i - 1][mask];
				for (int j : hatToPerson[i]) {
					if (mask & (1 << j)) {
						f[i][mask] += f[i - 1][mask ^ (1 << j)];
						f[i][mask] %= mod;
					}
				}
			}
		}

		return f[maxHatId][(1 << n) - 1];
	}
};

