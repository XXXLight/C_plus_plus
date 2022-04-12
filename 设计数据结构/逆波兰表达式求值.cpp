#include<bits/stdc++.h>
using namespace std;

// stack ��ȫ������vectorģ��
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> stk;

		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				int a = stk.top();                      //ȡ��ջ����������
				stk.pop();
				int b = stk.top();
				stk.pop();

				if (tokens[i] == "+") stk.push(b + a);  //��������������ջ
				if (tokens[i] == "-") stk.push(b - a);
				if (tokens[i] == "*") stk.push(b * a);
				if (tokens[i] == "/") stk.push(b / a);
			}                                           //��ǰΪ���־�ֱ����ջ��Ϊ������ͳ�ջ������������
			else stk.push(stoi(tokens[i]));             //stoi��ʾstring to int���ַ���ת����
		}

		int res = stk.top();                            //���ʣ�µ�ջ��Ԫ�ؼ����沨�����ʽ�ļ�����

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

				if (tokens[i] == "+") stk.push_back(b + a);  //��������������ջ
				if (tokens[i] == "-") stk.push_back(b - a);
				if (tokens[i] == "*") stk.push_back(b * a);
				if (tokens[i] == "/") stk.push_back(b / a);
			}                                           //��ǰΪ���־�ֱ����ջ��Ϊ������ͳ�ջ������������
			else stk.push_back(stoi(tokens[i]));             //stoi��ʾstring to int���ַ���ת����
		}
		int res = stk.back();                            //���ʣ�µ�ջ��Ԫ�ؼ����沨�����ʽ�ļ�����
		return res;
	}
};