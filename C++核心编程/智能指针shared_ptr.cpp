#include <iostream>
#include <memory>

// 推荐用auto来接收
int main() {
	{
		int a = 10;
		auto ptra = std::make_shared<int>(a); //指针指向变量a
		auto ptra2(ptra); //copy

		// 因为ptra有两个引用 ptra、ptra2
		std::cout << ptra.use_count() << std::endl;
		

		int b = 20;
		int *pb = &a;
		//std::shared_ptr<int> ptrb = pb;  //error
		auto ptrb = std::make_shared<int>(b);
		ptra2 = ptrb; //assign  ,此处ptra2已经给了ptrb,所以ptra计数为1
		pb = ptrb.get(); //获取原始指针

		std::cout << ptra.use_count() << std::endl;
		std::cout << ptrb.use_count() << std::endl;
	}
}