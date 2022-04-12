#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		int i = 0, j = 0;
		while (i < version1.size() || j < version2.size())
		{
			int a = 0, b = 0;
			while (i < version1.size() && version1[i] != '.') a = a * 10 + version1[i++] - '0';
			while (j < version2.size() && version2[j] != '.') b = b * 10 + version2[j++] - '0';
			if (a > b) return 1;
			else if (a < b) return -1;
			i++;
			j++;
		}
		return 0;
	}
};


class Solution {
public:
	int compareVersion(string version1, string version2) {
		char c;         //提取'.'
		int num1, num2;  //提取数字
		istringstream ist1(version1);
		istringstream ist2(version2);
		while (bool(ist1 >> num1) + bool(ist2 >> num2))
		{
			if (num1 > num2)   return 1;
			if (num1 < num2)   return -1;
			num1 = 0;
			num2 = 0;
			ist1 >> c;
			ist2 >> c;
		}
		return 0;
	}
};