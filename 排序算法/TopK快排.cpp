#include<bits/stdc++.h>
using namespace std;

// 参考文档：https://wiki.jikexueyuan.com/project/easy-learn-algorithm/fast-sort.html
// 6 1 2 7 9 3 4 5 10 8
// 理解1：正常排序最快的时间复杂度是o(nlogn),TopK快排时间复杂度是o(n)
class Solution {
public:
	// 两个哨兵，一个Base
	int quickSort(vector<int>&v, int l, int r, int k) {
		int i = l, j = r;
		while (i < j) {
			// 注意下面是有等号的，因为可以出现 1 2 2 3 3 3 3 4这样的重复
			while (i < j&&v[j] >= v[l]) j--;
			while (i < j&&v[i] <= v[l]) i++;
			if (i < j) swap(v[i], v[j]);
		}
		swap(v[i], v[l]);
		if (k < i - l + 1) return quickSort(v, l, i - 1, k);
		if (k > i - l + 1) return quickSort(v, i + 1, r, k - i + l - 1);
		if (k == i - l + 1) return v[i];
	}
	int smallestK(vector<int>& arr, int k) {
		int res = quickSort(arr, 0, arr.size() - 1, k);
		return res;
	}
};

int main() {
	vector<int> v = { 0,1,2,3,4,5,6 };
	int res = Solution().smallestK(v, 2);
	return 0;
}