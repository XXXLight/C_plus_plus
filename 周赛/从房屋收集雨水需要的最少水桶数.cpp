#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumBuckets(string street) {
		int n = street.size();
		if (street == "H") return -1;// ""表示字符串string；''表示char
		// startWith和endWith的写法，直接暴力枚举每个字符
		if (street[0] == 'H'&&street[1] == 'H' || street[n - 1] == 'H'&&street[n - 2] == 'H') {
			return -1;
		}
		for (int i = 1; i + 1 < n; ++i) {
			if (street[i] == 'H'&&street[i - 1] == 'H' && street[i + 1] == 'H')  return -1;
		}
		// 以上确保了几点：
		// 1.没有连续的HHH，不会以HH开头或者结尾
		// 2.有两个HH，则一定是.HH.
		// 3.正是因为上面确保的几个要点保证了下面遍历方法的正确性
		int ret = 0;
		for (int i = 0; i < n; ++i) {
			if (street[i] == 'H') {
				ret++;
				// H.H型结构跳过后面的H
				if (street[i + 1] == '.' && street[i + 2] == 'H') {
					i += 2;
				}
			}
		}
		return ret;
	}
};