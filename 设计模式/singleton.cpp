//#include<bits/stdc++.h>
//using namespace std;
////单例模式的实现
//
//// 概念：让你能够保证一个类只有一个实例， 并提供一个访问该实例的全局节点。
//class Singleton {
//public:
//	//全局访问点
//	static Singleton& getInstance() {
//		static Singleton instance;//类内唯一构造的实例
//		return instance;
//	}
//	void printTest() {
//		cout << "do something" << endl;
//	}
//private://所有构造函数的访问权限标记为private
//	Singleton() {};
//	//Singleton(Singleton const &singleton);
//	//Singleton& operator=(Singleton const singleton);
//};
//
//int main() {
//	Singleton &a = Singleton::getInstance();
//	a.printTest();
//	system("pause");
//	return 0;
//}