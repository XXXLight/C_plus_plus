#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") {
			return "0";
		}
		string ans = "0";
		int m = num1.size(), n = num2.size();
		for (int i = n - 1; i >= 0; i--) {
			string curr;
			int add = 0;
			for (int j = n - 1; j > i; j--) {
				curr.push_back(0);
			}
			int y = num2[i] - '0';
			for (int j = m - 1; j >= 0; j--) {
				int x = num1[j] - '0';
				int product = x * y + add;
				curr.push_back(product % 10);
				add = product / 10;
			}
			while (add != 0) {
				curr.push_back(add % 10);
				add /= 10;
			}
			reverse(curr.begin(), curr.end());
			for (auto &c : curr) {
				c += '0';
			}
			ans = addStrings(ans, curr);
		}
		return ans;
	}

	string addStrings(string &num1, string &num2) {
		int i = num1.size() - 1, j = num2.size() - 1, add = 0;
		string ans;
		while (i >= 0 || j >= 0 || add != 0) {
			int x = i >= 0 ? num1[i] - '0' : 0;
			int y = j >= 0 ? num2[j] - '0' : 0;
			int result = x + y + add;
			ans.push_back(result % 10);
			add = result / 10;
			i--;
			j--;
		}
		reverse(ans.begin(), ans.end());
		for (auto &c : ans) {
			c += '0';
		}
		return ans;
	}
};



class Solution {
public:
	string multiply(string num1, string num2) {
		int m = num1.size(), n = num2.size();
		// 结果最多为 m + n 位数
		vector<int> res(m + n, 0);
		// 从个位数开始逐位相乘
		for (int i = m - 1; i >= 0; i--)
			for (int j = n - 1; j >= 0; j--) {
				int mul = (num1[i] - '0') * (num2[j] - '0');
				// 乘积在 res 对应的索引位置
				int p1 = i + j, p2 = i + j + 1;
				// 叠加到 res 上
				int sum = mul + res[p2];
				res[p2] = sum % 10;
				res[p1] += sum / 10;
			}
		// 结果前缀可能存的 0（未使用的位）
		int i = 0;
		while (i < res.size() && res[i] == 0)
			i++;
		// 将计算结果转化成字符串
		string str;
		for (; i < res.size(); i++)
			str.push_back('0' + res[i]);

		return str.size() == 0 ? "0" : str;
	}
};