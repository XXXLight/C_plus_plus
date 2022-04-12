//#include<bits/stdc++.h>
//using namespace std;
//
//class test
//{
//public:
//	void hello() {
//		cout << "test hello!";
//	};
//	void lambda() {
//		auto fun = [this] { // 捕获了 this 指针
//			this->hello(); // 这里 this 调用的就是 class test 的对象了
//		};
//		fun();
//	}
//};
//
//
//// 创建一个匿名函数并执行
//void fun1() {
//	[]() {
//		cout << "Hello World!" << endl;
//	}();
//}
//
//// 我们也可以方便的将这个创建的匿名函数赋值出来调用：
//void fun2() {
//	int i = 1024;
//	auto func = [](int i) {
//		cout << i << endl;
//	};
//	func(i);
//}
//
//// [] 不捕获任何变量,报错
////void fun3() {
////	int i = 1024;
////	auto func = [] {cout << i; };
////	func();
////}
//
//// [=] 拷贝捕获,两份数据，地址不同
//void fun4() {
//	int i = 1024;
//	cout << &i << endl;
//	auto func = [=] {
//		cout << i << endl;
//		cout << &i << endl;
//	};
//	func();
//}
//
//// [&] 引用捕获，一份数据，地址相同
//void fun5() {
//	int i = 1024;
//	cout << &i << endl;
//	auto fun1 = [&] {
//		cout << &i << endl;
//	};
//	fun1();
//}
//
//// 两者混用
//void fun6() {
//	int i = 1024, j = 2048;
//	cout << "i:" << &i << endl;
//	cout << "j:" << &j << endl;
//	auto fun1 = [=, &i] { // 默认拷贝外部所有变量，但引用变量 i
//		cout << "i:" << &i << endl;
//		cout << "j:" << &j << endl;
//	};
//	fun1();
//}
//
//// [bar] 指定引用或拷贝
//void fun7() {
//	int i = 1024, j = 2048, k;
//
//	cout << "outside i:" << &i << endl;
//	cout << "outside j:" << &j << endl;
//
//	auto fun1 = [i, &j] {
//		cout << "inside  i:" << &i << endl;
//		cout << "inside  j:" << &j << endl;
//		// cout << k; // k 未捕获
//	};
//	fun1();
//}
//int main() {
//	cout << "fun1开始" << endl;
//	fun1();
//	cout << "fun1结束" << endl;
//	cout << endl;
//	cout << "fun2开始" << endl;
//	fun2();
//	cout << "fun2结束" << endl;
//	cout << endl;
//	cout << "fun4开始" << endl;
//	fun4();
//	cout << "fun4结束" << endl;
//	cout << endl;
//	cout << "fun5开始" << endl;
//	fun5();
//	cout << "fun5结束" << endl;
//	cout << endl;
//	cout << "fun6开始" << endl;
//	fun6();
//	cout << "fun6结束" << endl;
//	cout << endl;
//	cout << "fun7开始" << endl;
//	fun7();
//	cout << "fun7结束" << endl;
//	cout << endl;
//	test t;
//	t.lambda();
//	return 0;
//}