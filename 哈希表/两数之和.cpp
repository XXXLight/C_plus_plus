#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// ʱ�临�Ӷȣ�o(n)
// �ռ临�Ӷȣ�o(n),��Ҫ�ǿ���ϣ��
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mp;
		for (int i = 0; i < nums.size(); ++i) {
			if (mp.count(target - nums[i])) {
				return { mp[target - nums[i]], i };
			}
			mp[nums[i]] = i; //������������ں���
		}
		return {};
	}
};