//#include<bits/stdc++.h>
//#include<unordered_map>
//#include<queue>
//#include "cout_elements.h"
//#include "points_2D.h"
//#include "Union_Find.h"
//#include "Binary_search.h"
//#include "Math_sequence.h"
//
//using namespace std;
//void test_cout_elements() {
//	cout << "//****************************测试cout输出重载*************************************//"<<endl;
//	vector<int> v = { 1,2,3,4,5,6 };
//	vector<vector<double>> d2 = { {2.4,3.5,6.6},{1.0,3.3,4.9},{3.3,9.9} };
//	vector<string> s = { "fdsvsh","JHDCBH","fhavDFJKV" };
//	set<double> st = { 1.233,4.56,4.56,6.666 };
//	deque<int> dq = { 1,2,3,6,5,4 };
//	list<double> l = { 6.6,7.7,8.8 };
//	map<int, double> mp;
//	mp.insert(make_pair(1,3.6));
//	mp.insert(make_pair(2, 6.6));
//	cout << v;
//	cout << d2;
//	cout << s;
//	cout << st;
//	cout << dq;
//	cout << l;
//	cout << mp;
//}
//
//void test_points_2D() {
////*********************************************************************************//
////测试二维计算几何
//	cout << "//****************************测试二维计算几何*************************************//"<<endl;
//	Point p1, p2, p_add,p_sub,p_mul,p_div;
//	p1.x = 3, p1.y = 4;
//	p2.x = 1, p2.y = 9;
//	p_add = p1 + p2;
//	p_sub = p1 - p2;
//	p_mul = p1 * 3;
//	p_div = p1 / 2;
//	cout << "Length(p1):" << Length({3,4}) << endl;
//	cout << "Dot(p1, p2):"<< Dot(p1, p2) << endl;
//	cout << "Angle(p1, p2):" << Angle({ 0,1 }, {1,0}) << endl;
//}
//void test_Union_Find() {
////*********************************************************************************//
////测试并查集
//	cout << "//*******************************测试并查集**********************************//"<<endl;
//	int num[20] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
//	UF *uf = new UF(20);
//	int count_res;
//	// 存储若干棵树
//	int* parent_res = new int[20];
//	// 记录树的“重量”
//	int* size_res = new int[20];
//	uf->union_(0, 1);
//	uf->union_(2, 1);
//	uf->union_(3, 1);
//	uf->union_(4, 10);
//	uf->union_(4, 5);
//	uf->union_(5, 6);
//	uf->union_(6, 7);
//	uf->union_(7, 8);
//	uf->union_(8, 9);
//	uf->union_(11, 12);
//	uf->union_(12, 13);
//	uf->union_(13, 14);
//	uf->union_(11, 15);
//	uf->union_(16, 17);
//	uf->union_(17, 18);
//	uf->union_(18, 19);
//	count_res = uf->count_num();
//	cout << "连通数量" << count_res << endl;
//	parent_res = uf->parent;
//	cout << "parent数组" << endl;
//	for (int i = 0; i < 20; i++) cout << parent_res[i] << " ";
//	cout << endl;
//	size_res = uf->size;
//	cout << "size数组" << endl;
//	for (int i = 0; i < 20; i++) cout << size_res[i] << " ";
//	cout << endl;
//}
//
//void test_binarySearch() {
//	cout << "=============test_binary_search==============" << endl;
//	vector<int> nums = { 1,1,2,3,4,5,6,7 };
//	int target = 2;
//	cout << binary_search(nums, target) << endl;
//}
//
//void test_left_bound() {
//	cout << "=============test_left_bound==============" << endl;
//	vector<int> nums = { 1,1,2,2,2,2,2,3,3,4,5,6,7 };
//	int target1 = 2;
//	cout << left_bound(nums, target1) << endl;
//	int target2 = 100;
//	cout << left_bound(nums, target2) << endl;
//}
//
//void test_right_bound() {
//	cout << "=============test_right_bound==============" << endl;
//	vector<int> nums = { 1,1,2,2,3,6,6,6,6,6,6,7,8,9 };
//	int target = 6;
//	cout << right_bound(nums, target) << endl;
//}
//
//void test_sequence() {
//	cout << "=============数列测试==============" << endl;
//	vector<int> v1 = { 1,2,3,6,7,8 };
//	vector<int> v2 = { 1,2,3,1,2,3 };
//	vector<double> v3 = { 1.1,2.2,2.2,3.3,4.4 };
//	vector<int> v4 = { 4,3,2,1 };
//	vector<int> v5 = { 6,6,5,4,3,2,1 };
//	vector<double> v6 = { 9.9,8.8,6.6,3.3 };
//	cout << test_bigger_equal(v3)<<endl;
//	cout << test_bigger_unequal(v1)<<endl;
//	cout << test_bigger_unequal(v3) << endl;
//	cout << test_lowwer_equal(v5) << endl;
//	cout << test_lowwer_unequal(v6) << endl;
//	cout << test_dengcha(v4) << endl;
//}
//int main() {
//	test_cout_elements();
//	test_points_2D();
//	test_Union_Find();
//	test_binarySearch();
//	test_left_bound();
//	test_right_bound();
//	test_sequence();
//	return 0;
//}