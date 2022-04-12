#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//�ۼ�ģʽ
class Solution {
public:
	int subarraySum(vector<int> &nums, int k) {
		int sum = 0, res = 0;
		unordered_map<int, int> cul;
		cul[0] = 1;
		for (auto &m : nums) {
			sum += m;
			res += cul[sum - k]; //��ֹ��ǰ�ĺ�Ϊsum,�����ϣ������sum-k,˵������ sum-(sum-k)=k������������
			++cul[sum];
		}
		return res;
	}
};

//ǰ����������ģʽ
class Solution {
public:
	int subarraySum(vector<int> &nums, int k) {
		vector<int> sum(nums.size() + 1);//Ҳ���Բ�������ֱ����ԭ���������ϲ���
		sum[0] = 0;
		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum[i + 1] = sum[i] + nums[i];//����ǰ׺��
		}
		unordered_map<int, int> mp;
		for (int i = 0; i < sum.size(); i++) {
			res += mp[sum[i] - k]; //���ﲻ�����жϣ�ֱ�Ӽӣ���Щ����¿��Զ�sum[i]-k�����жϿ��������������
			mp[sum[i]]++;
		}
		return res;;
	}
};
