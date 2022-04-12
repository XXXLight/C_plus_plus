// https://github.com/labuladong/fucking-algorithm/blob/master/%E7%AE%97%E6%B3%95%E6%80%9D%E7%BB%B4%E7%B3%BB%E5%88%97/%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE%E8%AF%A6%E8%A7%A3.md
#include<bits/stdc++.h>
using namespace std;

// ���ظ������������²���Ԫ��
//Ѱ��һ�����������Ķ���������
int binarySearch(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1; // ע��
	// l=rʱѭ����Ȼִ�У���ʱm=(l+r)/2=l=r,�����Ǹ���l=m+1����r=m-1����l=r+1,Ҳ����l>r���˳�ѭ������
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			left = mid + 1; // ע��
		else if (nums[mid] > target)
			right = mid - 1; // ע��
	}
	return -1;
}


// ���������ظ�Ԫ�ص�����²�����߽�
// left_bound
int left_bound(vector<int>& nums, int target) {
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
	// 1 2 2 3 4����6
	// ���������
	if (left >= nums.size() || nums[left] != target)
		return -1;
	return left;
}



// ���������ظ�Ԫ�ص�����²����ұ߽�
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
			// �𷵻أ������Ҳ�߽�
			left = mid + 1;
		}
	}
	//  1 2 2 2 3 4����0
	// ���Ҫ��� right Խ������
	if (right < 0 || nums[right] != target)
		return -1;
	return right;
}





//while (l <= r)ʱ��l = rʱ��m = (l + r) / 2 = l = r, ����ʱr = m - 1����ʱl = m, ����l = r + 1������l = m + 1ʱ��r = m, ����l = r + 1, �������˳�����
//while (l < r)ʱ��l+1 = rʱ��m = (l + r) / 2 = l,r=m+1, ����ʱr = m����ʱl = m, ����l = r������l = m + 1ʱ��r = m+1, ����l = r , �������˳�����


// ���ַ�Χ��10^5������ֵ��ʱ���뵽ʹ�ö��ַ�
