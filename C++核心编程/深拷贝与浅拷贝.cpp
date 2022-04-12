//#include<bits/stdc++.h>
//using namespace std;
//
//class Person {
//public:
//	// 深拷贝与浅拷贝涉及到的是指针问题,在堆上开辟的内存
//	int* height;
//	// 有参构造
//	Person(int h) {
//		height = new int(h);
//	}
//	// 没有自己的拷贝构造调用的是默认的浅拷贝操作
//
//	//自己写的拷贝构造，控制的是这个变量
//	Person(const Person& p) {
//		height = new int(*p.height);
//	}
//
//	// 析构
//	~Person() {
//		if (height != nullptr) {
//			delete height;
//		}
//		// 析构函数放在这里，浅拷贝只能析构一次，深拷贝能析构两次
//		cout << "析构函数" << endl;
//	}
//};
//
//int main() {
//	Person P1(180);
//	Person P2(P1);
//	cout << *P1.height << " " << *P2.height << endl;
//	return 0;
//}