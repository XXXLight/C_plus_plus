#include<bits/stdc++.h>
using namespace std;

//二分查找时可能会有 a[l] = a[mid] = a[r]，
//此时无法判断区间 哪个是有序的
// 最坏时间复杂度：o(n),所有元素相等且要查找的数不在里面
class Solution {
public:
	bool search(vector<int> &nums, int target) {
		int n = nums.size();
		if (n == 0) {
			return false;
		}
		if (n == 1) {
			return nums[0] == target;
		}
		int l = 0, r = n - 1;
		while (l <= r) { //必须是等于号
			int mid = (l + r) / 2;
			if (nums[mid] == target) {
				return true;
			}
			// 注意下面的是if而不是while
			if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
				++l;
				--r;
			}
			else if (nums[l] <= nums[mid]) { //必须是等于号
				if (nums[l] <= target && target < nums[mid]) {
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
			else {
				if (nums[mid] < target && target <= nums[n - 1]) {
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
		}
		return false;
	}
};


// while(l<r),需要在l==r时特判,[l.m]&[m+1,r]
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 1) return nums[0] == target;
		int l = 0, r = len - 1;// 注意这里r包含右区间
		while (l < r) {
			int m = (l + r) / 2;
			if (nums[m] == target) return true;
			if (nums[m] == nums[l] && nums[m] == nums[r]) {
				l++; r--;
			}
			else if (nums[l] <= nums[m]) {
				if (target >= nums[l] && target <= nums[m]) {
					r = m;// 不是m-1
				}
				else {
					l = m + 1;
				}
			}
			else {
				if (target >= nums[m] && target <= nums[r]) {
					l = m + 1;
				}
				else {
					r = m;// 不是m-1
				}
			}
		}
		// l==r处没有判断
		return nums[l] == target;
	}
};



// while(l<r),需要在l==r时特判,[l,m-1]&[m,r]
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 1) return nums[0] == target;
		int l = 0, r = len - 1;// 注意这里r包含右区间
		while (l < r) {
			int m = (l + r) / 2 + 1;
			if (nums[m] == target) return true;
			if (nums[m] == nums[l] && nums[m] == nums[r]) {
				l++; r--;
			}
			else if (nums[l] <= nums[m]) {
				if (target >= nums[l] && target <= nums[m]) {
					r = m - 1;// 不是m-1
				}
				else {
					l = m;
				}
			}
			else {
				if (target >= nums[m] && target <= nums[r]) {
					l = m;
				}
				else {
					r = m - 1;// 不是m-1
				}
			}
		}
		// l==r处没有判断
		return nums[l] == target;
	}
};


// while(l<=r)，不需要特判
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 1) return nums[0] == target;
		int l = 0, r = len - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (nums[m] == target) return true;
			if (nums[m] == nums[l] && nums[m] == nums[r]) {
				l++; r--;
			}
			else if (nums[l] <= nums[m]) {
				if (target >= nums[l] && target <= nums[m]) {
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}
			else {
				if (target >= nums[m] && target <= nums[r]) {
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
		}
		return false;
	}
};