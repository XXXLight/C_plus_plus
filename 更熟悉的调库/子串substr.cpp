#include<bits/stdc++.h>
using namespace std;

int main() {
	string s = "hvchsdfvdf";
	cout << s.substr(1) << endl;// vchsdfvdf  解释：从第1位开始到字符串末尾
	cout << s.substr(2, 3) << endl;// chs  解释：从第2位开始长度位3的子串
	return 0;
}