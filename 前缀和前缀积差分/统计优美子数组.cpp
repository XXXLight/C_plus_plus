#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		vector<int> sum(nums.size() + 1); //sum����ͳ�ƽ�ֹ��ǰλ���������ֵ��ۼƸ�������ʵ��������һ��ǰ׺��
		sum[0] = 0;
		int cnt = 0;//������
		int res = 0;//���
		unordered_map<int, int> mp;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] & 1) cnt++;//���������������һ
			sum[i + 1] = cnt;
		}
		//�ԡ�ǰ׺�����顱���б���
		for (int i = 0; i < sum.size(); i++) {
			mp[sum[i]]++;
			if (sum[i] >= k) {//���Բ����ж�ֱ���ң���������Ч�ʻ����
				res += mp[sum[i] - k];
			}
		}
		return res;
	}
};