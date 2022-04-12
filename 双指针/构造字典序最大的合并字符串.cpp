#include<bits/stdc++.h>
using namespace std;

//Follow your code

class Solution {
public:
	string largestMerge(string word1, string word2) {
		int len1 = word1.size();
		int len2 = word2.size();
		int i = 0, j = 0;
		string res = "";
		while (i < len1 || j < len2) { //退出循环的条件是i==len1&&j==len2,即两个都到了尾部
			string sub1 = word1.substr(i, len1 - i);//直接写成string sub1 = word1.substr(i);和python中切片一样
			string sub2 = word2.substr(j, len2 - j);//直接写成string sub2 = word2.substr(j);和python中切片一样
			if (sub1 <= sub2) {
				res += sub2[0];
				j++;
			}
			else if (sub2 < sub1) {
				res += sub1[0];
				i++;
			}
		}
		return res;
	}
};