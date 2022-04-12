//#include<bits/stdc++.h>
//using namespace std;
//
//// ​ 栈区：
////由编译器自动分配释放, 存放函数的参数值, 局部变量等
////注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
//
////堆区：
////由程序员分配释放, 若程序员不释放, 程序结束时由操作系统回收
////在C++中主要利用new在堆区开辟内存
//
//// 返回的是变量的地址
//int* func1() {
//	int a = 10;
//	return &a;
//}
//
//void test01() {
//	int* p = func1();
//	cout << *p << endl;
//	cout << *p << endl;
//}
//
//// 返回的是地址，在堆上开辟的地址是不会变的
//int* func2() {
//	int* a = new int(10);
//	return a;
//}
//
//void test02() {
//	int *p = func2();
//	cout << *p << endl;
//	cout << *p << endl;
//}
//
//void test03() {
//	int* p = func2();
//	cout << *p << endl;
//	cout << *p << endl;
//	//利用delete释放堆区数据
//	delete p;
//	cout << *p << endl; //报错，释放的空间不可访问
//}
//
//int main() {
//	test01();
//	cout << endl;
//	test02();
//	//test03();
//	return 0;
//}