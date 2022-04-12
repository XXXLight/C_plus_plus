#include<bits/stdc++.h>
using namespace std;

// �Լ�������������Ĳ�������ķ���
class Solution {
public:
	long long subArrayRanges(vector<int>& nums) {
		int len = nums.size();
		// dp1[i][j]ά��[i,j]��Χ�ڵ����ֵ
		// dp2[i][j]ά��[i,j]��Χ�ڵ���Сֵ
		vector<vector<int>> dp1(len, vector<int>(len, 0));
		vector<vector<int>> dp2(len, vector<int>(len, 0));
		// dp�����ʼ��
		for (int i = 0; i < len; i++) dp1[i][i] = nums[i], dp2[i][i] = nums[i]; // ������д�� , , , ;���Դﵽ���̴����Ŀ��
		long long res = 0;
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				dp1[i][j] = max(dp1[i][j - 1], nums[j]), dp2[i][j] = min(dp2[i][j - 1], nums[j]);
				res += abs(dp1[i][j] - dp2[i][j]);
			}
		}
		return res;
	}
};