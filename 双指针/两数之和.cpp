#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// ʱ�临�Ӷȣ�o(n)
// �ռ临�Ӷȣ�o(n)
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mp;
		// �ߵ�i��ʱ��hash��[0,i-1]
		for (int i = 0; i < nums.size(); i++) {
			if (mp.count(target - nums[i])) {
				return { i,mp[target - nums[i]] };
			}
			mp[nums[i]] = i;
		}
		return {};
	}
};