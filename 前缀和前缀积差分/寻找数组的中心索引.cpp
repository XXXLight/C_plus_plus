#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		vector<int> preSum, endSum; //ǰ׺�ͺ�����ǰ׺��
		preSum.push_back(0); //��0��ʼ�ۼ�
		endSum.push_back(0); //��0��ʼ�ۼ�
		//ǰ׺��
		int sum = 0;
		for (auto e : nums) {
			sum += e;//�ۼ�ģʽ
			preSum.push_back(sum);
		}
		//����ǰ׺��
		reverse(nums.begin(), nums.end());
		sum = 0;
		for (auto e : nums) {
			sum += e;//�ۼ�ģʽ
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