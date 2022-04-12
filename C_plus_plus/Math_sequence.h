#pragma once
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*****************************************************************
���е������ݼ����ϸ�������ϸ�ݼ����Ȳ����С��ȱ������ж�
*****************************************************************/

//˼·��������У���һ���ⷵ��false
//�Ƿ����ϸ�������� <
template<typename T>
bool test_bigger_unequal(vector<T>& v) {
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i] >= v[i + 1])
			return false;
	}
	return true;
}
//������������� <=
template<typename T>
bool test_bigger_equal(vector<T>& v) {
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i] > v[i + 1])
			return false;
	}
	return true;
}


//�Ƿ����ϸ�ݼ����� >
template<typename T>
bool test_lowwer_unequal(vector<T>& v) {
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i] <= v[i + 1])
			return false;
	}
	return true;
}

//�ݼ���������� >=
template<typename T>
bool test_lowwer_equal(vector<T>& v) {
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i] < v[i + 1])
			return false;
	}
	return true;
}

//���ԵȲ�����
template<typename T>
bool test_dengcha(vector<T>& v) {
	auto d = v[1] - v[0];
	for (int i = 0; i < v.size()-1; i++) {
		if(v[i+1]-v[i]!=d)
		return false;
	}
	return true;
};