//#include<bits/stdc++.h>
//using namespace std;
//
////抽象工厂模式
//class ProductA
//{
//public:
//	virtual void Show() = 0;
//};
//class ProductA1 : public ProductA//A类低端产品
//{
//public:
//	void Show()
//	{
//		cout << "I'm ProductA1" << endl;
//	}
//};
//class ProductA2 : public ProductA//A类高端产品
//{
//public:
//	void Show()
//	{
//		cout << "I'm ProductA2" << endl;
//	}
//};
//class ProductB
//{
//public:
//	virtual void Show() = 0;
//};
//class ProductB1 : public ProductB//B类低端产品
//{
//public:
//	void Show()
//	{
//		cout << "I'm ProductB1" << endl;
//	}
//};
//class ProductB2 : public ProductB//B类高端产品
//{
//public:
//	void Show()
//	{
//		cout << "I'm ProductB2" << endl;
//	}
//};
//class Factory
//{
//public:
//	virtual ProductA *CreateProductA() = 0;
//	virtual ProductB *CreateProductB() = 0;
//};
//class Factory1 : public Factory//1号工厂用于生产低端产品
//{
//public:
//	ProductA *CreateProductA()
//	{
//		return new ProductA1();
//	}
//	ProductB *CreateProductB()
//	{
//		return new ProductB1();
//	}
//};
//class Factory2 : public Factory//2号工厂用于生产高端产品
//{
//	ProductA *CreateProductA()
//	{
//		return new ProductA2();
//	}
//	ProductB *CreateProductB()
//	{
//		return new ProductB2();
//	}
//};
//
//
//int main()
//{
//	Factory *factory1 = new Factory1();
//	ProductA *productA1 = factory1->CreateProductA();
//	ProductB *productB1 = factory1->CreateProductB();
//	productA1->Show();
//	productB1->Show();
//	Factory *factory2 = new Factory2();
//	ProductA *productA2 = factory2->CreateProductA();
//	ProductB *productB2 = factory2->CreateProductB();
//	productA2->Show();
//	productB2->Show();
//	if (factory1)
//	{
//		delete factory1;
//		factory1 = NULL;
//	}
//	if (productA1)
//	{
//		delete productA1;
//		productA1 = NULL;
//	}
//	if (productB1)
//	{
//		delete productB1;
//		productB1 = NULL;
//	}
//	if (factory2)
//	{
//		delete factory2;
//		factory2 = NULL;
//	}
//	if (productA2)
//	{
//		delete productA2;
//		productA2 = NULL;
//	}
//	if (productB2)
//	{
//		delete productB2;
//		productB2 = NULL;
//	}
//	//system("pause");
//	return 0;
//}