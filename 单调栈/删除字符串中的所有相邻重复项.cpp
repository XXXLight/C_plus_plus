#include<bits/stdc++.h>
using namespace std;

// ʹ��string�Ϳ���ģ��ջ
class Solution {
public:
	string removeDuplicates(string s) {
		string stk;
		for (char ch : s) {
			if (!stk.empty() && stk.back() == ch) {
				stk.pop_back();
			}
			else {
				stk.push_back(ch);
			}
		}
		return stk;
	}
};

