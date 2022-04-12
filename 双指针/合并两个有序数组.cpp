#include<bits/stdc++.h>
using namespace std;

// 就是归并排序的合并过程
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = 0, j = 0;
		int k = 0;
		vector<int> res = nums1;
		while (i < m&&j < n) {
			if (nums1[i] < nums2[j]) {
				res[k++] = nums1[i++];
			}
			else {
				res[k++] = nums2[j++];
			}
		}
		// 此时条件为 i>=m 或者 j>=n 即只有一个越界
		while (i < m) res[k++] = nums1[i++];
		while (j < n) res[k++] = nums2[j++];
		// 此时条件为 i>=m && j>=n 即两个都走到数组尾部
		nums1 = res;
	}
};