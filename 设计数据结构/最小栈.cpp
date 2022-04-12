#include<bits/stdc++.h>
using namespace std;

class MinStack {
	// ˫ջģ��
	stack<int> x_stack;
	stack<int> min_stack;
public:
	MinStack() {
		min_stack.push(INT_MAX);
	}
	// push��pop��ͬ����
	void push(int x) {
		x_stack.push(x);
		min_stack.push(min(min_stack.top(), x));
	}

	void pop() {
		x_stack.pop();
		min_stack.pop();
	}

	int top() {
		return x_stack.top();
	}

	int getMin() {
		return min_stack.top();
	}
};


// ����һ��
// ˼·��˫ջģ����Сջ
// ���Ӷȷ�����
//ʱ�临�Ӷȣ�������Ŀ�е����в�����ʱ�临�ӶȾ�Ϊ O(1)����Ϊջ�Ĳ��롢ɾ�����ȡ�������� O(1)�����Ƕ����ÿ������������ջ�������Ρ�
//�ռ临�Ӷȣ�O(n)������nΪ�ܲ������������£����ǻ��������� n��Ԫ�أ���ʱ����ջռ�õĿռ�ΪO(n)��

class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> st1, stMin;
	MinStack() {
		stMin.push(INT_MAX);
	}
	void push(int val) {
		st1.push(val);
		stMin.push(min(stMin.top(), val));
	}
	void pop() {
		st1.pop();
		stMin.pop();
	}
	int top() {
		return st1.top();
	}
	int getMin() {
		return stMin.top();
	}
};