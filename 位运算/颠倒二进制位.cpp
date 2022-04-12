#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		int res = 0;
		for (int i = 0; i < 32; i++) {
			int r = (n >> i) & 1; //È¡Î»
			int temp = r << (31 - i); //ÒÆÎ»
			res |= temp;
		}
		return res;
	}
};