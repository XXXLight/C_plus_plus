#include<bits/stdc++.h>
using namespace std;


const int64_t MOD = 1e9 + 7;
struct Node {
	int64_t a, b;    //f(x)=ax+b
	Node(int _a = 1, int _b = 0) :a(_a), b(_b) {}
	void operator += (const Node &t) {
		a = a * t.a%MOD;
		b = (b*t.a + t.b) % MOD;
	}
};
Node A[200000];
class Fancy {
public:
	vector<int64_t> nums;
	Fancy() {
		for (int i = 0; i < 200000; i++)
			A[i].a = 1, A[i].b = 0;
	}
	void append(int val) {
		nums.push_back(val);
	}
	void addAll(int inc) {
		if (nums.empty())
			return;
		Node op(1, inc);
		for (int i = 100000 - nums.size(); i < 200000; i += i & -i)
			A[i] += op;
	}
	void multAll(int m) {
		if (nums.empty())
			return;
		Node op(m, 0);
		for (int i = 100000 - nums.size(); i < 200000; i += i & -i)
			A[i] += op;
	}
	int getIndex(int idx) {
		if (idx >= nums.size())
			return -1;
		Node op;
		for (int i = 100000 - (idx + 1); i >= 1; i -= i & -i)
			op += A[i];
		return (op.a*nums[idx] + op.b) % MOD;
	}
};
