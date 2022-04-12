#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	int maxSum(vector<int>& nums1, vector<int>& nums2) {
		long sum1 = 0, sum2 = 0;
		long res = 0;
		int i = 0, j = 0;
		while (i < nums1.size() && j < nums2.size()) {
			if (nums1[i] == nums2[j]) {
				res += (max(sum1, sum2) + nums1[i]);
				sum1 = 0;
				sum2 = 0;
				i++;
				j++;
			}
			else if (nums1[i] < nums2[j]) {
				sum1 += nums1[i];
				i++;
			}
			else {
				sum2 += nums2[j];
				j++;
			}
		}
		while (i < nums1.size()) {
			sum1 += nums1[i];
			i++;
		}
		while (j < nums2.size()) {
			sum2 += nums2[j];
			j++;
		}
		res += max(sum1, sum2);
		return res % ((int)pow(10, 9) + 7);
	}
};