#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<string>stack;
	bool contains_tag = false;

	//判断是不是一个有效的TAG_NAME;
	bool isValidTagName(string s, bool ending) {
		if (s.length() < 1 || s.length() > 9)return false;

		for (int i = 0; i < s.length(); ++i) {
			if (s[i] > 'Z' || s[i] < 'A')return false;
		}

		if (ending) {
			//结束符的TAG_NAME，判断是不是与栈顶的TAG_NAME相等，出栈
			if (!stack.empty() && stack.back() == s)stack.pop_back();
			else return false;
		}
		else {
			//开始的TAG_NAME,入栈
			contains_tag = true;
			stack.push_back(s);
		}

		return true;
	}

	//判断是不是有效的Cdata
	bool isValidCdata(string s) {
		return s.find("[CDATA[", 0) == 0;
	}

	bool isValid(string code) {
		if (code[0] != '<' || code[code.size() - 1] != '>')return false;

		for (int i = 0; i < code.length(); ++i) {
			bool ending = false;
			int closeindex;
			//应当只有在遍历结束的时候栈为空
			if (stack.empty() && contains_tag)return false;
			if (code[i] == '<') {
				//下一个是！,判断是不是一个cdata
				if (!stack.empty() && i < code.size() - 1 && code[i + 1] == '!') {
					closeindex = code.find("]]>", i + 1);
					if (closeindex == string::npos || !isValidCdata(code.substr(i + 2, closeindex - i))) {
						return false;
					}
				}
				//否则是一个TAG_NAME;
				else {
					//结束符标识
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