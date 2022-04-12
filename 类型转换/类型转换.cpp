#include<bits/stdc++.h>
using namespace std;

int main() {
	// int转string   string s=to_string(num);  num属于int
	// long long转string    string s=to_string(num); num属于long long
	// 单个的char转int  int s0=s[0]-'0'  s[0]='6'等
	// string转long long     long long res=atoll(t.c_str());   t是string

	// string 转 float
	string s = "3425345.1313";
	float res_s = atof(s.c_str());
	cout << res_s << endl;
	// char 和 string 是直接可以相加的
	char a = '1';
	string res_a = s + a;
	cout << res_a << endl;
	int inta = 999999999;
	int res = inta * inta;
	cout << res << endl;
	return 0;
}