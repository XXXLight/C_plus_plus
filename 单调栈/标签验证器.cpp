#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<string>stack;
	bool contains_tag = false;

	//�ж��ǲ���һ����Ч��TAG_NAME;
	bool isValidTagName(string s, bool ending) {
		if (s.length() < 1 || s.length() > 9)return false;

		for (int i = 0; i < s.length(); ++i) {
			if (s[i] > 'Z' || s[i] < 'A')return false;
		}

		if (ending) {
			//��������TAG_NAME���ж��ǲ�����ջ����TAG_NAME��ȣ���ջ
			if (!stack.empty() && stack.back() == s)stack.pop_back();
			else return false;
		}
		else {
			//��ʼ��TAG_NAME,��ջ
			contains_tag = true;
			stack.push_back(s);
		}

		return true;
	}

	//�ж��ǲ�����Ч��Cdata
	bool isValidCdata(string s) {
		return s.find("[CDATA[", 0) == 0;
	}

	bool isValid(string code) {
		if (code[0] != '<' || code[code.size() - 1] != '>')return false;

		for (int i = 0; i < code.length(); ++i) {
			bool ending = false;
			int closeindex;
			//Ӧ��ֻ���ڱ���������ʱ��ջΪ��
			if (stack.empty() && contains_tag)return false;
			if (code[i] == '<') {
				//��һ���ǣ�,�ж��ǲ���һ��cdata
				if (!stack.empty() && i < code.size() - 1 && code[i + 1] == '!') {
					closeindex = code.find("]]>", i + 1);
					if (closeindex == string::npos || !isValidCdata(code.substr(i + 2, closeindex - i))) {
						return false;
					}
				}
				//������һ��TAG_NAME;
				else {
					//��������ʶ
					if (i < code.length() - 1 && code[i + 1] == '/') {
						i++;
						ending = true;
					}
					closeindex = code.find('>', i + 1);
					if (closeindex == string::npos || !isValidTagName(code.substr(i + 1, closeindex - i - 1), ending))            return false;

				}
				i = closeindex;
			}

		}
		return stack.empty() && contains_tag;

	}
};