#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		// lower_bound的作用就是使用二分法加快找到插入位置
		return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	}
};


// while(l<r)
class Solution {
public:
	int left_bound(vector<int>& nums, int target) {
		int left = 0, right = nums.size();
		// 搜索区间为 [left, right]
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				// 搜索区间变为 [mid+1, right]
				left = mid + 1;
			}
			else if (nums[mid] > target) {
				// 搜索区间变为 [left, mid-1]
				right = mid;
			}
			else if (nums[mid] == target) {
				// 收缩右侧边界
				right = mid;
			}
		}
		return left;
	}

	int searchInsert(vector<int>& nums, int target) {
		return left_bound(nums, target);
	}
};



class Solution {
public:
	int left_bound(vector<int>& nums, int target) {
		if (target > nums.back()) return nums.size();
		if (target < nums[0]) return 0;
		int left = 0, right = nums.size() - 1;
		// 搜索区间为 [left, right]
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				// 搜索区间变为 [mid+1, right]
				left = mid + 1;
			}
			else if (nums[mid] > target) {
				// 搜索区间变为 [left, mid-1]
				right = mid - 1;
			}
			else if (nums[mid] == target) {
				// 收缩右侧边界
				right = mid - 1;
			}
		}
		return left;
	}

	int searchInsert(vector<int>& nums, int target) {
		return left_bound(nums, target);
	}
};




class Solution {
public:
	int left_bound(vector<int>& nums, int target) {
		// 先考虑边界情况
		if (target > nums.back()) return nums.size();
		if (target < nums[0]) return 0;
		int left = 0, right = nums.size() - 1;
		// 搜索区间为 [left, right]
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				// 搜索区间变为 [mid+1, right]
				left = mid + 1;
			}
			else if (nums[mid] > target) {
				// 搜索区间变为 [left, mid-1]
				right = mid;
			}
			else if (nums[mid] == target) {
				// 收缩右侧边界
				right = mid;
			}
		}
		return left;
	}

	int searchInsert(vector<int>& nums, int target) {
		return left_bound(nums, target);
	}
};