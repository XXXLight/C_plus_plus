#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//累加模式
class Solution {
public:
	int subarraySum(vector<int> &nums, int k) {
		int sum = 0, res = 0;
		unordered_map<int, int> cul;
		cul[0] = 1;
		for (auto &m : nums) {
			sum += m;
			res += cul[sum - k]; //截止当前的和为sum,如果哈希表中有sum-k,说明存在 sum-(sum-k)=k的连续子数组
			++cul[sum];
		}
		return res;
	}
};

//前项与后项递推模式
class Solution {
public:
	int subarraySum(vector<int> &nums, int k) {
		vector<int> sum(nums.size() + 1);//也可以不开数组直接在原来的数组上操作
		sum[0] = 0;
		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum[i + 1] = sum[i] + nums[i];//计算前缀和
		}
		unordered_map<int, int> mp;
		for (int i = 0; i < sum.size(); i++) {
			res += mp[sum[i] - k]; //这里不用作判断，直接加，有些情况下可以对sum[i]-k进行判断可以提高运行速率
			mp[sum[i]]++;
		}
		return res;;
	}
};
