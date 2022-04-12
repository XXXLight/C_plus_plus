// https://github.com/labuladong/fucking-algorithm/blob/master/%E7%AE%97%E6%B3%95%E6%80%9D%E7%BB%B4%E7%B3%BB%E5%88%97/%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE%E8%AF%A6%E8%A7%A3.md
#include<bits/stdc++.h>
using namespace std;

// 不重复且有序的情况下查找元素
//寻找一个数（基本的二分搜索）
int binarySearch(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1; // 注意
	// l=r时循环仍然执行，此时m=(l+r)/2=l=r,无论是更新l=m+1还是r=m-1都有l=r+1,也满足l>r的退出循环条件
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			left = mid + 1; // 注意
		else if (nums[mid] > target)
			right = mid - 1; // 注意
	}
	return -1;
}


// 有序且有重复元素的情况下查找左边界
// left_bound
int left_bound(vector<int>& nums, int target) {
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
	// 1 2 2 3 4查找6
	// 检查出界情况
	if (left >= nums.size() || nums[left] != target)
		return -1;
	return left;
}



// 有序且有重复元素的情况下查找右边界
// right_bound
int right_bound(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] < target) {
			left = mid + 1;
		}
		else if (nums[mid] > target) {
			right = mid - 1;
		}
		else if (nums[mid] == target) {
			// 别返回，锁定右侧边界
			left = mid + 1;
		}
	}
	//  1 2 2 2 3 4查找0
	// 最后要检查 right 越界的情况
	if (right < 0 || nums[right] != target)
		return -1;
	return right;
}





//while (l <= r)时，l = r时，m = (l + r) / 2 = l = r, 更新时r = m - 1，此时l = m, 所以l = r + 1；更新l = m + 1时，r = m, 所以l = r + 1, 都满足退出条件
//while (l < r)时，l+1 = r时，m = (l + r) / 2 = l,r=m+1, 更新时r = m，此时l = m, 所以l = r；更新l = m + 1时，r = m+1, 所以l = r , 都满足退出条件


// 数字范围是10^5且求最值的时候想到使用二分法
