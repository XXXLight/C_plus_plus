#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
	mt19937 gen;// 如果想产生很大的随机数(几亿，甚至几十亿)，就要用到 mt19937
	uniform_int_distribution<int> dis;
	vector<int> pre;

public:
	Solution(vector<int>& w) : gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {
		partial_sum(w.begin(), w.end(), back_inserter(pre));
	}

	int pickIndex() {
		int x = dis(gen);
		return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
	}
};

