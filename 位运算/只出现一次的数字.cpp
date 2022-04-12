#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//0^a=a, a^a=0;这就是初始值必须为0的原因
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (auto e : nums) res ^= e;
		return res;
	}
};