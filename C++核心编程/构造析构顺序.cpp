//#include<bits/stdc++.h>
//using namespace std;
//
//// A has B,�ȹ���B
//// Phone��Person��has��ϵ��Person has Phone
//class Phone
//{
//public:
//	Phone(string name)
//	{
//		m_PhoneName = name;
//		cout << "Phone����" << endl;
//	}
//
//	~Phone()
//	{
//		cout << "Phone����" << endl;
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
//	//��ʼ���б���Ը��߱�����������һ�����캯��
//	Person(string name, string pName) :m_Name(name), m_Phone(pName)
//	{
//		cout << "Person����" << endl;
//	}
//
//	~Person()
//	{
//		cout << "Person����" << endl;
//	}
//
//	void playGame()
//	{
//		cout << m_Name << " ʹ��" << m_Phone.m_PhoneName << " ���ֻ�! " << endl;
//	}
//
//	string m_Name;
//	Phone m_Phone;
//
//};
//void test01()
//{
//	//�����г�Ա�����������ʱ�����ǳƸó�ԱΪ �����Ա
//	//�����˳���� ���ȵ��ö����Ա�Ĺ��죬�ٵ��ñ��๹��
//	//����˳���빹���෴
//	Person p("����", "ƻ��X");
//	p.playGame();
//
//}
//
//// A is B,�ȹ���B
//// Son��Base��is��ϵ��Son��Base
//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base���캯��!" << endl;
//	}
//	~Base()
//	{
//		cout << "Base��������!" << endl;
//	}
//};
//
//class Son : public Base
//{
//public:
//	Son()
//	{
//		cout << "Son���캯��!" << endl;
//	}
//	~Son()
//	{
//		cout << "Son��������!" << endl;
//	}
//
//};
//
//
//void test02()
//{
//	//�̳��� �ȵ��ø��๹�캯�����ٵ������๹�캯��������˳���빹���෴
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
