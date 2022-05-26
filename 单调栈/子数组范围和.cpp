#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	long long subArrayRanges(vector<int>& nums) {
		int n = nums.size();
		vector<int> minLeft(n), minRight(n), maxLeft(n), maxRight(n);
		stack<int> minStack, maxStack;
		for (int i = 0; i < n; i++) {
			while (!minStack.empty() && nums[minStack.top()] > nums[i]) {
				minStack.pop();
			}
			minLeft[i] = minStack.empty() ? -1 : minStack.top();
			minStack.push(i);

			// ��� nums[maxStack.top()] == nums[i], ��ô���ݶ��壬
			// nums[maxStack.top()] �߼���С�� nums[i]����Ϊ maxStack.top() < i
			while (!maxStack.empty() && nums[maxStack.top()] <= nums[i]) {
				maxStack.pop();
			}
			maxLeft[i] = maxStack.empty() ? -1 : maxStack.top();
			maxStack.push(i);
		}
		minStack = stack<int>();
		maxStack = stack<int>();
		for (int i = n - 1; i >= 0; i--) {
			// ��� nums[minStack.top()] == nums[i], ��ô���ݶ��壬
			// nums[minStack.top()] �߼��ϴ��� nums[i]����Ϊ minStack.top() > i
			while (!minStack.empty() && nums[minStack.top()] >= nums[i]) {
				minStack.pop();
			}
			minRight[i] = minStack.empty() ? n : minStack.top();
			minStack.push(i);

			while (!maxStack.empty() && nums[maxStack.top()] < nums[i]) {
				maxStack.pop();
			}
			maxRight[i] = maxStack.empty() ? n : maxStack.top();
			maxStack.push(i);
		}

		long long sumMax = 0, sumMin = 0;
		for (int i = 0; i < n; i++) {
			sumMax += static_cast<long long>(maxRight[i] - i) * (i - maxLeft[i]) * nums[i];
			sumMin += static_cast<long long>(minRight[i] - i) * (i - minLeft[i]) * nums[i];
		}
		return sumMax - sumMin;
	}
};

