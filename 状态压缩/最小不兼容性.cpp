#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minimumIncompatibility(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> value(1 << n, -1);
		vector<int> freq(n + 1);
		for (int sub = 0; sub < (1 << n); ++sub) {
			// �ж� sub �Ƿ��� n/k �� 1
			if (__builtin_popcount(sub) == n / k) {
				// ʹ��������м���
				for (int j = 0; j < n; ++j) {
					if (sub & (1 << j)) {
						++freq[nums[j]];
					}
				}
				// ����һ�������ܳ��ֳ��� 1 ��
				bool flag = true;
				for (int j = 1; j <= n; ++j) {
					if (freq[j] > 1) {
						flag = false;
						break;
					}
				}
				// �������Ҫ����ô���� sub �Ĳ�������
				if (flag) {
					int lb = INT_MAX, rb = INT_MIN;
					for (int j = 1; j <= n; ++j) {
						if (freq[j] > 0) {
							lb = min(lb, j);
							rb = max(rb, j);
						}
					}
					value[sub] = rb - lb;
				}
				// ��������ʹ��������м��������Ҫ������ָ�ԭ״
				for (int j = 0; j < n; ++j) {
					if (sub & (1 << j)) {
						--freq[nums[j]];
					}
				}
			}
		}

		vector<int> f(1 << n, -1);
		f[0] = 0;
		for (int mask = 1; mask < (1 << n); ++mask) {
			// �ж� mask �Ƿ��� n/k ������ 1
			if (__builtin_popcount(mask) % (n / k) == 0) {
				// ö���Ӽ�
				for (int sub = mask; sub; sub = (sub - 1) & mask) {
					if (value[sub] != -1 && f[mask ^ sub] != -1) {
						if (f[mask] == -1) {
							f[mask] = f[mask ^ sub] + value[sub];
						}
						else {
							f[mask] = min(f[mask], f[mask ^ sub] + value[sub]);
						}
					}
				}
			}
		}

		return f[(1 << n) - 1];
	}
};
