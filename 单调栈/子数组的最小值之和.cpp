#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
	const int BASE = 1e9 + 7;
public:
	int sumSubarrayMins(vector<int>& arr) {
		stack<int> stk;
		arr.push_back(0);               // 保证栈中所有元素都会被弹出计算
		int len = arr.size();
		long res = 0;
		for (int i = 0; i < len; ++i) {
			while (!stk.empty() && arr[i] <= arr[stk.top()]) {
				int index = stk.top(); stk.pop();
				int prev_index = -1;
				if (!stk.empty()) prev_index = stk.top();
				int prev_count = index - prev_index - 1; // 数量m
				int next_count = i - index - 1;          // 数量n
				res += long(arr[index]) * (prev_count + 1) * (next_count + 1) % BASE;
				res %= BASE;
			}
			stk.push(i);
		}
		return res;
	}
};

