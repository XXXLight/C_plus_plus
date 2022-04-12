#include<bits/stdc++.h>
using namespace std;

//����2 - 36������ת��Ϊ10��������
int Atoi(string s, int radix)    //s�Ǹ�����radix�����ַ���
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

//��10������ת��Ϊ�����n������
string intToA(int n, int radix)    //n�Ǵ�ת���֣�radix��ָ���Ľ���
{
	string ans = "";
	do {
		int t = n % radix;
		if (t >= 0 && t <= 9)	ans += t + '0';
		else ans += t - 10 + 'a';
		n /= radix;
	} while (n != 0);	//ʹ��do{}while�����Է�ֹ����Ϊ0�����
	reverse(ans.begin(), ans.end());
	return ans;
}
// ����ת��������ǰ��0����0ת����3λ2������000
string intToA(int n, int radix, int length)    //n�Ǵ�ת���֣�radix��ָ���Ľ���
{
	string ans = "";
	do {
		int t = n % radix;
		if (t >= 0 && t <= 9)	ans += t + '0';
		else ans += t - 10 + 'a';
		n /= radix;
	} while (n != 0);	//ʹ��do{}while�����Է�ֹ����Ϊ0�����
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