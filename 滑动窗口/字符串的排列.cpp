#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//在 最小覆盖子串 的基础上稍微改动即可
class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int lenS1 = s1.size(), lenS2 = s2.size(); //字符串的长度
		int p1 = 0, p2 = 0; //双指针形成滑动窗口[p1,p2)
		int match = 0; //当前匹配字母数量
		int start = 0, minLen = INT_MAX; //为了记录结果
		unordered_map<char, int> window, needs; //window记录窗口中的次数
		for (auto e : s1) needs[e]++; //需要的次数
		while (p2 < lenS2) { //直到字符串的右边界，结束条件p2==lenS2，证明p2是右边界
			//将右边的加入窗口，同时右移指针
			char c1 = s2[p2];
			window[c1]++;
			p2++;
			//将右边的加入窗口，同时右移指针
			if (needs.count(c1) && window[c1] == needs[c1]) {//窗口中的字母出现次数达到要求
				match++;
			}
			while (match == needs.size()) {//匹配则缩小左边的窗口
				//长度相同说明有解
				if (p2 - p1 == lenS1) {
					return true;
				}
				//长度相同说明有解
				//缩小窗口，指针右移
				char c2 = s2[p1];
				window[c2]--;
				p1++;
				//缩小窗口，指针右移
				if (needs.count(c2) && window[c2] < needs[c2]) match--;
			}
		}
		return false;
	}
};