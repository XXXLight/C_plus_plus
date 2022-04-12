#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int> res(nums.size());
		int len = nums.size();
		stack<int> st;
		// ������չ����������%len
		for (int i = 2 * len - 1; i >= 0; i--) {
			// ע��˴���while�������������ܽ����������ȼ���Ƿ�գ��Ƿ��е��ں�
			while (!st.empty() && st.top() <= nums[i%len]) {
				st.pop();
			}
			res[i%len] = st.empty() ? -1 : st.top();
			st.push(nums[i%len]);
		}
		return res;
	}
};
