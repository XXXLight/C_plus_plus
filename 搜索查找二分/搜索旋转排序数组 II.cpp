#include<bits/stdc++.h>
using namespace std;

//���ֲ���ʱ���ܻ��� a[l] = a[mid] = a[r]��
//��ʱ�޷��ж����� �ĸ��������
// �ʱ�临�Ӷȣ�o(n),����Ԫ�������Ҫ���ҵ�����������
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
		while (l <= r) { //�����ǵ��ں�
			int mid = (l + r) / 2;
			if (nums[mid] == target) {
				return true;
			}
			// ע���������if������while
			if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
				++l;
				--r;
			}
			else if (nums[l] <= nums[mid]) { //�����ǵ��ں�
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


// while(l<r),��Ҫ��l==rʱ����,[l.m]&[m+1,r]
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 1) return nums[0] == target;
		int l = 0, r = len - 1;// ע������r����������
		while (l < r) {
			int m = (l + r) / 2;
			if (nums[m] == target) return true;
			if (nums[m] == nums[l] && nums[m] == nums[r]) {
				l++; r--;
			}
			else if (nums[l] <= nums[m]) {
				if (target >= nums[l] && target <= nums[m]) {
					r = m;// ����m-1
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
					r = m;// ����m-1
				}
			}
		}
		// l==r��û���ж�
		return nums[l] == target;
	}
};



// while(l<r),��Ҫ��l==rʱ����,[l,m-1]&[m,r]
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 1) return nums[0] == target;
		int l = 0, r = len - 1;// ע������r����������
		while (l < r) {
			int m = (l + r) / 2 + 1;
			if (nums[m] == target) return true;
			if (nums[m] == nums[l] && nums[m] == nums[r]) {
				l++; r--;
			}
			else if (nums[l] <= nums[m]) {
				if (target >= nums[l] && target <= nums[m]) {
					r = m - 1;// ����m-1
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
					r = m - 1;// ����m-1
				}
			}
		}
		// l==r��û���ж�
		return nums[l] == target;
	}
};


// while(l<=r)������Ҫ����
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