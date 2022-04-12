#include<bits/stdc++.h>
using namespace std;

// ��϶������
// ��һ�����оͿ���ʵ��
class MyStack {
public:
	queue<int> q;

	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	//����push���ﻷ�δ����������pop��
	void push(int x) {
		// �������仰���ܽ��������˾���n-1��
		int n = q.size();
		q.push(x);
		// ��ǰ���Ԫ�ذᵽ��β�������ƶ�(��)
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

