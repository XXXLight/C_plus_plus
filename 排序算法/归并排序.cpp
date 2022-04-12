#include<iostream>
#include<vector>
using namespace std;

// Question1:��ô���ԣ� 
// ����ȷ���鲢�Ĺ���û�д��󣬳����ǵ��Գ����ģ������ǱȶԳ����ģ���Ŀ���Աȶԣ�������Ҫ����
// ��ȷ��[2,6,7,8//1,3,5,9]===>[1,2,3,5,6,7,8,9]�Ĺ����ǶԵ�


// �������Ҷ��Ǳ�����+˫ָ��
void MergeSort(vector<int>&nums, int l, int r) {
	if (l == r)	return;  //�ݹ�����������е�ÿ����������Ϊ����Ϊ1������
	int m = (l + r) >>1;
	// �ȷֶ�����
	MergeSort(nums, l, m);
	MergeSort(nums, m + 1, r);

	// �ٺϲ�
	int n = r - l + 1;//��ʱ�����ϲ������������
	int* tmp = new int[n]; //�ռ临�Ӷ� o(n),������ķ�ʽͦ�� vector<int> tmp(n)
	int i = 0, left = l, right = m + 1;
	while (left <= m && right <= r) //�˳����� left>m��right>r����һ��Խ��
		tmp[i++] = nums[left] <= nums[right] ? nums[left++] : nums[right++];
	// ����û��Խ���
	while (left <= m)
		tmp[i++] = nums[left++];
	while (right <= r)
		tmp[i++] = nums[right++];
	for (int j = 0; j < n; ++j)
		nums[l + j] = tmp[j]; // copy(tmp.begin(),tmp.end(),nums.begin()+l);
	delete[] tmp;//ɾ���������ڴ棬��ֹ�ڴ�й©
}

int main() {
	vector<int>a = { 3,1,2,4,5,8,7,6 }; 
	MergeSort(a, 0, 7); // ��Ϊ�Ǳ�����������[0,7]
	for (int i = 0; i < 8; ++i)
		cout << a[i] << " ";
}