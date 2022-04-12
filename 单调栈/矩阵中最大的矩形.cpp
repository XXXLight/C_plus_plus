#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int maximalRectangle(vector<string>& matrix) {
		if (matrix.size() == 0) {
			return 0;
		}
		vector<int> heights(matrix[0].size(), 0);
		int maxArea = 0;
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				if (matrix[i][j] == '0') {
					heights[j] = 0;
				}
				else {
					heights[j] += matrix[i][j] - '0';
				}
			}
			maxArea = max(maxArea, largestRectangleArea(heights));
		}
		return maxArea;
	}

	int largestRectangleArea(vector<int>& heights) {
		stack<int> sta;
		sta.push(-1);
		int maxArea = 0;
		for (int i = 0; i < heights.size(); ++i) {
			while (sta.top() != -1 && heights[sta.top()] >= heights[i]) {
				int height = heights[sta.top()];
				sta.pop();
				int width = i - sta.top() - 1;
				maxArea = max(maxArea, height * width);
			}
			sta.push(i);
		}

		while (sta.top() != -1) {
			int height = heights[sta.top()];
			sta.pop();
			int width = heights.size() - sta.top() - 1;
			maxArea = max(maxArea, height * width);
		}
		return maxArea;
	}
};


