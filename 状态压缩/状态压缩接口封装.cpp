#include<bits/stdc++.h>
using namespace std;

// 位运算从右边开始是第0位

// 将 x 的第 pos 位设置为 1
int setBit(int x, int pos) {
	return x | (1 << pos);// 0/1 和1或 都会变成1
}

// 将 x 的第 pos 位设置为 0
int unsetBit(int x, int pos) {
	return x & ~(1 << pos);//  0/1 和1&都会保持不变； 0/1 和0&都会变成0，所以可以置0
}

// 将 x 的第 pos 位取反
int flapBit(int x, int pos) {
	return x ^ (1 << pos);
}

// 找到最低位的 1
int lowbit(int x) {
	return x & (-x);
}

//消除最后一个 1
int clear(int x) {
	return x & (x - 1);
}

//判断两数是否异号
bool isOppositeSign(int x, int y) {
	return (x^y) < 0;
}

//判断奇偶
bool isEven(int x) {
	return (x & 1) == 0;
}

//交换两数
void swap(int x, int y) {
	x ^= y;
	y ^= x;
	x ^= y;
}

// 判断是否是 2 的指数
bool isTowExponent(int n) {
	return (n&(n - 1)) == 0;
}

// 求相反数
int reverseSign(int n) {
	return (~n) + 1;
}

// 位数逆转
int ror(int x, int n) {
	x = (x >> n) | (x << (32 - n));
	return x;
}
int rol(int x, int n) {
	x = (x << n) | (x >> (32 - n));
	return x;
}

// 大小写转换
// 转换为大写
char toUpper(char c) {
	return c & '_';
}
// 转换为小写
char toLower(char c) {
	return c | ' ';
}
// 大小写相互转换
char exchage(char c) {
	return c ^ 'c';
}


int main() {
	int a = 6;
	int a1 = unsetBit(a, 1);
	//cout << bitset<10>(a) << " " << bitset<10>(a1) << endl;
	return 0;
}