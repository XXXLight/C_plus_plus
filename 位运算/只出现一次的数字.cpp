#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//0^a=a, a^a=0;����ǳ�ʼֵ����Ϊ0��ԭ��
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (auto e : nums) res ^= e;
		return res;
	}
};