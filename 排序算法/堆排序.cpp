//#include<iostream>
//using namespace std;
//
//void maxHeapIfy(int A[], int i, int n)  //��i�ڵ�Ϊ���Ķ���С������������,n��ʾ���е����ݸ���
//{
//	int l = 2 * i + 1;   //i�������
//	int r = 2 * i + 2;  //i���Ҷ���
//	int largest = i;   //�����ø��ڵ���ӽڵ������ڵ������ֵ��λ��Ϊ���ڵ��±�
//	if (l < n && A[l] > A[largest])
//		largest = l;
//	if (r < n && A[r] > A[largest])
//		largest = r;
//	if (largest != i)    //���ֵ���Ǹ��ڵ㣬����
//	{
//		swap(A[i], A[largest]);
//		maxHeapIfy(A, largest, n);  //�ݹ���ã���֤����Ҳ������
//	}
//}
//void buildMaxHeap(int A[], int n)  //��������
//{
//	// �����һ����Ҷ�ӽڵ㣨n/2-1����ʼ�Ե����Ϲ�����
//	for (int i = n / 2 - 1; i >= 0; i--)  //�ӣ�n/2-1������һ��maxHeapIfy�Ϳ��Եõ�����
//		maxHeapIfy(A, i, n);
//}
//void heapSort(int A[], int n)  //�������㷨
//{
//	buildMaxHeap(A, n);  //�Ƚ�����
//	/*for (int i = 0; i < n; i++) cout << A[i] << " ";
//	cout << endl;*/
//	for (int i = n - 1; i > 0; i--)
//	{
//		//// �൱��ÿ�ε������ģ�Ȼ�����
//		// �����ڵ�(���ֵA[0])����������򲿷ֵ����һ��Ԫ�ؽ���,�������յõ����ǵ�������
//		swap(A[0], A[i]);
//		/*for (int i = 0; i < n; i++) cout << A[i] << " ";
//		cout << endl;*/
//		// ���������鳤�ȼ�һ,ֻҪ�Ի������ڵ��Ԫ�ؽ������򣬽����³��ͺ��ˡ�
//		maxHeapIfy(A, 0, i);//i��ʾ����Ԫ�ظ�����i��n-1��ʼ˵��ɾ���˵�n��
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