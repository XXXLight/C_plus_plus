#include<bits/stdc++.h>
using namespace std;

// 与计算器一样
class Solution {
public:
	int calculate(string s) {
		// vector就可以模拟栈
		vector<int> stk;
		char preSign = '+';
		int num = 0;
		int n = s.length();
		for (int i = 0; i < n; ++i) {
			if (isdigit(s[i])) {
				num = num * 10 + int(s[i] - '0');
			}
			if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
				switch (preSign) {
				case '+':
					stk.push_back(num);
					break;
				case '-':
					stk.push_back(-num);
					break;
				case '*':
					stk.back() *= num;
					break;
				default:
					stk.back() /= num;
				}
				preSign = s[i];
				num = 0;
			}
		}
		return accumulate(stk.begin(), stk.end(), 0);
	}
};


// Q1:用的什么数据结构？（栈，可以用vector模拟）
// 1.时间复杂度和空间复杂度都是o(n)
class Solution {
public:
	int calculate(string s) {
		int res = 0;// 计算结果
		int len = s.size();
		char presign = '+';  // 数字前面的运算符
		long long tmp = 0;	// 临时存放数据
		vector<int> v;	// 模拟栈
		for (int i = 0; i < len; i++) {
			// 碰到数字，不停累加
			if (isdigit(s[i])) tmp = tmp * 10 + s[i] - '0';
			// 不是数字且不是空格代表就是运算符
			if (!isdigit(s[i]) && s[i] != ' ' || i == len - 1) {
				// 运算符分为四类，加减直接放，乘除对栈顶进行运算即可
				if (presign == '+') {
					v.push_back(tmp);
				}
				else if (presign == '-') {
					v.push_back((-1)*tmp);
				}
				else if (presign == '*') {
					v.back() *= tmp;
				}
				else {
					v.back() /= tmp;
				}
				//下一轮的运算符是这一轮的，下一轮tmp=0
				presign = s[i];// 放在结尾的是下一轮的东西
				tmp = 0;
			}
		}
		return accumulate(v.begin(), v.end(), 0);
	}
};