#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	char anotherPair(char c) {
		if (c == '(') return ')';
		else if (c == '[') return ']';
		else if (c == '{') return '}';
		// 这个分支必须有，否则会报错(error: non-void function does not return a value in all control paths)
		return '=';
	}
	bool isValid(string s) {
		stack<char> st;
		for (int i = 0; i < s.size(); i++) {
			// 左括号入栈
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				st.push(s[i]);
			}
			// 右括号检查是否匹配
			else {
				char front = st.top();
				// 匹配则出栈
				if (!st.empty() && anotherPair(front) == s[i]) {
					st.pop();
				}
				// 不匹配返回false
				else return false;
			}
		}
		// 栈不空也返回false
		if (!st.empty()) return false;
		return true;
	}
};