#pragma once
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*****************************************************************
位运算常用技巧
*****************************************************************/
//（1）if(a&1) 表示a是奇数进行何种操作 if(!(a&1))表示偶数下进行的操作
//（2）a<<1 a乘以2，反之则除以2，左乘右除
//（3）异或性质：(1)a^a=0  (2)a^0=a  (3)a^b=b^a
//n&(n−1) 解析： 二进制数字 n 最右边的 1 变成 0 ，其余不变。



//只出现一次的数字，其余元素出现两次	性质：(1)a^a=0  (2)a^0=a  (3)a^b=b^a
int singleNumber(vector<int>& nums) {
	int ret = 0;//主要利用了前两个性质，相同的抵消，与0不变
	for (auto e : nums) ret ^= e;
	return ret;
}


//二进制中1的个数
//n&(n−1) 解析： 二进制数字 n 最右边的 1 变成 0 ，其余不变。
int hammingWeight_0(uint32_t n) {
	bitset<32> b(n);//利用库函数
	return b.count();
}
int hammingWeight_1(uint32_t n) {
	int res = 0;
	while (n) {
		n &= n - 1;//消除最右边的1
		res++;
	}
	return res;
}
int hammingWeight_2(uint32_t n) {
	int cnt = 0;
	for (int i = 0; i < 32; i++) {//32位法
		if ((n >> i) & 1)
			cnt++;
	}
	return cnt;
}


//2的幂
bool isPowerOfTwo(int n) {
	return (n > 0) && ((n&(n - 1)) == 0);
}

//子集
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res;
	int len = 2 << (nums.size() - 1);
	vector<int> r;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < nums.size(); j++) {
			if ((i >> j) & 1) //判断i的第j位是0还是1
				r.push_back(nums[j]);
		}
		res.push_back(r);
		r.clear();
	}
	return res;
}

//颠倒二进制位	(n >> i) & 1 :判断n的（右边是第0位）第i位是0还是1
uint32_t reverseBits(uint32_t n) {
	uint32_t res = 0;
	for (int i = 0; i < 32; i++) {
		int bit_1 = (n >> i) & 1;
		int bit_2 = bit_1 << (31 - i);
		res += bit_2;
	}
	return res;
}

//字母大小写全排列
vector<string> letterCasePermutation(string S) {
	int cnt = 0;
	for (auto s : S) {
		if (isalpha(s))
			cnt++;
	}
	vector<string> res;
	for (int i = 0; i < 1 << cnt; i++) {
		string s0;
		int b = 0;
		for (auto s : S) {
			if (isalpha(s)) {
				if ((1 << b)&i) s0 += tolower(s);
				else s0 += toupper(s);
				b++;
			}
			else s0 += s;
		}
		res.push_back(s0);
	}
	return res;
}