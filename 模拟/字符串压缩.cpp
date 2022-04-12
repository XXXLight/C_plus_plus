#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string compressString(string S) {
		string res;
		// 指针 i-1 i判断前后关系
		for (int i = 1; i < S.size(); i++) {
			// 初始化计数器和当前字母
			int cnt = 1;
			char tmp = S[i - 1]; // string的单个是char
			while (S[i] == S[i - 1]) {
				cnt++;
				i++;
			}
			// S[i-1]!=S[i]需要更新计数器和字母，练成循环了，所以不用重复做
			res += tmp;  // char可以直接与string相加
			res += to_string(cnt);
			if (i == S.size() - 1) { res += S[i]; res += "1"; }
		}
		if (res.size() >= S.size() || S.size() == 1) return S;
		return res;
	}
};