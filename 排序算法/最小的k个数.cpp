#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		quickSort(arr, 0, arr.size() - 1);
		vector<int> res;
		res.assign(arr.begin(), arr.begin() + k);
		return res;
	}
private:
	void quickSort(vector<int>& arr, int l, int r) {
		// 子数组长度为 1 时终止递归
		if (l >= r) return;
		// 哨兵划分操作（以 arr[l] 作为基准数）
		int i = l, j = r;
		while (i < j) {
			while (i < j && arr[j] >= arr[l]) j--;
			while (i < j && arr[i] <= arr[l]) i++;
			swap(arr[i], arr[j]);
		}
		swap(arr[i], arr[l]);
		// 递归左（右）子数组执行哨兵划分
		quickSort(arr, l, i - 1);
		quickSort(arr, i + 1, r);
	}
};


class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (k >= arr.size()) return arr;
		return quickSort(arr, k, 0, arr.size() - 1);
	}
private:
	vector<int> quickSort(vector<int>& arr, int k, int l, int r) {
		int i = l, j = r;
		while (i < j) {
			while (i < j && arr[j] >= arr[l]) j--;
			while (i < j && arr[i] <= arr[l]) i++;
			swap(arr[i], arr[j]);
		}
		swap(arr[i], arr[l]);
		if (i > k) return quickSort(arr, k, l, i - 1);
		if (i < k) return quickSort(arr, k, i + 1, r);
		vector<int> res;
		res.assign(arr.begin(), arr.begin() + k);
		return res;
	}
};

// 先写快排，再改进
// 时间复杂度：o(n)
// 空间复杂度：o(log(n))
class Solution {
public:
	vector<int> quickSort(vector<int>&v, int l, int r, int k) {
		vector<int> res(k);
		//if (l >= r) return ;
		int i = l, j = r;
		while (i < j) {
			while (i < j&&v[j] >= v[l]) j--;
			while (i < j&&v[i] <= v[l]) i++;
			if (i < j) swap(v[i], v[j]);
		}
		swap(v[i], v[l]);
		if (k < i) return quickSort(v, l, i - 1, k);
		else if (k > i)  return quickSort(v, i + 1, r, k);
		else {
			copy(v.begin(), v.begin() + k, res.begin());
			return res;
		}
	}
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (k >= arr.size()) return arr;
		vector<int> res = quickSort(arr, 0, arr.size() - 1, k);
		return res;
	}
};

//堆
class Solution {
public:
	vector<int> smallestK(vector<int>& arr, int k) {
		vector<int> vec(k, 0);
		if (k == 0) { // 排除 0 的情况
			return vec;
		}
		priority_queue<int> Q;
		for (int i = 0; i < k; ++i) {
			Q.push(arr[i]);
		}
		for (int i = k; i < (int)arr.size(); ++i) {
			if (Q.top() > arr[i]) {
				Q.pop();
				Q.push(arr[i]);
			}
		}
		for (int i = 0; i < k; ++i) {
			vec[i] = Q.top();
			Q.pop();
		}
		return vec;
	}
};
