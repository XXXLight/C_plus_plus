#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int cuttingRope(int n) {
		if (n <= 3) return n - 1;
		int res = 1;
		while (n > 4) {
			n -= 3;
			res *= 3;
		}
		// �˳�ѭ��ʱn<=4
		res *= n;
		return res;
	}
};