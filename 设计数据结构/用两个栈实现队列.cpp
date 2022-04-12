#include<bits/stdc++.h>
using namespace std;


class CQueue {
public:
	stack<int> inStack, outStack;
	// 将inStack栈中的元素弹到outStack
	void in2out() {
		while (!inStack.empty()) {
			outStack.push(inStack.top());
			inStack.pop();
		}
	}
	CQueue() {}

	void appendTail(int value) {
		inStack.push(value);
	}

	int deleteHead() {
		if (empty()) return -1; // 队列为空不能删
		if (outStack.empty()) { //只有out栈为空才移动
			in2out();
		}
		int x = outStack.top();
		outStack.pop();
		return x;
	}
	bool empty() {
		return inStack.empty() && outStack.empty();
	}
};



