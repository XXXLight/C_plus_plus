#include<bits/stdc++.h>
using namespace std;

// continue是后面的语句不执行继续循环
// break是跳出循环
class Solution {
public:
	int numDifferentIntegers(string word) {
		int len = word.size();
		set<string> v;
		// 线性扫描
		for (int i = 0; i < len; i++) {
			if (isalpha(word[i])) continue; // 字母跳过
			// 满足条件就一直处理并移动指针
			string s = "";
			while (isdigit(word[i]) && i < len) { // i<len不能少
				s += word[i];
				i++;
			}
			// 去除前导零
			while (s.size() > 0 && s[0] == '0') { // 不能是“0”
				s.erase(s.begin());
			}
			v.insert(s);
		}
		return v.size();
	}
};



class Solution {
public:
	int numDifferentIntegers(string word) {
		int len = word.size();
		set<string> v;
		int i = 0;
		while (i < len) {
			if (isalpha(word[i])) { i++; continue; }
			string s = "";
			while (isdigit(word[i]) && i < len) {
				s += word[i];
				i++;
			}

			while (s.size() > 0 && s[0] == '0') {
				s.erase(s.begin());
			}
			v.insert(s);
		}
		return v.size();
	}
};