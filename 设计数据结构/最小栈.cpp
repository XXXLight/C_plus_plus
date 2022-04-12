#include<bits/stdc++.h>
using namespace std;

class MinStack {
	// 双栈模拟
	stack<int> x_stack;
	stack<int> min_stack;
public:
	MinStack() {
		min_stack.push(INT_MAX);
	}
	// push和pop是同步的
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


// 清晰一点
// 思路：双栈模拟最小栈
// 复杂度分析：
//时间复杂度：对于题目中的所有操作，时间复杂度均为 O(1)。因为栈的插入、删除与读取操作都是 O(1)，我们定义的每个操作最多调用栈操作两次。
//空间复杂度：O(n)，其中n为总操作数。最坏情况下，我们会连续插入 n个元素，此时两个栈占用的空间为O(n)。

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