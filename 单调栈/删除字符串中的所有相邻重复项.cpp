#include<bits/stdc++.h>
using namespace std;

// 使用string就可以模拟栈
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

