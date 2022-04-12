#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;



// string,vector就可以模拟栈
class Solution {
public:
	string smallestSubsequence(string s) {
		vector<bool> visited(26);       // 判断字母是否已经在栈中
		unordered_map<char, int> num;   // 记录字母出现的次数
		for (char ch : s) {
			num[ch]++;
		}

		string stk;                     // string就可以模拟栈了
		for (char ch : s) {
			if (!visited[ch - 'a']) {   // 若字母没有出现在栈中

				// 当 栈顶元素 > 当前字母的值，且栈顶字母次数不为0，进行出栈操作
				while (!stk.empty() && stk.back() > ch && num[stk.back()] > 0) {
					visited[stk.back() - 'a'] = false;      // 出栈后，字母不在栈中了
					stk.pop_back();                         // 出栈
				}
				visited[ch - 'a'] = true;                   // 入栈，字母在栈中
				stk.push_back(ch);
			}
			num[ch]--;                                      // 每次访问后， 字母次数 - 1
		}
		return stk;
	}
};