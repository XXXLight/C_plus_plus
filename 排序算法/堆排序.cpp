//#include<iostream>
//using namespace std;
//
//void maxHeapIfy(int A[], int i, int n)  //将i节点为根的堆中小的数依次上移,n表示堆中的数据个数
//{
//	int l = 2 * i + 1;   //i的左儿子
//	int r = 2 * i + 2;  //i的右儿子
//	int largest = i;   //先设置父节点和子节点三个节点中最大值的位置为父节点下标
//	if (l < n && A[l] > A[largest])
//		largest = l;
//	if (r < n && A[r] > A[largest])
//		largest = r;
//	if (largest != i)    //最大值不是父节点，交换
//	{
//		swap(A[i], A[largest]);
//		maxHeapIfy(A, largest, n);  //递归调用，保证子树也是最大堆
//	}
//}
//void buildMaxHeap(int A[], int n)  //建立最大堆
//{
//	// 从最后一个非叶子节点（n/2-1）开始自底向上构建，
//	for (int i = n / 2 - 1; i >= 0; i--)  //从（n/2-1）调用一次maxHeapIfy就可以得到最大堆
//		maxHeapIfy(A, i, n);
//}
//void heapSort(int A[], int n)  //堆排序算法
//{
//	buildMaxHeap(A, n);  //先建立堆
//	/*for (int i = 0; i < n; i++) cout << A[i] << " ";
//	cout << endl;*/
//	for (int i = n - 1; i > 0; i--)
//	{
//		//// 相当于每次弹出最大的，然后调整
//		// 将根节点(最大值A[0])与数组待排序部分的最后一个元素交换,这样最终得到的是递增序列
//		swap(A[0], A[i]);
//		/*for (int i = 0; i < n; i++) cout << A[i] << " ";
//		cout << endl;*/
//		// 待排序数组长度减一,只要对换到根节点的元素进行排序，将它下沉就好了。
//		maxHeapIfy(A, 0, i);//i表示堆中元素个数，i从n-1开始说明删除了第n个
//		/*for (int i = 0; i < n; i++) cout << A[i] << " ";
//		cout << endl;*/
//	}
//}
//
//int main() {
//	int A[] = { 5,9,8,-1,2,3,7,4 };
//	int len = sizeof(A) / 4;
//	heapSort(A, len);
//	for (int i = 0; i < len; i++) {
//		cout << A[i] << " ";
//	}
//	return 0;
//}