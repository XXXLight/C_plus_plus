#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findTheWinner(int n, int k) {
		int p = 0; //  һ���˵�ʱ���ʤ���±��� 0,f(1,K)=0
		for (int i = 2; i <= n; i++) {
			p = (p + k) % i;//  f(N,K)=(f(N-1,K)+K)%N,N���ˣ���K�����ʤ���ߵ���������0��ʼ�㣩
		}
		return p + 1;
	}
};

class Solution {
public:
	int findTheWinner(int n, int k) {
		vector<int> v;
		vector<int> res; //��¼·����ģ��
		for (int i = 1; i <= n; ++i) v.push_back(i);
		int pos = 0;
		for (int i = 1; i < n; ++i)
		{
			pos = (pos + k - 1) % v.size();
			res.push_back(*(v.begin() + pos)); // ȡֵ*
			v.erase(v.begin() + pos); //������λ��
		}
		res.push_back(*v.begin());
		for (auto e : res) {
			cout << e << " ";
		}
		return v.front();
	}
};