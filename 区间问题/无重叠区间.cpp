#include<bits/stdc++.h>
using namespace std;


// ��¼��1.��ķ����ʽд����[](a,b){return ;}
// 2.�е����������������
class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.size() == 0) return 0;
		int cnt = 1;
		// ���bool cmp
		// ��l����r��������
		sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
			if (a[0] != b[0]) return a[0] < b[0];
			return a[1] > b[1];
		});
		// ά��ǰһ������[L,R]
		int L = intervals[0][0], R = intervals[0][1];
		for (int i = 1; i < intervals.size(); i++) {
			//��ǰ��������һ��������жԱ�
			int curL = intervals[i][0], curR = intervals[i][1];
			// ��Ϊ�ǰ���˵�����ģ����Ե�ǰ��������һ������һ�������ֹ�ϵ
			// 1.���� 2.�ཻ 3.Զ��
			// 1.����
			if (curR <= R) {
				L = curL;
				R = curR;
			}
			// 3.Զ��
			else if (curL >= R) {
				L = curL;
				R = curR;
				cnt++;
			}
			// 2.�ཻ ��[L,R]���ô���
		}
		return intervals.size() - cnt;
	}
};