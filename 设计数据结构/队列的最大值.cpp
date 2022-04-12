#include<bits/stdc++.h>
using namespace std;

class MaxQueue {
public:
	int q[10001];
	int st = 0, end = 0;
	MaxQueue() {

	}

	int max_value() {
		int maxV = -1;
		for (int i = st; i != end; i++) {
			maxV = max(maxV, q[i]);
		}
		return maxV;
	}

	void push_back(int value) {
		q[end++] = value;
	}

	int pop_front() {
		if (st == end) return -1;
		return q[st++];
	}
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */