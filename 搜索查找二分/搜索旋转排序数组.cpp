#include<bits/stdc++.h>
using namespace std;



// 思考问题：二分查找一定需要全局有序吗？
// 显然不用，因为本题就验证了，可以根据局部有序性来缩小区间就可以了




// 数形结合，数无形时少直觉，形少数时难入微
// 核心思想是：二分切，并且在切的同时看哪边是有序，从而判断出要查找的值在哪个区间从而进行二分
// 时间复杂度：o(log(n))
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		if (!n) {
			return -1;
		}
		if (n == 1) {
			return nums[0] == target ? 0 : -1;
		}
		int l = 0, r = n - 1;// 因为后面要用到nums[r],所以最好取n-1而不是n
		while (l <= r) {// 注意是等号,因为是[l,r]区间，l=0,r=n-1都是包含的
			int m = l + ((r - l) >> 1); // 注意运算符的优先级，>>小于+
			if (nums[m] == target) return m;
			// 左边有序
			if (nums[0] <= nums[m]) {
				// 左边有序且taregt在左边
				if (target >= nums[0] && target < nums[m]) {
					r = m - 1; // 不是m，因为是[l,m-1]和[m+1,r]都是包含的
				}
				// 左边有序且taregt在右边
				else {
					l = m + 1; // 不是m
				}
			}
			// 右边有序
			else {
				// 右边有序且taregt在右边
				if (target > nums[m] && target <= nums[n - 1]) {
					l = m + 1; // 不是m
				}
				// 右边有序且taregt在左边
				else {
					r = m - 1;// 不是m
				}
			}
		}
		return -1;
	}
};


// 全部取等号是可以的
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		int l = 0, r = len - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (nums[m] == target) return m;
			if (nums[0] <= nums[m]) {
				if (target >= nums[0] && target <= nums[m]) {
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}
			else {
				if (target >= nums[m] && target <= nums[len - 1]) {
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
		}
		return -1;
	}
};



// while(l<=r)，不需要特判
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		int l = 0, r = len - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (nums[m] == target) return m;
			if (nums[0] <= nums[m]) {
				if (target >= nums[0] && target <= nums[m]) {
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
		return -1;
	}
};




// while(l<r)需要特判，[l,m]&[m+1,r]
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		int l = 0, r = len - 1;
		while (l < r) {
			int m = (l + r) / 2;
			if (nums[m] == target) return m;
			if (nums[0] <= nums[m]) {
				if (target >= nums[0] && target <= nums[m]) {
					r = m;
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
					r = m;
				}
			}
		}
		return nums[l] == target ? l : -1;
	}
};




// while(l<r)需要特判，[l,m-1]&[m,r]
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		int l = 0, r = len - 1;
		while (l < r) {
			int m = (l + r) / 2 + 1;// 注意这里+1确保是向上取整
			if (nums[m] == target) return m;
			if (nums[0] <= nums[m]) {
				if (target >= nums[0] && target <= nums[m]) {
					r = m - 1;// m-1对应的情况下m应当取上边界
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
					r = m - 1;
				}
			}
		}
		return nums[l] == target ? l : -1;
	}
};




