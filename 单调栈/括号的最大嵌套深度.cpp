#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxDepth(string s) {
		stack<int> st;
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				st.push(s[i]);
				res = max(res, (int)st.size());
			}
			else if (!st.empty() && s[i] == ')') {
				st.pop();
			}
			else continue;
		}
		return res;
	}
};

// 这种方法比较简单
// 思路：一个变量，碰到左括号++，碰到右括号--，返回该变量的最大值
class Solution {
public:
	int maxDepth(string s) {
		int res = 0, n = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') n++;
			if (s[i] == ')') n--;
			if (res < n) res = n;
		}
		return res;
	}
};
