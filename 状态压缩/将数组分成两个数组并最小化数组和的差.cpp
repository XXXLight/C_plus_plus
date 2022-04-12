#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minimumDifference(vector<int>& nums) {
		int n = nums.size() / 2;
		/*
		���ȣ�Ԥ����ǰn��Ԫ�أ���2��n�η���״̬����ÿ��Ԫ��ѡ��ѡ�����ö�����λ��1����ѡ��0����ѡ��
		���仰˵����1����Ԫ�ع����һ�����飬��0�������ڶ������顣
		������sum_pre��ʾǰn��������Ϊ��һ������ģ��͹�Ϊ�ڶ��������Ԫ��֮�
		*/
		vector<int>pre[16];  //pre[i]��ʾѡȡi��Ԫ��ʱ���͵ļ���
		for (int i = 0; i < (1 << n); i++) {
			int sum_pre = 0, bit = 0;
			for (int j = 0; j < n; j++) {
				if ((i >> j) & 1) {
					sum_pre += nums[j];
					bit++;
				}
				else {
					sum_pre -= nums[j];
				}
			}
			pre[bit].push_back(sum_pre);
		}
		//����Ϊ�˺�����ֲ��ҡ�˳��ȥ�أ�Ҳ���Բ�ȥ��
		for (int i = 0; i <= n; i++) {
			sort(pre[i].begin(), pre[i].end());
			pre[i].erase(unique(pre[i].begin(), pre[i].end()), pre[i].end());
		}

		/*
		���Ǻ�n����������n����ѡ��bit�������һ�����飬��ôֻ���ǰn��������n-bit�������һ�����顣
		ѡ���ķ�ʽ��������ͬ��ö��2��n�η���״̬��
		����ÿ��״̬�����ö��ֲ��Ҵ����������pre[n-bit]���ҵ�һ����k��ʹ��k���ϵ�ǰ��sum_later�����ӽ�0
		��¼����С�Ĳ�ֵ���ɡ�
		*/
		int ans = 1e9 + 7;
		for (int i = 0; i < (1 << n); i++) {
			int sum_later = 0, bit = 0;
			for (int j = 0; j < n; j++) {
				if ((i >> j) & 1) {
					sum_later += nums[j + n];
					bit++;
				}
				else {
					sum_later -= nums[j + n];
				}
			}
			auto it = lower_bound(pre[n - bit].begin(), pre[n - bit].end(), -sum_later);
			if (it != pre[n - bit].end())
				ans = min(ans, sum_later + *it);
		}
		return ans;
	}
};

