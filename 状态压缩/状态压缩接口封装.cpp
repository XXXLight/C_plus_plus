#include<bits/stdc++.h>
using namespace std;

// λ������ұ߿�ʼ�ǵ�0λ

// �� x �ĵ� pos λ����Ϊ 1
int setBit(int x, int pos) {
	return x | (1 << pos);// 0/1 ��1�� ������1
}

// �� x �ĵ� pos λ����Ϊ 0
int unsetBit(int x, int pos) {
	return x & ~(1 << pos);//  0/1 ��1&���ᱣ�ֲ��䣻 0/1 ��0&������0�����Կ�����0
}

// �� x �ĵ� pos λȡ��
int flapBit(int x, int pos) {
	return x ^ (1 << pos);
}

// �ҵ����λ�� 1
int lowbit(int x) {
	return x & (-x);
}

//�������һ�� 1
int clear(int x) {
	return x & (x - 1);
}

//�ж������Ƿ����
bool isOppositeSign(int x, int y) {
	return (x^y) < 0;
}

//�ж���ż
bool isEven(int x) {
	return (x & 1) == 0;
}

//��������
void swap(int x, int y) {
	x ^= y;
	y ^= x;
	x ^= y;
}

// �ж��Ƿ��� 2 ��ָ��
bool isTowExponent(int n) {
	return (n&(n - 1)) == 0;
}

// ���෴��
int reverseSign(int n) {
	return (~n) + 1;
}

// λ����ת
int ror(int x, int n) {
	x = (x >> n) | (x << (32 - n));
	return x;
}
int rol(int x, int n) {
	x = (x << n) | (x >> (32 - n));
	return x;
}

// ��Сдת��
// ת��Ϊ��д
char toUpper(char c) {
	return c & '_';
}
// ת��ΪСд
char toLower(char c) {
	return c | ' ';
}
// ��Сд�໥ת��
char exchage(char c) {
	return c ^ 'c';
}


int main() {
	int a = 6;
	int a1 = unsetBit(a, 1);
	//cout << bitset<10>(a) << " " << bitset<10>(a1) << endl;
	return 0;
}