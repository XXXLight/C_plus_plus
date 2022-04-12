#include<bits/stdc++.h>
using namespace std;


class CQueue {
public:
	stack<int> inStack, outStack;
	// ��inStackջ�е�Ԫ�ص���outStack
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
		if (empty()) return -1; // ����Ϊ�ղ���ɾ
		if (outStack.empty()) { //ֻ��outջΪ�ղ��ƶ�
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



