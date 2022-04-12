#include<bits/stdc++.h>
using namespace std;

//快速排序（从小到大）
void quickSort(vector<int>& arr, int left, int right)
{
	if (left >= right)	return;  // 这里必须是>=不能是==
	int i = left, j = right, base = arr[left];  //取最左边的数为基准数

	// 下面是定位索引的过程
	while (i < j)
	{
		while (arr[j] >= base && i < j)j--; // 都是有等于号的
		while (arr[i] <= base && i < j)i++; // 都是有等于号的
		if (i < j) swap(arr[i], arr[j]);
	}
	//基准数归位
	swap(arr[left], arr[i]);
	quickSort(arr, left, i - 1);//递归左边
	quickSort(arr, i + 1, right);//递归右边
}

int main() {
	vector<int>a = { 5,1,2,4,3,8,7,6 };
	quickSort(a, 0, 7);
	for (int i = 0; i < 8; ++i)
		cout << a[i] << " ";
}

////快速排序（从大到小）
//void quickSort(int left, int right, vector<int>& arr)
//{
//	if (left >= right) //递归边界条件
//		return;
//	if (left < 0 || right >= arr.size())
//	{
//		cout << "error args! array bound." << endl;
//		return;
//	}//非法输入判断,防止数组越界
//	int i, j, base, temp;
//	i = left, j = right;
//	base = arr[left];  //取最左边的数为基准数
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
//	//基准数归位
//	arr[left] = arr[i];
//	arr[i] = base;
//	quickSort(left, i - 1, arr);//递归左边
//	quickSort(i + 1, right, arr);//递归右边
//}

