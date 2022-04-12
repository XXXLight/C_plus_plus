#include<bits/stdc++.h>
using namespace std;

int main() {
	bitset<8> n;
	bitset<9> b(10);
	bitset<10> c("00001001001010");
	string s("00001001001010");
	bitset<10> d(s, 3, 5);
	cout << n << endl;  // 00000000 解释：初始化为8位0
	cout << b << endl;  // 000001010 解释：十进制的10，是二进制的1010，写成9位就是000001010
	cout << c << endl; // 0000100100 解释：取了前10位
	cout << d << endl;// 0000001001 解释：s从第3位开始提取长度位5的子串，以10位进行输出
	cout << bitset<7>(40) << endl;// 0101000 解释：32 16 8 4 2 1，40以7位二进制输出
	return 0;
}