//#include <iostream>
//#include <memory>
//
//int main() {
//	{
//		std::unique_ptr<int> uptr(new int(10));  //�󶨶�̬����
//		//std::unique_ptr<int> uptr2 = uptr;  //�����xֵ
//		//std::unique_ptr<int> uptr2(uptr);  //���ܿ�ؐ
//		std::unique_ptr<int> uptr2 = std::move(uptr); //�D�Q���Й�
//		uptr2.release(); //�ͷ�����Ȩ
//	}
//	//���^uptr�������򣬃ȴ�ጷ�
//}