#include<bits/stdc++.h>
using namespace std;

//s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
class Solution {
public:
	int calculate(string s) {
		stack<int> ops;
		ops.push(1);
		int sign = 1;

		int ret = 0;
		int n = s.length();
		int i = 0;
		while (i < n) {
			if (s[i] == ' ') {	// s[i]==" "不行
				i++;
			}
			else if (s[i] == '+') {
				sign = ops.top();
				i++;
			}
			else if (s[i] == '-') {
				sign = -ops.top();
				i++;
			}
			else if (s[i] == '(') {
				ops.push(sign);
				i++;
			}
			else if (s[i] == ')') {
				ops.pop();
				i++;
			}
			else {
				long num = 0;
				while (i < n && s[i] >= '0' && s[i] <= '9') {
					num = num * 10 + s[i] - '0';
					i++;
				}
				ret += sign * num;
			}
		}
		return ret;
	}
};


#include<bits/stdc++.h>
using namespace std;

//s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
class Solution {
public:
	int calculate(string s) {
		stack<int> ops;
		ops.push(1);
		int sign = 1;

		int ret = 0;
		int n = s.length();
		int i = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == ' ') {	// s[i]==" "不行
				continue;
			}
			else if (s[i] == '+') {
				sign = ops.top();
			}
			else if (s[i] == '-') {
				sign = -ops.top();
			}
			else if (s[i] == '(') {
				ops.push(sign);
			}
			else if (s[i] == ')') {
				ops.pop();
			}
			else {
				long num = 0;
				while (i < n && s[i] >= '0' && s[i] <= '9') {
					num = num * 10 + s[i] - '0';
					i++;
				}
				ret += sign * num;
				i--; //要不然会多加一次
			}
		}
		return ret;
	}
};