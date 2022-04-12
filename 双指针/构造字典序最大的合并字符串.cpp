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
		while (i < len1 || j < len2) { //�˳�ѭ����������i==len1&&j==len2,������������β��
			string sub1 = word1.substr(i, len1 - i);//ֱ��д��string sub1 = word1.substr(i);��python����Ƭһ��
			string sub2 = word2.substr(j, len2 - j);//ֱ��д��string sub2 = word2.substr(j);��python����Ƭһ��
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