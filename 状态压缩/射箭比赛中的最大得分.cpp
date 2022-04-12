#include<bits/stdc++.h>
using namespace std;


// 典型的根据数据量来推断解法的题
class Solution {
public:
	vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
		vector<int> res(aliceArrows.size());
		int mask = (1 << 12), maxScores = 0, resMask = 0;
		for (int i = 0; i < mask; i++) {
			int cntArro = 0, sumScores = 0;
			for (int j = 0; j < 12; j++) {
				if ((1 << j)&i) {
					cntArro += aliceArrows[j] + 1;
					sumScores += j;
					if (cntArro > numArrows) { sumScores = 0; break; };
					maxScores = max(maxScores, sumScores);
				}
			}
			if (sumScores == maxScores) {
				resMask = i;// 得到最大分值时候的状态
			}
		}
		for (int i = 0; i < 12; i++) {
			if ((1 << i)&resMask) { res[i] = aliceArrows[i] + 1; }
		}
		int sum = accumulate(res.begin(), res.end(), 0);
		if (sum < numArrows) {
			res[0] += numArrows - sum;// 剩下的剑全部放在第一个结果元素上
		}
		return res;
	}
};