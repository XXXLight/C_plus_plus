#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0;
		int left = 0, right = height.size() - 1;
		int leftMax = 0, rightMax = 0;
		while (left < right) {
			leftMax = max(leftMax, height[left]);
			rightMax = max(rightMax, height[right]);
			if (height[left] < height[right]) {
				ans += leftMax - height[left];
				++left;
			}
			else {
				ans += rightMax - height[right];
				--right;
			}
		}
		return ans;
	}
};

class Solution {
public:
	int trap(vector<int>& height) {
		int res = 0;
		int leftMax = 0, rightMax = 0;
		int len = height.size();
		int left = 0, right = len - 1;
		while (left <= right) {
			if (leftMax < rightMax) {
				res += max(0, leftMax - height[left]);
				leftMax = max(leftMax, height[left]);
				left++;
			}
			else {
				res += max(0, rightMax - height[right]);
				rightMax = max(rightMax, height[right]);
				right--;
			}
		}
		return res;
	}
};

