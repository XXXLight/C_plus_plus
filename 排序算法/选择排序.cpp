//#include<bits/stdc++.h>
//using namespace std;
//
//void selectionSort(vector<int>&nums) {
//	int len = nums.size();
//	int minindex, temp;
//	for (int i = 0; i < len - 1; i++) {
//		minindex = i;
//		for (int j = i + 1; j < len; j++) {
//			if (nums[j] < nums[minindex]) {
//				minindex = j;
//			}
//		}
//		swap(nums[i], nums[minindex]);
//	}
//}
//
//int main() {
//	vector<int> v= { 6,4,8,7,3,5,2,1 };
//	selectionSort(v);
//	for (auto e : v) cout << e << " ";
//	return 0;
//}