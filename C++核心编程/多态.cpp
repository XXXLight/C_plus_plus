//#include<bits/stdc++.h>
//using namespace std;
//
//class Animal {
//public:
//	// //����ǰ�����virtual�ؼ��֣�����麯������ô�������ڱ����ʱ��Ͳ���ȷ�����������ˡ�
//	virtual void speak() {
//		cout << "������˵��" << endl;
//	}
//};
//
//class Cat :public Animal {
//public:
//	void speak() {
//		cout << "Сè��˵��" << endl;
//	}
//};
//
//class Dog :public Animal {
//public:
//	void speak() {
//		cout << "С����˵��" << endl;
//	}
//};
//
//// ���������ַ�ڱ���׶ξ���ȷ������ô��̬����
////���������ַ�����н׶β���ȷ�������Ƕ�̬����
//// �����Ǹ��࣬�����ഫ����
//void DoSpeak(Animal& animal) {
//	animal.speak();
//}
//
////��̬���������� 
////1���м̳й�ϵ
////2��������д�����е��麯��
////��̬ʹ�ã�
////����ָ�������ָ���������
//void test01() {
//	Cat cat;
//	DoSpeak(cat);
//
//	Dog dog;
//	DoSpeak(dog);
//
//	// ��߸��࣬�ұ����࣬����ָ�������ָ������������
//	Animal* ani = new Cat();
//	ani->speak();
//}
//
//int main() {
//	test01();
//	return 0;
//}