#include<bits/stdc++.h>
using namespace std;
//�����������
//ѧϰ�㣺
//1.int mid = left + (right - left) / 2; // ����ʽ��ͬ�� (left + right) / 2����Ϊ�˱������������ѧϰ��������
//2.���鲢�����е��������ͳһ�������ĸ�if else
//3.���������������Ƚϵ�
//4.û��main�������㱣��


class Solution {
public:
	int reversePairs(vector<int>& nums) { //�������ã��������������������
		int len = nums.size();
		if (len < 2) {
			return 0; // �����������ԣ�ֱ�� return 0
		}
		vector<int> helper(len); //��������
		return reversePairs(nums, 0, len - 1, helper);
	}

private:
	int reversePairs(vector<int>& nums, int left, int right, vector<int>& helper) {
		if (left == right) {
			return 0; // �ݹ���ֹ������ֻʣһ��Ԫ���ˣ��������������ˣ�
		}

		int mid = left + (right - left) / 2; // ����ʽ��ͬ�� (left + right) / 2����Ϊ�˱������������ѧϰ��������

		int leftPairs = reversePairs(nums, left, mid, helper); // ������벿�ֵ������[left,mid]
		int rightPairs = reversePairs(nums, mid + 1, right, helper); // �����Ұ벿�ֵ������[mid+1,right]

		if (nums[mid] <= nums[mid + 1]) {
			// ���ж����ڼ��٣���������Ҷ����ź��򣬶�����ߵ����ֵ <= �ұߵ���Сֵ��
			// ��ô�Ͳ����ڿ�Խ��ߺ��ұߵ��������
			return leftPairs + rightPairs;
		}

		int crossPairs = mergeAndCount(nums, left, mid, right, helper); // �����Խ��ߺ��ұߵ������

		return leftPairs + rightPairs + crossPairs;
	}

	int mergeAndCount(vector<int>& nums, int left, int mid, int right, vector<int>& helper) {
		// ��������ǰ�������ǣ���벿�ֺ��Ұ벿�ֶ����Ѿ��������ź����˵�,��������û��
		// ��Ϊ�������Ǵ����Ҳ��ֶ���ֻ��һ��Ԫ�ص������ʼ���еģ��Ե����ϣ��������ǿ��Ա�֤ǰ��������
		for (int i = left; i <= right; ++i) {
			helper[i] = nums[i]; // ����� helper ��������,������Ϊ����
		}

		int i = left, j = mid + 1; // i �� j �ֱ�����벿�ֺ��Ұ벿�ֵ����
		int count = 0; // count ����ͳ�����������

		for (int k = left; k <= right; ++k) {
			if (i == mid + 1) {
				// ���� i �Ѿ�Խ����ߵı߽磬ֱ������Ұ벿�ֽ� nums
				nums[k] = helper[j];//�����nums,�ұ���helper
				++j;
			}
			else if (j == right + 1) {
				// ���� j �Ѿ�Խ���ұߵı߽磬ֱ�������벿�ֽ� nums
				nums[k] = helper[i];//�����nums,�ұ���helper
				++i;
			}
			else if (helper[i] <= helper[j]) { // ע�⽡׳�Ĺ鲢��������Ҫ�� <=,�������˵��ںţ��Ƚ��õ���helper����
			 // �������С�ڵ����ұߣ��ǾͲ�������ԣ������޸� count
				nums[k] = helper[i];//�����nums,�ұ���helper
				++i;
			}
			else {
				// ������ߴ����ұߣ�������ԣ�count += ��ǰ��� [i, mid] ������Ԫ��
				// ��Ϊ��������� [7,8]���ұ���[5,6]��Ȼ�� i ָ�� 7��j ָ�� 5
				// ��ô 5 �� 7��8 ������������ԣ�Ҳ���Ǵ�ʱ�������µ������
				// ���Կ����ܽ�����ɣ�count += mid - i + 1
				nums[k] = helper[j];
				count += mid - i + 1;
				++j;
			}
		}

		return count;
	}
};

