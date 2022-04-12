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
		// ����ָ������ַ�����ĩβ��������ǰ�ƶ�
		// ����sum����sum����cur����ǰλ����carry����λ��
		while (i >= 0 || j >= 0 || carry) {
			int n1 = i >= 0 ? (num1[i] - '0') : 0;
			int n2 = j >= 0 ? (num2[j] - '0') : 0;
			int sum = n1 + n2 + carry;
			int cur = sum % 10;
			res += cur + '0';
			carry = sum / 10;//ע��carry�ŵ�λ��
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
			int carry = sum / 10;	// ���˸�int������ʱcarry��1��cout<<������Ȼ��0
			res += to_string(cur);
			p1--; p2--;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};