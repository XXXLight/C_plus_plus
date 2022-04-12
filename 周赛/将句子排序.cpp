#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	// 字符串切割
	vector<string> getStr(string s) {
		vector<string> res;
		istringstream str(s);
		string out;
		while (str.good()) {
			getline(str, out, ' ');		//从str读取字符串到out中，遇到空格便停止
			if (!out.empty()) 			//如果原字符串中有连续的空格out会为空
				res.push_back(out);
		}
		return res;
	}
	string sortSentence(string s) {
		string ret = "";
		vector<string> res = getStr(s);
		vector<string> r(res.size());
		for (int i = 0; i < res.size(); i++) {
			string tmp = res[i];
			int index = (tmp[tmp.size() - 1]) - '0' - 1;
			r[index] = tmp.substr(0, tmp.size() - 1);
		}
		for (int i = 0; i < r.size(); i++) {
			if (i != r.size() - 1) {
				ret += r[i];
				ret += " ";
			}
			else {
				ret += r[i];
			}
		}
		return ret;
	}
};