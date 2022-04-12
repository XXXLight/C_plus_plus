#include<bits/stdc++.h>
using namespace std;

// 模拟插入排序，和链表模拟插入排序类似
class SortedStack {
public:
	stack<int> st1, st2; //核心数据在栈st1
	SortedStack() {

	}
	void push(int val) {
		while (!st1.empty() && st1.top() < val) {
			st2.push(st1.top());
			st1.pop();
		}
		st1.push(val);
		while (!st2.empty()) {
			st1.push(st2.top());
			st2.pop();
		}
	}

	void pop() {
		if (!st1.empty())
			st1.pop();
	}

	int peek() {
		if (!st1.empty())
			return st1.top();
		return -1;
	}

	bool isEmpty() {
		return st1.empty();
	}
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */