#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minOperations(vector<int>& a, vector<int>& b) {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		// ����Ҫɵɵ����sum
		int sa = accumulate(a.begin(), a.end(), 0);
		int sb = accumulate(b.begin(), b.end(), 0);
		// swap����ֱ����������vector
		if (sa > sb) swap(sa, sb), swap(a, b);
		int i = 0, j = b.size() - 1;
		int cnt = 0;
		// ѭ���˳�����ʱsa>=sb���Ѿ�������Խ�磬�϶��ܹ�ʹ�������
		while (i < a.size() && 0 <= j && sa < sb) {
			if (6 - a[i] > b[j] - 1) { // ѡ��仯��ֵ����һ��
				sa += 6 - a[i++]; //��a��ѡ
			}
			else sb -= b[j--] - 1; //��b��ѡ
			++cnt;
		}
		while (i < a.size() && sa < sb) {
			sa += 6 - a[i++];
			++cnt;
		}
		while (0 <= j && sa < sb) {
			sb -= b[j--] - 1;
			++cnt;
		}
		return sa >= sb ? cnt : -1;
	}
};

