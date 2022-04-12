#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {
		int left = 0;
		int right = arr.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (arr[mid] > arr[mid + 1]) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
};



class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {
		int left = 0;
		int right = arr.size() - 1;
		while (left < right) {
			int mid1 = left + (right - left) / 3;
			int mid2 = right - (right - left) / 3;
			if (arr[mid1] < arr[mid2]) {
				left = mid1 + 1;
			}
			else if (arr[mid1] >= arr[mid2]) {
				right = mid2 - 1;
			}
		}
		return left;
	}
};

