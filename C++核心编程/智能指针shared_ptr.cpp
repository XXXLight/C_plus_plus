#include <iostream>
#include <memory>

// �Ƽ���auto������
int main() {
	{
		int a = 10;
		auto ptra = std::make_shared<int>(a); //ָ��ָ�����a
		auto ptra2(ptra); //copy

		// ��Ϊptra���������� ptra��ptra2
		std::cout << ptra.use_count() << std::endl;
		

		int b = 20;
		int *pb = &a;
		//std::shared_ptr<int> ptrb = pb;  //error
		auto ptrb = std::make_shared<int>(b);
		ptra2 = ptrb; //assign  ,�˴�ptra2�Ѿ�����ptrb,����ptra����Ϊ1
		pb = ptrb.get(); //��ȡԭʼָ��

		std::cout << ptra.use_count() << std::endl;
		std::cout << ptrb.use_count() << std::endl;
	}
}