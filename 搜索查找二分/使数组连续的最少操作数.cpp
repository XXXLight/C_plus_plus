#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minOperations(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		nums.erase(unique(nums.begin(), nums.end()), nums.end());  //ȥ�صĿ⺯��

		int setLen = nums.size();
		int result = len;
		int r = 0;
		for (int l = 0; l < setLen; l++) {
			// �����ҵ��� nums[l] + len - 1 ��ֵ��ĵ�һ��λ��
			int temp = upper_bound(nums.begin(), nums.begin() + setLen - 1, nums[l] + len - 1) - nums.begin();
			//�ҵ�ĩβ��Ȼû���ҵ���ʱ���ж�һ��nums�����һ��Ԫ�غ�nums[l] + len - 1��ֵ�Ĵ�С
			if (nums[setLen - 1] <= nums[l] + len - 1) {
				temp++;
			}
			//while (r < setLen && nums[r] <= nums[l] + len - 1) {
				//r++;
			//}
			result = min(result, len - temp + l);
		}
		return result;
	}
};

