//#include <iostream>
//#include <string>
//#include<typeinfo>
//using namespace std;
//// �����������ת��������=====>����  ����ת��������====>����
//// �����μ��������ת��ʱ��dynamic_cast��static_cast��Ч����һ���ģ�
//// �ڽ�������ת��ʱ��dynamic_cast�������ͼ��Ĺ��ܣ���static_cast����ȫ
//
//
//class Base
//{  //���麯��������Ƕ�̬����
//public:
//	virtual ~Base() {}
//};
//class Derived : public Base { };
//
//// ����=====>������
//// dynamic_cast ��̬�����ָ�������ǿ��ת��==>�������ָ������ã�
//// ���ת���İ�ȫ��(������ʱ���ͼ�顱����֤��ȫ)�����ڲ���ȫ��ָ��ת����ת��������� NULL ָ�롣
//
//// ��reinterpret_cast ���Խ���̬���ࣨ�����麯���Ļ��ࣩ��ָ��ǿ��ת��Ϊ�������ָ�룬
//// ת������鰲ȫ�ԣ��������ת�����ָ���Ƿ�ȷʵָ��һ�����������
//int main()
//{
//	Base b;
//	Derived d;
//	Derived* pd;
//	pd = reinterpret_cast <Derived*> (&b);
//	cout << typeid(&b).name() << endl;
//	cout << typeid(&pd).name() << endl;
//	if (pd == NULL)
//		//�˴�pd����Ϊ NULL��reinterpret_cast����鰲ȫ�ԣ����ǽ���ת��
//		cout << "unsafe reinterpret_cast" << endl; //����ִ��
//	pd = dynamic_cast <Derived*> (&b);
//	if (pd == NULL)  //�������NULL����Ϊ &b ��ָ����������󣬴�ת������ȫ
//		cout << "unsafe dynamic_cast1" << endl;  //��ִ��
//	pd = dynamic_cast <Derived*> (&d);  //��ȫ��ת��
//	if (pd == NULL)  //�˴� pd ����Ϊ NULL
//		cout << "unsafe dynamic_cast2" << endl;  //����ִ��
//	return 0;
//}