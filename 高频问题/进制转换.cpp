#include<bits/stdc++.h>
using namespace std;

//任意2 - 36进制数转化为10进制数。
int Atoi(string s, int radix)    //s是给定的radix进制字符串
{
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		char t = s[i];
		if (t >= '0'&&t <= '9') ans = ans * radix + t - '0';
		else ans = ans * radix + t - 'a' + 10;
	}
	return ans;
}

//将10进制数转换为任意的n进制数
string intToA(int n, int radix)    //n是待转数字，radix是指定的进制
{
	string ans = "";
	do {
		int t = n % radix;
		if (t >= 0 && t <= 9)	ans += t + '0';
		else ans += t - 10 + 'a';
		n /= radix;
	} while (n != 0);	//使用do{}while（）以防止输入为0的情况
	reverse(ans.begin(), ans.end());
	return ans;
}
// 进制转换，包含前导0，如0转换成3位2进制是000
string intToA(int n, int radix, int length)    //n是待转数字，radix是指定的进制
{
	string ans = "";
	do {
		int t = n % radix;
		if (t >= 0 && t <= 9)	ans += t + '0';
		else ans += t - 10 + 'a';
		n /= radix;
	} while (n != 0);	//使用do{}while（）以防止输入为0的情况
	reverse(ans.begin(), ans.end());
	if (ans.size() < length) {
		reverse(ans.begin(), ans.end());
		int cnt = length - ans.size();
		while (cnt--) ans.push_back('0');
		reverse(ans.begin(), ans.end());
	}
	return ans;
}

int main() {
	string s = "111";
	cout << Atoi(s, 2) << endl;
	cout << Atoi(s, 3) << endl;
	return 0;
}