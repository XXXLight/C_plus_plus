#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//����
class Solution {
public:
	int hammingWeight(uint32_t n) {
		return bitset<32>(n).count();
	}
};
// ���ߵ���
class Solution {
public:
	int hammingWeight(uint32_t n) {
		return __builtin_popcount(n);
	}
};

// n&(n-1)�������ұߵ�1
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int cnt = 0;
		while (n) {
			n &= n - 1;
			cnt++;
		}
		return cnt;
	}
};

//��32λ���б���
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int cnt = 0;
		for (int i = 0; i < 32; i++) {
			if ((n >> i) & 1)
				cnt++;
		}
		return cnt;
	}
};


