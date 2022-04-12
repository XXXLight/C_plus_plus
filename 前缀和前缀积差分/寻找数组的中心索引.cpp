#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		vector<int> preSum, endSum; //前缀和和逆向前缀和
		preSum.push_back(0); //从0开始累加
		endSum.push_back(0); //从0开始累加
		//前缀和
		int sum = 0;
		for (auto e : nums) {
			sum += e;//累加模式
			preSum.push_back(sum);
		}
		//逆向前缀和
		reverse(nums.begin(), nums.end());
		sum = 0;
		for (auto e : nums) {
			sum += e;//累加模式
			endSum.push_back(sum);
		}
		// i+j=nums.size()-1 ===>j=nums.size()-i-1
		for (int i = 0; i < nums.size(); i++) {
			if (preSum[i] == endSum[nums.size() - i - 1])
				return i;
		}
		return -1;
	}
};