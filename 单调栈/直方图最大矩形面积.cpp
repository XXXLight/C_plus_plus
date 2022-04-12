#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		stack<int> s;
		vector<int> left(n);//��ߵ�һ��С���������ӵ�λ��
		vector<int> right(n, n);//�ұߵ�һ��С���������ӵ�λ��
		for (int i = 0; i < n; ++i)
		{
			while (!s.empty() && heights[i] < heights[s.top()])
			{
				right[s.top()] = i;
				s.pop();
			}
			left[i] = s.empty() ? -1 : s.top();
			s.push(i);
		}
		int maxs = 0;
		for (int i = 0; i < n; ++i)
		{
			maxs = max(maxs, heights[i] * (right[i] - left[i] - 1));
		}
		return maxs;
	}
};

