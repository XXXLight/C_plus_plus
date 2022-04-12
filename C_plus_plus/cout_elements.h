#pragma once
#include<bits/stdc++.h>
using namespace std;

/*****************************************************************
重载cout<<实现各种容器简单输出
*****************************************************************/

//重载 << 输出一维vector,直接cout<<即可
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	for (auto e:v) os << e << " ";
	os << endl;
	return os;
}

//重载 << 输出二维vector，直接cout<<即可
template<typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
	for (auto e1 : v) {
		for (auto e2 : e1) {
			os << e2 << " ";
		}
		os << endl;
	}
	return os;
}

//重载 << 输出set元素
template<typename T>
ostream& operator<<(ostream& os, const set<T>& st) {
	for (auto e:st) os <<e<< " ";
	os << endl;
	return os;
}

//重载 << 输出map内元素
template<typename T1,typename T2>
ostream& operator<<(ostream& os, const map<T1,T2>& mp) {
	for (auto e : mp) {
		os << e.first << " : " << e.second << " " << endl;
	}
	return os;
}

//重载 << 输出unordered_map内元素
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const unordered_map<T1, T2>& u_mp) {
	for (auto e : u_mp) {
		os << e.first << " : " << e.second << " " << endl;
	}
	return os;
}

//重载 << 输出deque,直接cout<<即可
template<typename T>
ostream& operator<<(ostream& os, const deque<T>& dq) {
	for (auto e : dq) os << e << " ";
	os << endl;
	return os;
}

//重载 << 输出list,直接cout<<即可
template<typename T>
ostream& operator<<(ostream& os, const list<T>& l) {
	for (auto e : l) os << e << " ";
	os << endl;
	return os;
}


template<typename T>
ostream& operator<<(ostream& os, const unordered_set<T> ust) {
	for (auto e : ust) {
		os << e << " ";
	}
	os << endl;
	return os;
}


//东西多了可以包在namespace中间，真正的深入理解
//Sort_Index实现排序并返回原始下标，确保是稳定排序
namespace Sort_Index {
	typedef int data_type;//在此处针对数据修改类型,只要修改data_type前的就可以
	typedef struct TagNode
	{
		data_type value;
		int index;
	}Node;

	bool myCmp(const Node& a, const Node& b)
	{
		return a.value < b.value;
	}
	vector<int> sort_index(vector<data_type> &v) {
		vector<Node> coll;
		vector<int> index;
		Node tmp;
		for (int i = 0; i < v.size(); i++) {
			tmp.index = i;
			tmp.value = v[i];
			coll.push_back(tmp);
		}
		stable_sort(coll.begin(), coll.end(), myCmp);
		vector<Node>::iterator pos;
		for (pos = coll.begin(); pos != coll.end(); ++pos)
		{
			index.push_back(pos->index);
		}
		return index;
	}
};

