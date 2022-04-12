#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int subarraysDivByK(vector<int>& A, int K) {
		vector<int> sum(A.size() + 1); //�����飬ǰ׺�����飬��С��ԭ����1
		sum[0] = 0; //��һ��Ԫ��Ϊ0
		int res = 0; //���
		unordered_map<int, int> mp;
		mp[0] = 1;
		for (int i = 0; i < A.size(); i++) {
			sum[i + 1] = sum[i] + A[i]; //���ƹ�ʽģʽ
			int modulus = (sum[i + 1] % K + K) % K; //�Ը�����ģ���⴦��
			res += mp[modulus]; 
			mp[modulus]++; //�����������ִ���
		}
		return res;
	}
};