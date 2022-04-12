//#include <iostream>
//#include <string>
//#include<typeinfo>
//using namespace std;
//// 基本概念：上行转换：派生=====>基类  下行转换：基类====>派生
//// 在类层次间进行上行转换时，dynamic_cast和static_cast的效果是一样的；
//// 在进行下行转换时，dynamic_cast具有类型检查的功能，比static_cast更安全
//
//
//class Base
//{  //有虚函数，因此是多态基类
//public:
//	virtual ~Base() {}
//};
//class Derived : public Base { };
//
//// 基类=====>派生类
//// dynamic_cast 多态基类的指针或引用强制转换==>派生类的指针或引用，
//// 检查转换的安全性(“运行时类型检查”来保证安全)。对于不安全的指针转换，转换结果返回 NULL 指针。
//
//// 用reinterpret_cast 可以将多态基类（包含虚函数的基类）的指针强制转换为派生类的指针，
//// 转换不检查安全性，即不检查转换后的指针是否确实指向一个派生类对象
//int main()
//{
//	Base b;
//	Derived d;
//	Derived* pd;
//	pd = reinterpret_cast <Derived*> (&b);
//	cout << typeid(&b).name() << endl;
//	cout << typeid(&pd).name() << endl;
//	if (pd == NULL)
//		//此处pd不会为 NULL。reinterpret_cast不检查安全性，总是进行转换
//		cout << "unsafe reinterpret_cast" << endl; //不会执行
//	pd = dynamic_cast <Derived*> (&b);
//	if (pd == NULL)  //结果会是NULL，因为 &b 不指向派生类对象，此转换不安全
//		cout << "unsafe dynamic_cast1" << endl;  //会执行
//	pd = dynamic_cast <Derived*> (&d);  //安全的转换
//	if (pd == NULL)  //此处 pd 不会为 NULL
//		cout << "unsafe dynamic_cast2" << endl;  //不会执行
//	return 0;
//}