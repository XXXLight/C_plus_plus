#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		vector<int> dp(len, 1);
		for (int j = 1; j < len; j++) {
			for (int i = 0; i < j; i++) {
				// j是常量了，i是变量，dp[j]也是常量
				if (nums[i] < nums[j]) {
					dp[j] = max(dp[j], dp[i] + 1); //求数组的最大值
				}
			}
		}
		// 理解为什么
		return *max_element(dp.begin(), dp.end()); //注意返回的是dp数组中的最大值
	}
};


// 看不懂
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> d(nums.size(), INT_MAX);
		for (auto num : nums) *lower_bound(d.begin(), d.end(), num) = num;
		return lower_bound(d.begin(), d.end(), INT_MAX) - d.begin();
	}
};



// 与区间问题类似，都是对尾部元素动态维护，描述起来就是，往尾部放元素，比前面大直接放，比前面小进行二分查找下标进行替换
// res记录路径
// 画图加深理解
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		vector<int> res;
		res.push_back(nums[0]);
		for (int i = 1; i < len; i++) {
			if (nums[i] > res.back()) {
				res.push_back(nums[i]);
			}
			else {
				// 找>=nums[i]的index
				int index = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();// 注意这里必须减去res.begin()
				res[index] = nums[i];
			}
		}
		return res.size();
	}
};




// 调试输出，看每次动态更新的过程
class Solution {
public:
	void printDp(vector<int>& v) {
		for (auto e : v) cout << e << " ";
		cout << endl;
	}
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		vector<int> res;
		res.push_back(nums[0]);
		for (int i = 1; i < len; i++) {
			if (nums[i] > res.back()) {
				res.push_back(nums[i]);
			}
			else {
				// 找>=nums[i]的index
				int index = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();// 注意这里必须减去res.begin()
				res[index] = nums[i];
			}
			printDp(res);
		}
		return res.size();
	}
};