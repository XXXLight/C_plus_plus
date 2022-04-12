//#include<bits/stdc++.h>
//using namespace std;
//
//// A has B,先构造B
//// Phone与Person是has关系，Person has Phone
//class Phone
//{
//public:
//	Phone(string name)
//	{
//		m_PhoneName = name;
//		cout << "Phone构造" << endl;
//	}
//
//	~Phone()
//	{
//		cout << "Phone析构" << endl;
//	}
//
//	string m_PhoneName;
//
//};
//
//
//class Person
//{
//public:
//
//	//初始化列表可以告诉编译器调用哪一个构造函数
//	Person(string name, string pName) :m_Name(name), m_Phone(pName)
//	{
//		cout << "Person构造" << endl;
//	}
//
//	~Person()
//	{
//		cout << "Person析构" << endl;
//	}
//
//	void playGame()
//	{
//		cout << m_Name << " 使用" << m_Phone.m_PhoneName << " 牌手机! " << endl;
//	}
//
//	string m_Name;
//	Phone m_Phone;
//
//};
//void test01()
//{
//	//当类中成员是其他类对象时，我们称该成员为 对象成员
//	//构造的顺序是 ：先调用对象成员的构造，再调用本类构造
//	//析构顺序与构造相反
//	Person p("张三", "苹果X");
//	p.playGame();
//
//}
//
//// A is B,先构造B
//// Son与Base是is关系，Son是Base
//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base构造函数!" << endl;
//	}
//	~Base()
//	{
//		cout << "Base析构函数!" << endl;
//	}
//};
//
//class Son : public Base
//{
//public:
//	Son()
//	{
//		cout << "Son构造函数!" << endl;
//	}
//	~Son()
//	{
//		cout << "Son析构函数!" << endl;
//	}
//
//};
//
//
//void test02()
//{
//	//继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
//	Son s;
//}
//
//int main() {
//	test01();
//	cout << endl;
//	test02();
//	return 0;
//}
//
