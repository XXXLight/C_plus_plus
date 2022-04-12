#pragma once
#include<bits/stdc++.h>
using namespace std;

/*****************************************************************
����cout<<ʵ�ָ������������
*****************************************************************/

//���� << ���һάvector,ֱ��cout<<����
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	for (auto e:v) os << e << " ";
	os << endl;
	return os;
}

//���� << �����άvector��ֱ��cout<<����
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

//���� << ���setԪ��
template<typename T>
ostream& operator<<(ostream& os, const set<T>& st) {
	for (auto e:st) os <<e<< " ";
	os << endl;
	return os;
}

//���� << ���map��Ԫ��
template<typename T1,typename T2>
ostream& operator<<(ostream& os, const map<T1,T2>& mp) {
	for (auto e : mp) {
		os << e.first << " : " << e.second << " " << endl;
	}
	return os;
}

//���� << ���unordered_map��Ԫ��
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const unordered_map<T1, T2>& u_mp) {
	for (auto e : u_mp) {
		os << e.first << " : " << e.second << " " << endl;
	}
	return os;
}

//���� << ���deque,ֱ��cout<<����
template<typename T>
ostream& operator<<(ostream& os, const deque<T>& dq) {
	for (auto e : dq) os << e << " ";
	os << endl;
	return os;
}

//���� << ���list,ֱ��cout<<����
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


//�������˿��԰���namespace�м䣬�������������
//Sort_Indexʵ�����򲢷���ԭʼ�±꣬ȷ�����ȶ�����
namespace Sort_Index {
	typedef int data_type;//�ڴ˴���������޸�����,ֻҪ�޸�data_typeǰ�ľͿ���
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

