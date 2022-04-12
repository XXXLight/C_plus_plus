#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int reinitializePermutation(int n) {
		vector<int> v;
		for (int i = 0; i < n; i++) v.push_back(i);
		// vCur��ʼ��Ϊv
		vector<int> vCur(v), vNext(n);
		int cnt = 0;
		while (vNext != v) {
			// vCur����vNext
			for (int i = 0; i < n; i++) {
				if (i % 2 != 0) vNext[i] = vCur[n / 2 + (i - 1) / 2];
				else if (i % 2 == 0) vNext[i] = vCur[i / 2];
			}
			// vNext��ֵ��vCur
			vCur = vNext;
			cnt++;
		}
		return cnt;
	}
};