//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	operator int() { return 1; }
//	operator char*() { return NULL; }
//};
//
//// ����ת����  <ת����target>(ת��ǰsrc)
//
//// static_cast �ͷ��յ�ת���������ͺ͸����͡��ַ���֮��Ļ���ת����
//
//// static_cast ���������ڲ�ͬ���͵�ָ��֮�以��ת����Ҳ�����������ͺ�ָ��֮��Ļ���ת����
//// ��ȻҲ�������ڲ�ͬ���͵�����֮���ת������Ϊ���ոߡ�
//int main()
//{
//	A a;
//	int n;
//	const char* p="Hello World!";
//	n = static_cast <int> (3.14);  // n ��ֵ��Ϊ 3
//	n = static_cast <int> (a);  //���� a.operator int��n ��ֵ��Ϊ 1
//	p = static_cast <char*> (a);  //���� a.operator char*��p ��ֵ��Ϊ NULL
//	//n = static_cast <int> (p);  //�������static_cast���ܽ�ָ��ת��������
//	//p = static_cast <char*> (n);  //�������static_cast ���ܽ�����ת����ָ��
//	return 0;
//}