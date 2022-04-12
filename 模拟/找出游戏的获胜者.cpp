#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findTheWinner(int n, int k) {
		int p = 0; //  一个人的时候获胜者下标是 0,f(1,K)=0
		for (int i = 2; i <= n; i++) {
			p = (p + k) % i;//  f(N,K)=(f(N-1,K)+K)%N,N个人，数K，最后胜利者的索引（从0开始算）
		}
		return p + 1;
	}
};

class Solution {
public:
	int findTheWinner(int n, int k) {
		vector<int> v;
		vector<int> res; //记录路径，模拟
		for (int i = 1; i <= n; ++i) v.push_back(i);
		int pos = 0;
		for (int i = 1; i < n; ++i)
		{
			pos = (pos + k - 1) % v.size();
			res.push_back(*(v.begin() + pos)); // 取值*
			v.erase(v.begin() + pos); //传的是位置
		}
		res.push_back(*v.begin());
		for (auto e : res) {
			cout << e << " ";
		}
		return v.front();
	}
};