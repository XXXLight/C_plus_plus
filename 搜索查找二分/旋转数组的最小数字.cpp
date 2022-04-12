#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minArray(vector<int>& numbers) {
		int l = 0;
		int r = numbers.size() - 1;
		while (l < r) {
			int m = l + ((r - l) >> 1);
			// 此时nums[m]可能是最小值，不能越过去
			if (numbers[m] < numbers[r]) {
				r = m;
			}
			// 此时nums[m]一定不是最小值，因为nums[m]>nums[r],所以直接越过
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



