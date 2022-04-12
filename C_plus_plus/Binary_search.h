#pragma once
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int binary_search(vector<int> &nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else if (nums[mid] > target) {
			right = mid - 1;
		}
	}
	return -1;
}


int left_bound(vector<int> &nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] == target) {
			right = mid - 1;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else if (nums[mid] > target) {
			right = mid - 1;
		}
	}
	// 最后要检查 left 越界的情况
	if (left >= nums.size() || nums[left] != target)
		return -1;
	return left;
}


int right_bound(vector<int> &nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] == target) {
			left = mid + 1;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else if (nums[mid] > target) {
			right = mid - 1;
		}
	}
	// 最后要检查 right 越界的情况
	if (right < 0 || nums[right] != target)
		return -1;
	return right;
}


