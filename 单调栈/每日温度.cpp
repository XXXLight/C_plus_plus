#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> res(T.size());
		stack<int>st;
		int len = T.size();
		for (int i = len - 1; i >= 0; i--) {//�������
			while (!st.empty() && T[st.top()] <= T[i]) {//��
				st.pop();
			}
			res[i] = st.empty() ? 0 : st.top() - i;//��
			// ѹ���������
			st.push(i);
		}
		return res;
	}
};