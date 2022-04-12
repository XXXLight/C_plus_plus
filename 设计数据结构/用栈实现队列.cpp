#include<bits/stdc++.h>
using namespace std;

class MyQueue {
private:
	stack<int> inStack, outStack;
	// inStack ---¡· outStack
	void in2out() {
		while (!inStack.empty()) {
			outStack.push(inStack.top());
			inStack.pop();
		}
	}

public:
	MyQueue() {}

	void push(int x) {
		inStack.push(x);
	}

	int pop() {
		// ÒªÏÈ¼ì²é
		if (outStack.empty()) {
			in2out();
		}
		int x = outStack.top();
		outStack.pop();
		return x;
	}

	int peek() {
		if (outStack.empty()) {
			in2out();
		}
		return outStack.top();
	}

	bool empty() {
		return inStack.empty() && outStack.empty();
	}
};
