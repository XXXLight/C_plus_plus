#include<bits/stdc++.h>
using namespace std;


//  �Ķ��ۣ� �߽�+tDtD
//	�����ۣ� �߽�+for(tDt)
//	�����ظ�Ԫ�أ��ܷ�����ѡ�����ظ�Ԫ����Ҫȥ�أ�����ѡ�����depth


//	�����������йأ��������Ļ��ݣ�ֱ�ӿ������нڵ㣩�Ķ��۸���ݹ�

//  {a,b,c}��ȫ���У�abc��acb��bac��bca��cab��cba
//  1.abcû��prev_permutation��cbaû��next_permutation
//  2.���ɵ�ȫ�����ǰ����ֵ�˳��������е�


// ��ά����ȥ��API,���ù��캯��ֱ�ӹ���
vector<vector<int>> setVector(vector<vector<int>>& vv) {
	//����setȥ��
	set<vector<int>> stVec(vv.begin(), vv.end());
	vector<vector<int>> res(stVec.begin(), stVec.end());
	return res;
}