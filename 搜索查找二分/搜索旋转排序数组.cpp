#include<bits/stdc++.h>
using namespace std;



// ˼�����⣺���ֲ���һ����Ҫȫ��������
// ��Ȼ���ã���Ϊ�������֤�ˣ����Ը��ݾֲ�����������С����Ϳ�����




// ���ν�ϣ�������ʱ��ֱ����������ʱ����΢
// ����˼���ǣ������У��������е�ͬʱ���ı������򣬴Ӷ��жϳ�Ҫ���ҵ�ֵ���ĸ�����Ӷ����ж���
// ʱ�临�Ӷȣ�o(log(n))
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
		int l = 0, r = n - 1;// ��Ϊ����Ҫ�õ�nums[r],�������ȡn-1������n
		while (l <= r) {// ע���ǵȺ�,��Ϊ��[l,r]���䣬l=0,r=n-1���ǰ�����
			int m = l + ((r - l) >> 1); // ע������������ȼ���>>С��+
			if (nums[m] == target) return m;
			// �������
			if (nums[0] <= nums[m]) {
				// ���������taregt�����
				if (target >= nums[0] && target < nums[m]) {
					r = m - 1; // ����m����Ϊ��[l,m-1]��[m+1,r]���ǰ�����
				}
				// ���������taregt���ұ�
				else {
					l = m + 1; // ����m
				}
			}
			// �ұ�����
			else {
				// �ұ�������taregt���ұ�
				if (target > nums[m] && target <= nums[n - 1]) {
					l = m + 1; // ����m
				}
				// �ұ�������taregt�����
				else {
					r = m - 1;// ����m
				}
			}
		}
		return -1;
	}
};


// ȫ��ȡ�Ⱥ��ǿ��Ե�
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



// while(l<=r)������Ҫ����
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




// while(l<r)��Ҫ���У�[l,m]&[m+1,r]
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




// while(l<r)��Ҫ���У�[l,m-1]&[m,r]
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		int l = 0, r = len - 1;
		while (l < r) {
			int m = (l + r) / 2 + 1;// ע������+1ȷ��������ȡ��
			if (nums[m] == target) return m;
			if (nums[0] <= nums[m]) {
				if (target >= nums[0] && target <= nums[m]) {
					r = m - 1;// m-1��Ӧ�������mӦ��ȡ�ϱ߽�
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




