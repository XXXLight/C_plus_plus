#include<bits/stdc++.h>
using namespace std;
//1.ѧϰ��Ŀ�����
//2.ѧϰ����not������

class Solution {
public:
	bool isStraight(vector<int>& nums) {
		set<int> st;
		int maxV = INT_MIN, minV = INT_MAX;//ֱ����ģ��
		for (auto e : nums) {
			if (e == 0) continue;//������������
			//�����ʾ��������0
			if (not st.count(e)) {
				st.insert(e);
			}
			else if (st.count(e)) {
				return false;
			}
			maxV = max(e, maxV);   
			minV = min(e, minV);
		}
		return (maxV - minV < 5) ? true : false;
	}
};

