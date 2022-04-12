#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> canSeePersonsCount(vector<int>& heights) {
		int n = heights.size();
		vector<int> ans(n);
		stack<int> s;
		for (int i = n - 1; i >= 0; --i) {
			while (!s.empty()) {
				++ans[i];
				if (heights[i] > heights[s.top()]) {
					s.pop();
				}
				else {
					break;
				}
			}
			s.push(i);
		}
		return ans;
	}
};


// 第一种情况：8 1 2 3 4 9	（8能看到4个，其中1 2 3 4是弹出的，9因为比8大导致栈不空，所以还要加一）
// 第二种情况：8 1 2 3 4	（8能看到4个，其中1 2 3 4是弹出的）
class Solution {
public:
	vector<int> canSeePersonsCount(vector<int>& heights) {
		int len = heights.size();
		vector<int> res(len);//预先申明好空间
		stack<int> st;//用于存放每个人的身高
		for (int i = len - 1; i >= 0; i--) {//从后往前遍历
			while (!st.empty() && st.top() < heights[i]) {//如果没有遇到比他高的人
				st.pop(); //删掉这些比他低的人（在后续的遍历里，这些人会被这个人遮住）
				res[i]++;//比这他低的他都能看到
			}
			if (!st.empty()) res[i]++;//如果非空，他还能看见一个人（即最后一个把别人遮住的人）
			st.push(heights[i]);//把这个人给存到栈里
		}
		return res;
	}
};