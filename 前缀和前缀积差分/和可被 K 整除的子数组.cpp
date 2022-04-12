#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int subarraysDivByK(vector<int>& A, int K) {
		vector<int> sum(A.size() + 1); //开数组，前缀和数组，大小比原来大1
		sum[0] = 0; //第一个元素为0
		int res = 0; //结果
		unordered_map<int, int> mp;
		mp[0] = 1;
		for (int i = 0; i < A.size(); i++) {
			sum[i + 1] = sum[i] + A[i]; //递推公式模式
			int modulus = (sum[i + 1] % K + K) % K; //对负数求模特殊处理
			res += mp[modulus]; 
			mp[modulus]++; //计算余数出现次数
		}
		return res;
	}
};