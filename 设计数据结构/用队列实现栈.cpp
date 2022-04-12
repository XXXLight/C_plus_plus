#include<bits/stdc++.h>
using namespace std;

// 结合动画理解
// 用一个队列就可以实现
class MyStack {
public:
	queue<int> q;

	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	//是在push这里环形处理而不是在pop里
	void push(int x) {
		// 以下两句话不能交换，换了就是n-1了
		int n = q.size();
		q.push(x);
		// 将前面的元素搬到队尾，环形移动(环)
		for (int i = 0; i < n; i++) {
			q.push(q.front());
			q.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int r = q.front();
		q.pop();
		return r;
	}

	/** Get the top element. */
	int top() {
		int r = q.front();
		return r;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
};

