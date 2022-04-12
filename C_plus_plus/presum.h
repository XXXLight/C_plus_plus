#pragma once
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

//一维前缀和技巧
//  vector<int> v:1 2 3 4 5 6 7 8 9
//	  =>   presum:0 1 3 6 10 15 21 .....
//    =>  sum_i_j: presum[j+1]-presum[i]
int pre_sum0(vector<int>& v, int i, int j) {
	vector<int> add_sum;
	add_sum.push_back(0);
	int sum = 0;
	for (auto e : v) {
		sum += e;
		add_sum.push_back(sum);
	}
	return (add_sum[j + 1] - add_sum[i]);
}




