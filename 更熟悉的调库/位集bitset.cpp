#include<bits/stdc++.h>
using namespace std;

int main() {
	bitset<8> n;
	bitset<9> b(10);
	bitset<10> c("00001001001010");
	string s("00001001001010");
	bitset<10> d(s, 3, 5);
	cout << n << endl;  // 00000000 ���ͣ���ʼ��Ϊ8λ0
	cout << b << endl;  // 000001010 ���ͣ�ʮ���Ƶ�10���Ƕ����Ƶ�1010��д��9λ����000001010
	cout << c << endl; // 0000100100 ���ͣ�ȡ��ǰ10λ
	cout << d << endl;// 0000001001 ���ͣ�s�ӵ�3λ��ʼ��ȡ����λ5���Ӵ�����10λ�������
	cout << bitset<7>(40) << endl;// 0101000 ���ͣ�32 16 8 4 2 1��40��7λ���������
	return 0;
}