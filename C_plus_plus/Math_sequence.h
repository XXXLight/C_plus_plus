#pragma once
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*****************************************************************
数列递增、递减、严格递增、严格递减、等差数列、等比数列判断
*****************************************************************/

//思路，检查所有，有一例外返回false
//是否是严格递增数列 <
template<typename T>
bool test_bigger_unequal(vector<T>& v) {
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i] >= v[i + 1])
			return false;
	}
	return true;
}
//递增，可以相等 <=
template<typename T>
bool test_bigger_equal(vector<T>& v) {
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i] > v[i + 1])
			return false;
	}
	return true;
}


//是否是严格递减数列 >
template<typename T>
bool test_lowwer_unequal(vector<T>& v) {
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i] <= v[i + 1])
			return false;
	}
	return true;
}

//递减，可以相等 >=
template<typename T>
bool test_lowwer_equal(vector<T>& v) {
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i] < v[i + 1])
			return false;
	}
	return true;
}

//测试等差数列
template<typename T>
bool test_dengcha(vector<T>& v) {
	auto d = v[1] - v[0];
	for (int i = 0; i < v.size()-1; i++) {
		if(v[i+1]-v[i]!=d)
		return false;
	}
	return true;
};