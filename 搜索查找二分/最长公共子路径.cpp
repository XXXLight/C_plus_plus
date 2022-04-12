#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
	// �������Ĳ��ֵķ���������ѡ��� mod ��ҪԶ���� 10^10
	// ���� C++ ������������Ҫ�õ� long long ����
	// ��ô�ڽ��й�ϣֵ������ʱ���м�ֵ�ᳬ�� long long ���͵����ޣ���û�и����������
	// ������ǿ���ʹ��һ�����еİ취���� mod1 �� mod2 �ֱ�ȡģ���õ�һ����Ԫ��
	// �Ȿ������� mod1 * mod2 ȡģ��һ�µģ���������ѡ�� mod1=10^9+7��mod2=10^9+9
	// ���Ƕ����������˻�ԼΪ 10^18��Զ���� 10^10
	static constexpr int mod1 = 1000000007;
	static constexpr int mod2 = 1000000009;

	// �������ǵõ��Ĺ�ϣ�Ƕ�Ԫ�飬C++ Ĭ�ϲ�֧�ֽ� pair �����ϣ��������Ҫ����ʵ�ֹ�ϣ����
	struct pairhash {
		size_t operator() (const pair<int, int>& p) const {
			auto fn = hash<int>();
			return (fn(p.first) << 16) ^ fn(p.second);
		}
	};

	using LL = long long;

public:
	int longestCommonSubpath(int n, vector<vector<int>>& paths) {
		// ����������Ԫ�صķ�ΧΪ [0, 10^5]
		// ��������� [10^6, 10^7] �ķ�Χ�����ѡȡ���� base
		// Ϊ�˸����ٳ�ͻ�����ǿ��Զ� mod1 �� mod2 �ֱ�ѡȡ base1 �� base2
		mt19937 gen{ random_device{}() };
		auto dis = uniform_int_distribution<int>(1e6, 1e7);
		int base1 = dis(gen);
		int base2 = dis(gen);

		int m = paths.size();
		// ȷ�����ֲ��ҵ����½�
		int left = 1, right = min_element(paths.begin(), paths.end(), [](const auto& p1, const auto& p2) {return p1.size() < p2.size(); })->size();
		int ans = 0;
		while (left <= right) {
			int len = (left + right) / 2;
			// Ԥ���� mult1=base1^len, mult2=base2^len
			int mult1 = 1, mult2 = 1;
			for (int i = 1; i <= len; ++i) {
				mult1 = (LL)mult1 * base1 % mod1;
				mult2 = (LL)mult2 * base2 % mod2;
			}

			unordered_set<pair<int, int>, pairhash> s;
			bool check = true;
			for (int i = 0; i < m; ++i) {
				int hash1 = 0, hash2 = 0;
				// �����׸�����Ϊ len ��������Ĺ�ϣֵ
				for (int j = 0; j < len; ++j) {
					hash1 = ((LL)hash1 * base1 + paths[i][j]) % mod1;
					hash2 = ((LL)hash2 * base2 + paths[i][j]) % mod2;
				}

				unordered_set<pair<int, int>, pairhash> t;
				// ������Ǳ������ǵ� 0 �����飬������һ������Ĺ�ϣ���а����ö�Ԫ��
				// ���ǲŻὫ��Ԫ����뵱ǰ����Ĺ�ϣ����
				if (i == 0 || s.count({ hash1, hash2 })) {
					t.emplace(hash1, hash2);
				}
				// ���Ƽ������������Ĺ�ϣֵ
				for (int j = len; j < paths[i].size(); ++j) {
					hash1 = (((LL)hash1 * base1 % mod1 - (LL)paths[i][j - len] * mult1 % mod1 + paths[i][j]) % mod1 + mod1) % mod1;
					hash2 = (((LL)hash2 * base2 % mod2 - (LL)paths[i][j - len] * mult2 % mod2 + paths[i][j]) % mod2 + mod2) % mod2;
					if (i == 0 || s.count({ hash1, hash2 })) {
						t.emplace(hash1, hash2);
					}
				}
				if (t.empty()) {
					check = false;
					break;
				}
				s = move(t);
			}

			if (check) {
				ans = len;
				left = len + 1;
			}
			else {
				right = len - 1;
			}
		}
		return ans;
	}
};

