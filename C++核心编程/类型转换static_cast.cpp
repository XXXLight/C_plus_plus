//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	operator int() { return 1; }
//	operator char*() { return NULL; }
//};
//
//// 类型转换中  <转换后target>(转换前src)
//
//// static_cast 低风险的转换，如整型和浮点型、字符型之间的互相转换。
//
//// static_cast 不能用于在不同类型的指针之间互相转换，也不能用于整型和指针之间的互相转换，
//// 当然也不能用于不同类型的引用之间的转换。因为风险高。
//int main()
//{
//	A a;
//	int n;
//	const char* p="Hello World!";
//	n = static_cast <int> (3.14);  // n 的值变为 3
//	n = static_cast <int> (a);  //调用 a.operator int，n 的值变为 1
//	p = static_cast <char*> (a);  //调用 a.operator char*，p 的值变为 NULL
//	//n = static_cast <int> (p);  //编译错误，static_cast不能将指针转换成整型
//	//p = static_cast <char*> (n);  //编译错误，static_cast 不能将整型转换成指针
//	return 0;
//}