#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int n = cardPoints.size();
		// �������ڴ�СΪ n-k
		int windowSize = n - k;
		// ѡǰ n-k ����Ϊ��ʼֵ
		int sum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
		int minSum = sum;
		for (int i = windowSize; i < n; ++i) {
			// ��������ÿ�����ƶ�һ�����Ӵ��Ҳ���봰�ڵ�Ԫ��ֵ�������ٴ�����뿪���ڵ�Ԫ��ֵ
			sum += cardPoints[i] - cardPoints[i - windowSize];
			minSum = min(minSum, sum);
		}
		return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
	}
};

