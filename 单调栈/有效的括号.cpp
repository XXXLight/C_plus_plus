#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	char anotherPair(char c) {
		if (c == '(') return ')';
		else if (c == '[') return ']';
		else if (c == '{') return '}';
		// �����֧�����У�����ᱨ��(error: non-void function does not return a value in all control paths)
		return '=';
	}
	bool isValid(string s) {
		stack<char> st;
		for (int i = 0; i < s.size(); i++) {
			// ��������ջ
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
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
};