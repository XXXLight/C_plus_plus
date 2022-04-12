#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		// lower_bound�����þ���ʹ�ö��ַ��ӿ��ҵ�����λ��
		return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	}
};


// while(l<r)
class Solution {
public:
	int left_bound(vector<int>& nums, int target) {
		int left = 0, right = nums.size();
		// ��������Ϊ [left, right]
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				// ���������Ϊ [mid+1, right]
				left = mid + 1;
			}
			else if (nums[mid] > target) {
				// ���������Ϊ [left, mid-1]
				right = mid;
			}
			else if (nums[mid] == target) {
				// �����Ҳ�߽�
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
		// ��������Ϊ [left, right]
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				// ���������Ϊ [mid+1, right]
				left = mid + 1;
			}
			else if (nums[mid] > target) {
				// ���������Ϊ [left, mid-1]
				right = mid - 1;
			}
			else if (nums[mid] == target) {
				// �����Ҳ�߽�
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
		// �ȿ��Ǳ߽����
		if (target > nums.back()) return nums.size();
		if (target < nums[0]) return 0;
		int left = 0, right = nums.size() - 1;
		// ��������Ϊ [left, right]
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				// ���������Ϊ [mid+1, right]
				left = mid + 1;
			}
			else if (nums[mid] > target) {
				// ���������Ϊ [left, mid-1]
				right = mid;
			}
			else if (nums[mid] == target) {
				// �����Ҳ�߽�
				right = mid;
			}
		}
		return left;
	}

	int searchInsert(vector<int>& nums, int target) {
		return left_bound(nums, target);
	}
};