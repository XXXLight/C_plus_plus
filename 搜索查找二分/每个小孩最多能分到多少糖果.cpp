#include<bits/stdc++.h>
using namespace std;

// �͡����·;������ʱ�䡱��һ������Ŀ��ֻ������������

class Solution {
public:
	int maximumCandies(vector<int>& candies, long long k) {
		// �ж�ÿ��С���ֵ� i ���ǹ�ʱ�Ƿ��������Ҫ��
		auto check = [&](int i) -> bool {
			long long res = 0;
			for (int c : candies) {
				res += c / i;
			}
			return res >= k;
		};

		// ���ֲ���
		int l = 1;
		int r = 1 + *max_element(candies.begin(), candies.end());
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (check(mid)) {
				l = mid + 1;
			}
			else {
				r = mid;
			}
		}
		return l - 1;
	}
};





class Solution {
public:
	int maximumCandies(vector<int>& candies, long long k) {
		// �ж�ÿ��С���ֵ� i ���ǹ�ʱ�Ƿ��������Ҫ��,�ں������涨�庯�����Ѻ������ɱ���һ��
		auto check = [&](int i) -> bool {
			long long res = 0;
			for (int c : candies) {
				res += c / i;
			}
			return res >= k;
		};

		// ���ֲ���
		int l = 1;
		int r = 1 + *max_element(candies.begin(), candies.end());
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (check(mid)) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		return l - 1;
	}
};

