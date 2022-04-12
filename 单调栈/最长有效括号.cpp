#include<bits/stdc++.h>
using namespace std;

// ��Ч����+���ֱ�ӱ���
class Solution {
public:
	char anotherPair(char c) {
		if (c == '(') return ')';
		// �����֧�����У�����ᱨ��(error: non-void function does not return a value in all control paths)
		return '=';
	}
	bool isValid(string s) {
		stack<char> st;
		for (int i = 0; i < s.size(); i++) {
			// ��������ջ
			if (s[i] == '(') {
				st.push(s[i]);
			}
			// �����ż���Ƿ�ƥ��
			else {
				char front = st.top();
				// ƥ�����ջ
				if (!st.empty() && anotherPair(front) == s[i]) {
					st.pop();
				}
				// ��ƥ�䷵��false
				else return false;
			}
		}
		// ջ����Ҳ����false
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


// ����һ��+����һ��
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

