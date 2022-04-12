#include<iostream>
#include<vector>
using namespace std;

// Question1:怎么调试？ 
// 答：先确保归并的过程没有错误，程序都是调试出来的，而不是比对出来的，项目可以比对，程序需要调试
// 先确保[2,6,7,8//1,3,5,9]===>[1,2,3,5,6,7,8,9]的过程是对的


// 核心左右都是闭区间+双指针
void MergeSort(vector<int>&nums, int l, int r) {
	if (l == r)	return;  //递归基是让数组中的每个数单独成为长度为1的区间
	int m = (l + r) >>1;
	// 先分段排序
	MergeSort(nums, l, m);
	MergeSort(nums, m + 1, r);

	// 再合并
	int n = r - l + 1;//临时数组存合并后的有序序列
	int* tmp = new int[n]; //空间复杂度 o(n),开数组的方式挺好 vector<int> tmp(n)
	int i = 0, left = l, right = m + 1;
	while (left <= m && right <= r) //退出条件 left>m或right>r，即一个越界
		tmp[i++] = nums[left] <= nums[right] ? nums[left++] : nums[right++];
	// 处理没有越界的
	while (left <= m)
		tmp[i++] = nums[left++];
	while (right <= r)
		tmp[i++] = nums[right++];
	for (int j = 0; j < n; ++j)
		nums[l + j] = tmp[j]; // copy(tmp.begin(),tmp.end(),nums.begin()+l);
	delete[] tmp;//删掉堆区的内存，防止内存泄漏
}

int main() {
	vector<int>a = { 3,1,2,4,5,8,7,6 }; 
	MergeSort(a, 0, 7); // 因为是闭区间所以是[0,7]
	for (int i = 0; i < 8; ++i)
		cout << a[i] << " ";
}