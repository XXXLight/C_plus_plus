#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minArray(vector<int>& numbers) {
		int l = 0;
		int r = numbers.size() - 1;
		while (l < r) {
			int m = l + ((r - l) >> 1);
			// ��ʱnums[m]��������Сֵ������Խ��ȥ
			if (numbers[m] < numbers[r]) {
				r = m;
			}
			// ��ʱnums[m]һ��������Сֵ����Ϊnums[m]>nums[r],����ֱ��Խ��
			else if (numbers[m] > numbers[r]) {
				l = m + 1;
			}
			else {
				r -= 1;
			}
		}
		// l==r
		return numbers[l];
	}
};



