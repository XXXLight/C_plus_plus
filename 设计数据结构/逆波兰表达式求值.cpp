#include<bits/stdc++.h>
using namespace std;

// stack 完全可以用vector模拟
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> stk;

		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				int a = stk.top();                      //取得栈顶的两个数
				stk.pop();
				int b = stk.top();
				stk.pop();

				if (tokens[i] == "+") stk.push(b + a);  //计算结果，再推入栈
				if (tokens[i] == "-") stk.push(b - a);
				if (tokens[i] == "*") stk.push(b * a);
				if (tokens[i] == "/") stk.push(b / a);
			}                                           //当前为数字就直接入栈，为运算符就出栈两个数来计算
			else stk.push(stoi(tokens[i]));             //stoi表示string to int，字符串转整数
		}

		int res = stk.top();                            //最后剩下的栈顶元素即是逆波兰表达式的计算结果

		return res;
	}
};



class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		vector<int> stk;
		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				int a = stk.back();
				stk.pop_back();
				int b = stk.back();
				stk.pop_back();

				if (tokens[i] == "+") stk.push_back(b + a);  //计算结果，再推入栈
				if (tokens[i] == "-") stk.push_back(b - a);
				if (tokens[i] == "*") stk.push_back(b * a);
				if (tokens[i] == "/") stk.push_back(b / a);
			}                                           //当前为数字就直接入栈，为运算符就出栈两个数来计算
			else stk.push_back(stoi(tokens[i]));             //stoi表示string to int，字符串转整数
		}
		int res = stk.back();                            //最后剩下的栈顶元素即是逆波兰表达式的计算结果
		return res;
	}
};