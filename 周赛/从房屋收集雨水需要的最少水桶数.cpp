#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumBuckets(string street) {
		int n = street.size();
		if (street == "H") return -1;// ""��ʾ�ַ���string��''��ʾchar
		// startWith��endWith��д����ֱ�ӱ���ö��ÿ���ַ�
		if (street[0] == 'H'&&street[1] == 'H' || street[n - 1] == 'H'&&street[n - 2] == 'H') {
			return -1;
		}
		for (int i = 1; i + 1 < n; ++i) {
			if (street[i] == 'H'&&street[i - 1] == 'H' && street[i + 1] == 'H')  return -1;
		}
		// ����ȷ���˼��㣺
		// 1.û��������HHH��������HH��ͷ���߽�β
		// 2.������HH����һ����.HH.
		// 3.������Ϊ����ȷ���ļ���Ҫ�㱣֤�����������������ȷ��
		int ret = 0;
		for (int i = 0; i < n; ++i) {
			if (street[i] == 'H') {
				ret++;
				// H.H�ͽṹ���������H
				if (street[i + 1] == '.' && street[i + 2] == 'H') {
					i += 2;
				}
			}
		}
		return ret;
	}
};