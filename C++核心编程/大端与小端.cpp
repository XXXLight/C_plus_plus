//#include<bits/stdc++.h>
//#include<typeinfo>
//
//using namespace std;
//
//// 大端小端： 大端低高  小端低低
//// 大端：网络字节序 小端：主机字节序
//// 一个字节是由两位16进制数(0x)组成 
//// short int 4字节
//int main(int argc, char** argv)
//{
//	short int x=0x1122;
//	char x0, x1;
//	// 查看字节数
//	cout << sizeof(short int) << endl;
//	cout << sizeof(int) << endl;
//	cout << sizeof(char) << endl;
//	cout << typeid(&x).name() << endl;
//	cout << typeid((char*)&x).name() << endl;
//	x0 = ((char*)&x)[0];  //类比数组a[0],a是地址部分
//	x1 = ((char*)&x)[1];
//	printf("%x", x0);
//
//	return 1;
//}
