#include<bits/stdc++.h>
using namespace std;


class MedianFinder {
	priority_queue<int> left; // 左边是大根堆，说明默认是大根堆
	priority_queue<int, vector<int>, greater<>> right; // 右边是小根堆

	void resize() {
		// (1)l-r=2,l--,r++  ===》 l=r;  (2)l-r=1或l=r不变 ;   (3)r-l=1,r--,l++  ===>l-r=1;  
		// 上述三种情况都确保了l-r=1或者l=r
		if (left.size() >= right.size() + 2) {
			right.push(left.top());
			left.pop();
		}
		else if (right.size() > left.size()) {
			left.push(right.top());
			right.pop();
		}
	}
public:
	/** initialize your data structure here. */
	MedianFinder() {
		left.push(INT_MIN);//  求最大值，所以是大根堆
		right.push(INT_MAX);//  求最小值，所以是小根堆
	}

	void addNum(int num) {
		int lmax = left.top(), rmin = right.top();
		if (num <= lmax)
			left.push(num);
		else
			right.push(num);
		resize();
	}

	double findMedian() {
		if (left.size() == right.size())
			return ((double)left.top() + right.top()) / 2;
		else
			return left.top();
	}
};