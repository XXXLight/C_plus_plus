#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	int maxValueOfCoins(vector<vector<int>> &piles, int k) {
		vector<int> f(k + 1);
		int sumN = 0;
		for (auto &pile : piles) {
			int n = pile.size();
			for (int i = 1; i < n; ++i)
				pile[i] += pile[i - 1]; // pile ǰ׺��
			sumN = min(sumN + n, k); // �Ż���j ��ǰ i ��ջ�Ĵ�С֮�Ϳ�ʼö�٣������� k��
			for (int j = sumN; j; --j)
				for (int w = 0; w < min(n, j); ++w)
					f[j] = max(f[j], f[j - w - 1] + pile[w]); // w �� 0 ��ʼ����Ʒ���Ϊ w+1
		}
		return f[k];
	}
};

