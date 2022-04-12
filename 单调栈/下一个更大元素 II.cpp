#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int> res(nums.size());
		int len = nums.size();
		stack<int> st;
		// 长度扩展两倍，索引%len
		for (int i = 2 * len - 1; i >= 0; i--) {
			// 注意此处的while中两个条件不能交换，必须先检查是否空，是否有等于号
			while (!st.empty() && st.top() <= nums[i%len]) {
				st.pop();
			}
			res[i%len] = st.empty() ? -1 : st.top();
			st.push(nums[i%len]);
		}
		return res;
	}
};
