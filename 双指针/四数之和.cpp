#include<bits/stdc++.h>
using namespace std;

// ��д�����㷨������˫ָ�룬����o(n^4),˫ָ��o(n^3)
// �����Ĳ�ѭ��
// �㷨�Ż����Ǵӱ����㷨��ʼ
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end()); //����
		vector<vector<int>> res;
		set<vector<int>> st; //����ȥ�ز���
		int len = nums.size();
		for (int i = 0; i < len; i++) { //����Ķ���ĩβlen
			for (int j = i + 1; j < len; j++) {
				int p1 = j + 1;
				int p2 = len - 1;
				while (p1 < p2) {
					int sum = nums[i] + nums[j] + nums[p1] + nums[p2];
					if (sum == target) {
						res.push_back({ nums[i] , nums[j] , nums[p1] , nums[p2] });
						p1++;
						p2--;
					}
					else if (sum < target) {
						p1++;
					}
					else if (sum > target) {
						p2--;
					}
				}
			}
		}
		for (auto e : res) {
			st.insert(e);
		}
		res.clear();
		for (auto e : st) {
			res.push_back(e);
		}
		return res;
	}
};