#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int add(int a, int b) {
		while (b != 0) {
			auto carry = (unsigned int)(a & b) << 1;
			a ^= b;
			b = carry;
		}
		return a;
	}
};

