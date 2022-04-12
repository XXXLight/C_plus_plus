#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
		int maxV = pow(2, maximumBit); // 2^maximumBit并不是计算指数的,而是异或
		int x = 0;
		for (auto e : nums) x ^= e;
		int m = -1;
		int index;
		for (int i = 0; i < maxV; i++) {
			if ((x^i) > m) { // 位运算出错注意优先级，一定要加括号，关于位运算加括号就完事了
				m = x ^ i;
				index = i;
			}
		}
		vector<int> res;
		res.push_back(index);
		reverse(nums.begin(), nums.end());
		for (auto e : nums) {
			index ^= e;
			res.push_back(index);
		}
		res.pop_back();
		return res;
	}
};