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
//		auto fun = [this] { // ������ this ָ��
//			this->hello(); // ���� this ���õľ��� class test �Ķ�����
//		};
//		fun();
//	}
//};
//
//
//// ����һ������������ִ��
//void fun1() {
//	[]() {
//		cout << "Hello World!" << endl;
//	}();
//}
//
//// ����Ҳ���Է���Ľ��������������������ֵ�������ã�
//void fun2() {
//	int i = 1024;
//	auto func = [](int i) {
//		cout << i << endl;
//	};
//	func(i);
//}
//
//// [] �������κα���,����
////void fun3() {
////	int i = 1024;
////	auto func = [] {cout << i; };
////	func();
////}
//
//// [=] ��������,�������ݣ���ַ��ͬ
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
//// [&] ���ò���һ�����ݣ���ַ��ͬ
//void fun5() {
//	int i = 1024;
//	cout << &i << endl;
//	auto fun1 = [&] {
//		cout << &i << endl;
//	};
//	fun1();
//}
//
//// ���߻���
//void fun6() {
//	int i = 1024, j = 2048;
//	cout << "i:" << &i << endl;
//	cout << "j:" << &j << endl;
//	auto fun1 = [=, &i] { // Ĭ�Ͽ����ⲿ���б����������ñ��� i
//		cout << "i:" << &i << endl;
//		cout << "j:" << &j << endl;
//	};
//	fun1();
//}
//
//// [bar] ָ�����û򿽱�
//void fun7() {
//	int i = 1024, j = 2048, k;
//
//	cout << "outside i:" << &i << endl;
//	cout << "outside j:" << &j << endl;
//
//	auto fun1 = [i, &j] {
//		cout << "inside  i:" << &i << endl;
//		cout << "inside  j:" << &j << endl;
//		// cout << k; // k δ����
//	};
//	fun1();
//}
//int main() {
//	cout << "fun1��ʼ" << endl;
//	fun1();
//	cout << "fun1����" << endl;
//	cout << endl;
//	cout << "fun2��ʼ" << endl;
//	fun2();
//	cout << "fun2����" << endl;
//	cout << endl;
//	cout << "fun4��ʼ" << endl;
//	fun4();
//	cout << "fun4����" << endl;
//	cout << endl;
//	cout << "fun5��ʼ" << endl;
//	fun5();
//	cout << "fun5����" << endl;
//	cout << endl;
//	cout << "fun6��ʼ" << endl;
//	fun6();
//	cout << "fun6����" << endl;
//	cout << endl;
//	cout << "fun7��ʼ" << endl;
//	fun7();
//	cout << "fun7����" << endl;
//	cout << endl;
//	test t;
//	t.lambda();
//	return 0;
//}