#include<bits/stdc++.h>
using namespace std;


class MedianFinder {
	priority_queue<int> left; // ����Ǵ���ѣ�˵��Ĭ���Ǵ����
	priority_queue<int, vector<int>, greater<>> right; // �ұ���С����

	void resize() {
		// (1)l-r=2,l--,r++  ===�� l=r;  (2)l-r=1��l=r���� ;   (3)r-l=1,r--,l++  ===>l-r=1;  
		// �������������ȷ����l-r=1����l=r
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
		left.push(INT_MIN);//  �����ֵ�������Ǵ����
		right.push(INT_MAX);//  ����Сֵ��������С����
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