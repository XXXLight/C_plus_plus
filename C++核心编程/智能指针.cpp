//#include<bits/stdc++.h>
//using namespace std;
//
//
//// Why ����ָ��
//// ��̬�ڴ���������������⣺һ�������ͷ��ڴ棬������ڴ�й©��
//// һ��������ָ�������ڴ������¾��ͷ��������ͻ�������÷Ƿ��ڴ��ָ��
//// Ϊ���Ӱ�ȫ��ʹ�ö�̬�ڴ棬����������ָ��ĸ��
//// ����ָ�����Ϊ���Ƴ���ָ�룬��Ҫ���������������Զ��ͷ���ָ��Ķ���,��{}�������
//class Entity {
//public:
//	Entity() { puts("Entity����"); }
//	~Entity() { puts("Entity����"); }
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
//	// ���˴������Ѿ�������
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
//	// ���꺯���Զ�������
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
//	foo1(); //����ִ�з���ֻ�й��죬û�������������ڴ�й©
//	ex3();
//}