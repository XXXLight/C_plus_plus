#include<bits/stdc++.h>
using namespace std;

// 从山顶向两边扩展
// a&&b,如果b条件依赖a条件，则a放前面
class Solution {
public:
	int longestMountain(vector<int>& arr) {
		int len = arr.size();
		if (len <= 2) return 0;
		int res = 0;
		for (int i = 1; i < len - 1; i++) {
			int l = 0, r = 0;
			// 山顶向两边走，形象化理解为下山的过程
			if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {//先定位到山顶
				l = i - 1;
				r = i + 1;
				// 下山
				while (l >= 1 && arr[l] > arr[l - 1]) l--; // 索引条件放在最前面，类似检查栈！empty()
				while (r <= len - 2 && arr[r] > arr[r + 1]) r++; // 索引条件放在最前面，类似检查栈！empty()
			}
			// 指针走到山底了，更新答案位置
			res = max(res, r - l + 1);
		}
		if (res == 1) return 0;
		return res;
	}
};



class Solution {
public:
	int longestMountain(vector<int>& arr) {
		int len = arr.size();
		int res = 0;
		for (int i = 1; i < len - 1; i++) {
			// 找到山顶 
			if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) {
				int l = i - 1, r = i + 1;
				// 从左山腰往下走
				while (l >= 1 && arr[l] > arr[l - 1]) l--;
				// 从右山腰往下走
				while (r<len - 1 && arr[r]>arr[r + 1]) r++;
				//指针移到底再更新结果
				res = max(res, r - l + 1);
			}
		}
		return res;
	}
};



class Solution {
public:
	int longestMountain(vector<int>& A) {
		int maxLength = 0;
		int i = 1;

		while (i < A.size()) {
			int increasing = 0, decreasing = 0;

			while (i < A.size() && A[i - 1] < A[i]) i++, increasing++;
			while (i < A.size() && A[i - 1] > A[i]) i++, decreasing++;

			if (increasing > 0 && decreasing > 0)
				maxLength = max(maxLength, increasing + decreasing + 1);

			while (i < A.size() && A[i - 1] == A[i]) i++;
		}
		return maxLength;
	}
};

