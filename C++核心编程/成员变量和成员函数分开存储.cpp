//#include<bits/stdc++.h>
//using namespace std;
//
//// 非静态&&变量才占有空间
//class Person {
//public:
//	Person() {
//		mA = 0;
//	}
//	//非静态成员变量占对象空间
//	int mA;
//	//静态成员变量不占对象空间
//	static int mB;
//
//	// 可以看看sizeof,是4字节4字节分配
//	char c;
//	//函数也不占对象空间，所有函数共享一个函数实例
//	void func() {
//		cout << "mA:" << this->mA << endl;
//	}
//	//静态成员函数也不占对象空间
//	static void sfunc() {
//	}
//};
//
//int main() {
//
//	cout << sizeof(Person) << endl;
//
//	system("pause");
//
//	return 0;
//}