#include<bits/stdc++.h>
using namespace std;

// 空间换时间
// [0,i] [i] [i+1,len-1] 左小右大 左大右小
class Solution {
public:
	int numTeams(vector<int>& rating) {
		int len = rating.size();
		vector<int> left_big(len, 0);
		vector<int> left_small(len, 0);
		vector<int> right_big(len, 0);
		vector<int> right_small(len, 0);
		for (int i = 1; i < len - 1; i++) {
			int tmp = rating[i];
			int cnt_left_big = 0;
			int cnt_left_small = 0;
			int cnt_right_big = 0;
			int cnt_right_small = 0;
			for (int j = 0; j < i; j++) {
				if (tmp < rating[j]) {
					cnt_left_big++;
				}
				else if (tmp > rating[j]) {
					cnt_left_small++;
				}
			}
			for (int j = i + 1; j < len; j++) {
				if (tmp < rating[j]) {
					cnt_right_big++;
				}
				else if (tmp > rating[j]) {
					cnt_right_small++;
				}
			}
			left_big[i] = cnt_left_big;
			left_small[i] = cnt_left_small;
			right_big[i] = cnt_right_big;
			right_small[i] = cnt_right_small;
		}
		int res = 0;
		for (int i = 1; i < len - 1; i++) {
			res += left_big[i] * right_small[i] + left_small[i] * right_big[i];
		}
		return res;
	}
};