#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	//����itervals����������� �յ㽵������
	//Ϊÿ����������һ��todos���� ����洢���Ǳ����仹��Ҫ�ҵ� �����ڽ�����Ԫ�صĸ��� 
	//��Ϊ��������������2 ���Գ�ʼʱ��Ϊ2
	//�Ӻ���ǰ���� ���todo[i]>0 ��ȡ����������ǰtodo[i]�� ����ʹ����̰��
	//̰�ĵ�˼����ÿ����һ������ ȡ�ĸ���Ϊ�����������Ҫȡ�ĸ�������Сֵ ȡ��ֵΪ����������Сֵ
	//ÿ��ȡ��ֵΪval��ͬʱ����res res++
	//�ٴӴ�λ�� �����±�i֮ǰ��todos
	//����j��λ�õ��Ҷ˵�С�ڵ���val ��todos[j]--
	static bool cmp(vector<int>& a, vector<int>& b)
	{
		return a[0] == b[0] ? a[1] > b[1]:a[0] < b[0];
	}
	int intersectionSizeTwo(vector<vector<int>>& intervals) {
		//������������� �����յ㽵��
		sort(intervals.begin(), intervals.end(), cmp);
		int size = intervals.size();
		//ÿ�����仹��Ҫ�ҵ��Ľ���ĸ���
		vector<int> todos(size, 2);
		int i = size, res = 0;
		while (--i >= 0)
		{
			//����i�����仹��Ҫ�ҵ�todos[i]������ �ӵ�i����������ȡǰtodos[i]��ֵ ��Ϊval
			for (int val = intervals[i][0]; val < intervals[i][0] + todos[i]; val++)
				//ʵ��������val���ɵ�ֵ���Ǽ���S
				//����i֮ǰ��todos
				for (int j = i - 1; j >= 0; j--)
					//�����j��todos[j]��Ϊ0 �ҵ�j��������յ���ڵ���val
					if (todos[j] && val <= intervals[j][1])
						todos[j]--;
			res += todos[i];//������ϵ�i������ �ӵ�������ֵ�ĸ���
			//todos[i]=0;//���Ϊ�������Ը��� ʵ���ϲ�����Ҳ�Խ����Ӱ��
		}
		return res;
	}
};