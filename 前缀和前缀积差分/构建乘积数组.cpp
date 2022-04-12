#include<bits/stdc++.h>
using namespace std;

// 理解为什么要用前缀积

class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		if (a.size() == 0) return {};
		vector<int> left(a.size()); //前缀积
		vector<int> right(a.size()); //逆向前缀积
		vector<int> res(a.size());
		left[0] = 1;
		right[a.size() - 1] = 1;
		for (int i = 1; i < a.size(); i++) {
			left[i] = left[i - 1] * a[i - 1];//注意索引： i i-1 i-1 ，递推模式
		}
		for (int i = a.size() - 1; i > 0; i--) {
			right[i - 1] = right[i] * a[i]; //注意索引： i-1 i i ，递推模式
		}
		for (int i = 0; i < a.size(); i++) {
			res[i] = left[i] * right[i];
		}
		return res;
	}
};


class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		int n = a.size();
		vector<int> res(n, 1);
		int l = 1, r = 1;
		for (int i = 0, j = n - 1; i < a.size() && j >= 0; i++, j--) {
			res[i] *= l; l *= a[i];
			res[j] *= r; r *= a[j];
		}
		return res;
	}
};