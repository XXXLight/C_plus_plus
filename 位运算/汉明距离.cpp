#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//������
class Solution {
public:
	int hammingDistance(int x, int y) {
		return bitset<32>(x^y).count();
	}
};


class Solution {
public:
	int hammingDistance(int x, int y) {
		//���
		int z = x ^ y;

		//��1��λ��
		int res = 0;
		while (z) {
			z &= z - 1;
			res++;
		}
		return res;
	}
};