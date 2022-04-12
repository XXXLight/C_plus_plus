//#include<bits/stdc++.h>
//using namespace std;
////简单工厂模式
//typedef enum ProductTypeTag {
//	TypeA,
//	TypeB,
//	TypeC
//}PRODUCTTYPE;
//class Product {
//public:
//	virtual void Show() = 0;
//};
//class ProductA :public Product {
//public:
//	void Show() {
//		cout << "I am productA" << endl;
//	}
//};
//class ProductB :public Product {
//public:
//	void Show() {
//		cout << "I am productB" << endl;
//	}
//};
//class ProductC :public Product {
//public:
//	void Show() {
//		cout << "I am productC" << endl;
//	}
//};
//class Factory {
//public:
//	Product* CreateProduct(PRODUCTTYPE type) {
//		switch (type)
//		{
//		case TypeA:
//			return new ProductA();
//		case TypeB:
//			return new ProductB();
//		case TypeC:
//			return new ProductC();
//		default:
//			return NULL;
//		}
//	}
//};
//
//int main()
//{
//	Factory productCreator;
//	Product *productA = productCreator.CreateProduct(TypeA);
//	Product *productB = productCreator.CreateProduct(TypeB);
//	Product *productC = productCreator.CreateProduct(TypeC);
//	productA->Show();
//	productB->Show();
//	productC->Show();
//	if (productA) {
//		delete productA;
//		productA = NULL;
//	}
//	if (productB) {
//		delete productB;
//		productB = NULL;
//	}
//	if (productC) {
//		delete productC;
//		productC = NULL;
//	}
//	system("pause");
//	return 0;
//}
//
//
