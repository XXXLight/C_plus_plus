#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num <= 0)
			return false;
		if ((num & num - 1) != 0)
			return false;
		//�˴�˵��(num & num - 1)=0��ֻ��һ��1
		//���汣֤1����������λ
		if ((num & 0x55555555) == num)
			return true;
		return false;
	}
};
