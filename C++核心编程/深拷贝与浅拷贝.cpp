//#include<bits/stdc++.h>
//using namespace std;
//
//class Person {
//public:
//	// �����ǳ�����漰������ָ������,�ڶ��Ͽ��ٵ��ڴ�
//	int* height;
//	// �вι���
//	Person(int h) {
//		height = new int(h);
//	}
//	// û���Լ��Ŀ���������õ���Ĭ�ϵ�ǳ��������
//
//	//�Լ�д�Ŀ������죬���Ƶ����������
//	Person(const Person& p) {
//		height = new int(*p.height);
//	}
//
//	// ����
//	~Person() {
//		if (height != nullptr) {
//			delete height;
//		}
//		// ���������������ǳ����ֻ������һ�Σ��������������
//		cout << "��������" << endl;
//	}
//};
//
//int main() {
//	Person P1(180);
//	Person P2(P1);
//	cout << *P1.height << " " << *P2.height << endl;
//	return 0;
//}