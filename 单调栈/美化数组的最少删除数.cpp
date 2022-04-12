#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<int> st;// 直接使用stack来模拟栈
	int minDeletion(vector<int>& nums) {
		int len = nums.size();
		int cnt = 0;
		for (auto& e : nums) {
			if (st.size() % 2 == 0) {
				st.push_back(e);
			}
			else if (e == st.back()) {
				cnt++;
			}
			else if (e != st.back()) {
				st.push_back(e);
			}
		}
		if (st.size() % 2 != 0) cnt++;
		return cnt;
	}
};