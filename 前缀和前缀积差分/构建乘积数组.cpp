#include<bits/stdc++.h>
using namespace std;

// ���ΪʲôҪ��ǰ׺��

class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		if (a.size() == 0) return {};
		vector<int> left(a.size()); //ǰ׺��
		vector<int> right(a.size()); //����ǰ׺��
		vector<int> res(a.size());
		left[0] = 1;
		right[a.size() - 1] = 1;
		for (int i = 1; i < a.size(); i++) {
			left[i] = left[i - 1] * a[i - 1];//ע�������� i i-1 i-1 ������ģʽ
		}
		for (int i = a.size() - 1; i > 0; i--) {
			right[i - 1] = right[i] * a[i]; //ע�������� i-1 i i ������ģʽ
		}
		for (int i = 0; i < a.size(); i++) {
			res[i] = left[i] * right[i];
		}
		return res;
	}
};


class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		int n = a.size();
		vector<int> res(n, 1);
		int l = 1, r = 1;
		for (int i = 0, j = n - 1; i < a.size() && j >= 0; i++, j--) {
			res[i] *= l; l *= a[i];
			res[j] *= r; r *= a[j];
		}
		return res;
	}
};