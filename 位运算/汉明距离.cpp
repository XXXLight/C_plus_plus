#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//调库呗
class Solution {
public:
	int hammingDistance(int x, int y) {
		return bitset<32>(x^y).count();
	}
};


class Solution {
public:
	int hammingDistance(int x, int y) {
		//异或
		int z = x ^ y;

		//数1的位数
		int res = 0;
		while (z) {
			z &= z - 1;
			res++;
		}
		return res;
	}
};