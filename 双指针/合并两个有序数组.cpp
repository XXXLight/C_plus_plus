#include<bits/stdc++.h>
using namespace std;

// ���ǹ鲢����ĺϲ�����
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = 0, j = 0;
		int k = 0;
		vector<int> res = nums1;
		while (i < m&&j < n) {
			if (nums1[i] < nums2[j]) {
				res[k++] = nums1[i++];
			}
			else {
				res[k++] = nums2[j++];
			}
		}
		// ��ʱ����Ϊ i>=m ���� j>=n ��ֻ��һ��Խ��
		while (i < m) res[k++] = nums1[i++];
		while (j < n) res[k++] = nums2[j++];
		// ��ʱ����Ϊ i>=m && j>=n ���������ߵ�����β��
		nums1 = res;
	}
};