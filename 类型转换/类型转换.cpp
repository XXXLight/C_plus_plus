#include<bits/stdc++.h>
using namespace std;

int main() {
	// intתstring   string s=to_string(num);  num����int
	// long longתstring    string s=to_string(num); num����long long
	// ������charתint  int s0=s[0]-'0'  s[0]='6'��
	// stringתlong long     long long res=atoll(t.c_str());   t��string

	// string ת float
	string s = "3425345.1313";
	float res_s = atof(s.c_str());
	cout << res_s << endl;
	// char �� string ��ֱ�ӿ�����ӵ�
	char a = '1';
	string res_a = s + a;
	cout << res_a << endl;
	int inta = 999999999;
	int res = inta * inta;
	cout << res << endl;
	return 0;
}