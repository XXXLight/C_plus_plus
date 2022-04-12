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
		//此处说明(num & num - 1)=0，只有一个1
		//下面保证1出现在奇数位
		if ((num & 0x55555555) == num)
			return true;
		return false;
	}
};
