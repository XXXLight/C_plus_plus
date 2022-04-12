#include<bits/stdc++.h>
using namespace std;

// https://www.acwing.com/solution/content/41031/
class Solution {
public:
	int maxScore(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(1 << n, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				dp[(1 << i) | (1 << j)] = __gcd(nums[i], nums[j]);
			}
		}
		for (int i = 1; i < (1 << n); ++i) {
			if (__builtin_popcount(i) % 2) continue;
			for (int j = i; j != 0; j = (j - 1)&i) {
				if (__builtin_popcount(i) - __builtin_popcount(j) == 2) {
					dp[i] = max(dp[i], dp[j] + (__builtin_popcount(i) / 2)*dp[i^j]);
				}
			}
		}
		return dp[(1 << n) - 1];
	}
};



// �ȽϺ����İ汾
class Solution {
public:
	int gcd[15][15];
	int maxScore(vector<int>& nums) {
		int n = nums.size();
		//  gcd[i][j]��ʾnums[i]��nums[j]�����Լ��
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				gcd[i][j] = __gcd(nums[i], nums[j]);
			}
		}
		vector<int> dp(1 << n); //state
		for (int i = 0; i < (1 << n); i++) {
			int cnt = __builtin_popcount(i);// i��1�ĸ���
			if (cnt & 1) continue; // i����������1ֱ������
			cnt >>= 1; // cnt����Ŀ�е�i��Ҳ���ǵڼ��β���
			for (int j = 0; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					// i�ĵ�jλ��i�ĵ�kλ��1
					if ((i >> j) & 1 and (i >> k) & 1) {
						dp[i] = max(dp[i], dp[i - (1 << j) - (1 << k)] + cnt * gcd[j][k]);
					}
				}
			}
		}
		return dp[(1 << n) - 1];
	}
};


// ����bitset��λ�����е���
class Solution {
public:
	int gcd[15][15];
	int maxScore(vector<int>& nums) {
		int n = nums.size();
		//  gcd[i][j]��ʾnums[i]��nums[j]�����Լ��
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				gcd[i][j] = __gcd(nums[i], nums[j]);
			}
		}
		vector<int> dp(1 << n); //state
		for (int i = 0; i < (1 << n); i++) {
			int cnt = __builtin_popcount(i);// i��1�ĸ���
			if (cnt & 1) continue; // i����������1ֱ������
			cnt >>= 1; // cnt����Ŀ�е�i��Ҳ���ǵڼ��β���
			for (int j = 0; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					// i�ĵ�jλ��i�ĵ�kλ��1
					if ((i >> j) & 1 and (i >> k) & 1) {
						cout << bitset<6>(i) << " " << j << " " << k << " " << endl;
						dp[i] = max(dp[i], dp[i - (1 << j) - (1 << k)] + cnt * gcd[j][k]);
					}
				}
			}
		}
		return dp[(1 << n) - 1];
	}
};
