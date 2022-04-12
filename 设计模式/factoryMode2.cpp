//#include<bits/stdc++.h>
//using namespace std;
//
////工厂方法模式
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
//		cout << "I am ProductA" << endl;
//	}
//};
//
//class ProductB :public Product {
//public:
//	void Show() {
//		cout << "I am ProductB" << endl;
//	}
//};
//
//class ProductC :public Product {
//public:
//	void Show() {
//		cout << "I am ProductC" << endl;
//	}
//};
//
//class Factory {
//public:
//	virtual Product* createProduct() = 0;
//};
//
//class FactoryA :public Factory {
//public:
//	Product *createProduct() {
//		return new ProductA();
//	}
//};
//
//class FactoryB :public Factory {
//public:
//	Product *createProduct() {
//		return new ProductB();
//	}
//};
//
//class FactoryC :public Factory {
//public:
//	Product *createProduct() {
//		return new ProductC();
//	}
//};
//
//int main()
//{
//	Factory *factoryA = new FactoryA();
//	Product *productA = factoryA->createProduct();
//	productA->Show();
//	Factory *factoryB = new FactoryB();
//	Product *productB = factoryB->createProduct();
//	productB->Show();
//	if (factoryA)
//	{
//		delete factoryA;
//		factoryA = NULL;
//	}
//	if (factoryB)
//	{
//		delete factoryB;
//		factoryB = NULL;
//	}
//	if (productA)
//	{
//		delete productA;
//		productA = NULL;
//	}
//	if (productB)
//	{
//		delete productB;
//		productB = NULL;
//	}
//	system("pause");
//	return 0;
//}
