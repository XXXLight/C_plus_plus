#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		string res = "";
		int len1 = num1.size();
		int len2 = num2.size();
		int i = len1 - 1, j = len2 - 1;
		int carry = 0;
		// 两个指针放在字符串的末尾，加完往前移动
		// 先算sum，由sum产生cur（当前位）和carry（进位）
		while (i >= 0 || j >= 0 || carry) {
			int n1 = i >= 0 ? (num1[i] - '0') : 0;
			int n2 = j >= 0 ? (num2[j] - '0') : 0;
			int sum = n1 + n2 + carry;
			int cur = sum % 10;
			res += cur + '0';
			carry = sum / 10;//注意carry放的位置
			i--; j--;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};


class Solution {
public:
	string addStrings(string num1, string num2) {
		int len1 = num1.size();
		int len2 = num2.size();
		int carry = 0;
		int p1 = len1 - 1, p2 = len2 - 1;
		string res;
		while (p1 >= 0 || p2 >= 0 || carry) {
			int a = p1 >= 0 ? num1[p1] - '0' : 0;
			int b = p2 >= 0 ? num2[p2] - '0' : 0;
			cout << a << " " << b << " " << carry << endl;
			int sum = a + b + carry;
			int cur = sum % 10;
			int carry = sum / 10;	// 多了个int，调试时carry是1，cout<<出来居然是0
			res += to_string(cur);
			p1--; p2--;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};