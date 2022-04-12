//#include<bits/stdc++.h>
//using namespace std;
//
//
//// Why 智能指针
//// 动态内存管理经常出现两问题：一是忘记释放内存，会造成内存泄漏；
//// 一种是尚有指针引用内存的情况下就释放了它，就会产生引用非法内存的指针
//// 为更加安全的使用动态内存，引入了智能指针的概念。
//// 智能指针的行为类似常规指针，重要的区别是它负责自动释放所指向的对象,出{}作用域后
//class Entity {
//public:
//	Entity() { puts("Entity构造"); }
//	~Entity() { puts("Entity析构"); }
//};
//
//void ex1() {
//	puts("---------");
//	puts("Enter ex1"); 
//	{
//		puts("Enter ex1:scope1");
//		auto e1 = std::make_unique<Entity>();
//		puts("Leave ex1:scope1");
//	}
//	// 到此处对象已经析构了
//	puts("Leave ex1");
//}
//
//void foo(std::unique_ptr<Entity>) {
//	puts("Enter foo");
//	puts("Leave foo");
//}
//
//
//void ex2() {
//	puts("-------");
//	puts("Enter ex2");
//	auto e1 = std::make_unique<Entity>();
//	foo(std::move(e1));
//	// 调完函数自动析构了
//	puts("Leave ex2");
//}
//
//void ex3() {
//	puts("---------");
//	puts("Enter ex3");
//	auto e1 = std::make_shared<Entity>();
//	cout << e1.use_count() << endl;
//	{
//		puts("Enter ex3:scope1");
//		auto e2 = e1; // e1.use_count() e1 e2
//		cout << e1.use_count() << endl;
//		auto e3 = std::move(e2); // e1.use_count() e1 e3
//		cout << e1.use_count() << endl;
//		puts("Leave ex3");
//	}
//}
//
//void bar(Entity* e) {
//
//}
//
//void foo1() {
//	Entity* e = new Entity();
//	bar(e);
//}
//
//int main() {
//	ex1();
//	ex2();
//	foo1(); //单独执行发现只有构造，没有析构，存在内存泄漏
//	ex3();
//}