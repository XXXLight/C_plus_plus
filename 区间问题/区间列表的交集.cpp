#include<bits/stdc++.h>
using namespace std;

// ˫ָ��
// ʱ�临�Ӷȣ�o(M+N)
// �ռ临�Ӷȣ�o(M+N)

// ��Ϊ����������������
class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
		vector<vector<int>> res;
		int i = 0, j = 0;
		// ע��������&&,�˳�������i = firstList.size() || j = secondList.size()������һ���Ѿ������β
		while (i < firstList.size() && j < secondList.size()) {
			int L1 = firstList[i][0], R1 = firstList[i][1];
			int L2 = secondList[j][0], R2 = secondList[j][1];
			// �н������Ž��
			if (L1 <= R2 && L2 <= R1) {
				res.push_back({ max(L1, L2), min(R1, R2) });
			}
			// �����ƶ�ָ��
			if (R2 <= R1) j++;
			else i++;
		}
		return res;
	}
};