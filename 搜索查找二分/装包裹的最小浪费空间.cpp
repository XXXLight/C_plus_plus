#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
	using LL = long long;

	static constexpr int MOD = 1000000007;

public:
	int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
		int n = packages.size();
		sort(packages.begin(), packages.end());

		// �������� packages ��ǰ׺��
		vector<LL> pre(n + 1);
		for (int i = 1; i <= n; ++i) {
			pre[i] = pre[i - 1] + packages[i - 1];
		}

		// ����������ͨ��ǰ׺�����飬�õ����� packages[left..right] �ĺ�
		auto get = [&](int left, int right) {
			return pre[right + 1] - pre[left];
		};

		LL ans = LLONG_MAX;
		for (auto& box : boxes) {
			sort(box.begin(), box.end());
			// С�Ż�������������ĳߴ����������ӵĳߴ磬��ôһ�������㣬ֱ������
			if (packages.back() > box.back()) {
				continue;
			}

			// ��ʼ��ָ�� pt����ָ��δ���������ӵĵ�һ������
			auto pt = packages.begin();
			// ���˷ѿռ�
			LL total = 0;

			for (int y : box) {
				// С�Ż��������ǰ���� y �ĳߴ�С�� pt ָ��İ�������ô������ж��ֲ���
				if (y < *pt) {
					continue;
				}

				// pt'
				auto pt_next = prev(upper_bound(pt, packages.end(), y));

				total += (LL)(pt_next - pt + 1) * y - get(pt - packages.begin(), pt_next - packages.begin());
				pt = next(pt_next);
				// С�Ż���������а������Ѿ����������ӣ�������ǰ�˳�
				if (pt == packages.end()) {
					break;
				}
			}
			ans = min(ans, total);
		}

		return (ans == LLONG_MAX ? -1 : ans % MOD);
	}
};

