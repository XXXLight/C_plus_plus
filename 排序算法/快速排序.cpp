#include<bits/stdc++.h>
using namespace std;

//�������򣨴�С����
void quickSort(vector<int>& arr, int left, int right)
{
	if (left >= right)	return;  // ���������>=������==
	int i = left, j = right, base = arr[left];  //ȡ����ߵ���Ϊ��׼��

	// �����Ƕ�λ�����Ĺ���
	while (i < j)
	{
		while (arr[j] >= base && i < j)j--; // �����е��ںŵ�
		while (arr[i] <= base && i < j)i++; // �����е��ںŵ�
		if (i < j) swap(arr[i], arr[j]);
	}
	//��׼����λ
	swap(arr[left], arr[i]);
	quickSort(arr, left, i - 1);//�ݹ����
	quickSort(arr, i + 1, right);//�ݹ��ұ�
}

int main() {
	vector<int>a = { 5,1,2,4,3,8,7,6 };
	quickSort(a, 0, 7);
	for (int i = 0; i < 8; ++i)
		cout << a[i] << " ";
}

////�������򣨴Ӵ�С��
//void quickSort(int left, int right, vector<int>& arr)
//{
//	if (left >= right) //�ݹ�߽�����
//		return;
//	if (left < 0 || right >= arr.size())
//	{
//		cout << "error args! array bound." << endl;
//		return;
//	}//�Ƿ������ж�,��ֹ����Խ��
//	int i, j, base, temp;
//	i = left, j = right;
//	base = arr[left];  //ȡ����ߵ���Ϊ��׼��
//	while (i < j)
//	{
//		while (arr[j] <= base && i < j)
//			j--;
//		while (arr[i] >= base && i < j)
//			i++;
//		if (i < j)
//		{
//			temp = arr[i];
//			arr[i] = arr[j];
//			arr[j] = temp;
//		}
//	}
//	//��׼����λ
//	arr[left] = arr[i];
//	arr[i] = base;
//	quickSort(left, i - 1, arr);//�ݹ����
//	quickSort(i + 1, right, arr);//�ݹ��ұ�
//}

