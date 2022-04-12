#include<bits/stdc++.h>
using namespace std;

// 有效括号+最长，直接暴力
class Solution {
public:
	char anotherPair(char c) {
		if (c == '(') return ')';
		// 这个分支必须有，否则会报错(error: non-void function does not return a value in all control paths)
		return '=';
	}
	bool isValid(string s) {
		stack<char> st;
		for (int i = 0; i < s.size(); i++) {
			// 左括号入栈
			if (s[i] == '(') {
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
	int longestValidParentheses(string s) {
		int ans = INT_MIN;
		for (int i = 0; i < s.size(); i++) {
			for (int j = i + 1; j < s.size(); j++) {
				if (isValid(s.substr(i, j - i + 1))) {
					ans = max(ans, j - i + 1);
				}
			}
		}
		return ans == INT_MIN ? 0 : ans;
	}
};


// 正向一次+逆向一次
class Solution {
public:
	int longestValidParentheses(string s) {
		int left = 0, right = 0, maxlength = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				left++;
			}
			else {
				right++;
			}
			if (left == right) {
				maxlength = max(maxlength, 2 * right);
			}
			else if (right > left) {
				left = right = 0;
			}
		}
		left = right = 0;
		for (int i = (int)s.length() - 1; i >= 0; i--) {
			if (s[i] == '(') {
				left++;
			}
			else {
				right++;
			}
			if (left == right) {
				maxlength = max(maxlength, 2 * left);
			}
			else if (left > right) {
				left = right = 0;
			}
		}
		return maxlength;
	}
};

