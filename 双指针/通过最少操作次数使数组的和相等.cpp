#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minOperations(vector<int>& a, vector<int>& b) {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		// 不需要傻傻地用sum
		int sa = accumulate(a.begin(), a.end(), 0);
		int sb = accumulate(b.begin(), b.end(), 0);
		// swap可以直接用来交换vector
		if (sa > sb) swap(sa, sb), swap(a, b);
		int i = 0, j = b.size() - 1;
		int cnt = 0;
		// 循环退出条件时sa>=sb，已经发生了越界，肯定能够使两者相等
		while (i < a.size() && 0 <= j && sa < sb) {
			if (6 - a[i] > b[j] - 1) { // 选择变化差值最大的一边
				sa += 6 - a[i++]; //从a中选
			}
			else sb -= b[j--] - 1; //从b中选
			++cnt;
		}
		while (i < a.size() && sa < sb) {
			sa += 6 - a[i++];
			++cnt;
		}
		while (0 <= j && sa < sb) {
			sb -= b[j--] - 1;
			++cnt;
		}
		return sa >= sb ? cnt : -1;
	}
};

