#include<bits/stdc++.h>
using namespace std;

// ���䷽�� left+���������%���䳤��


//����һ����Χ�������ͨ�ñ�ʾ��ʽ��
//Ҫȡ��[a, b)�����������ʹ��(rand() % (b - a)) + a;
//Ҫȡ��[a, b]�����������ʹ��(rand() % (b - a + 1)) + a;
//Ҫȡ��(a, b]�����������ʹ��(rand() % (b - a)) + a + 1;
//ͨ�ù�ʽ:a + rand() % n�����е�a����ʼֵ��n�������ķ�Χ��
//Ҫȡ��a��b֮��������������һ�ֱ�ʾ��a + (int)b * rand() / (RAND_MAX + 1)��
//Ҫȡ��0��1֮��ĸ�����������ʹ��rand() / double(RAND_MAX)��


//����ϴ���㷨��ȷ�Ե�׼�򣺲����Ľ�������� n! �ֿ��ܣ�������Ǵ���ġ�

class Solution {
private:
	// �����Լ�д
	vector<int> data;
public:
	Solution(vector<int>& nums) {
		data = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return data;
	}
	// ����[a,b]���������
	int randINT(int a, int b) {
		return rand() % (b - a + 1) + a;
	}
	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> res(data); //��������
		//��һ��
		for (int i = 0; i < res.size(); i++)
		{
			// ���ȡ�±�
			int rand = randINT(i, res.size() - 1);
			// ����λ��
			swap(res[i], res[rand]);
		}
		//������
		/*for (int i = 0; i < res.size() - 1; i++)
		{
			int rand = randINT(i, res.size() - 1);
			swap(res[i], res[rand]);
		}*/
		//������
		//for (int i = res.size() - 1; i >= 0; i--)
		//{
		//	int rand = randINT(0, i);
		//	swap(res[i], res[rand]);
		//}
		//���ģ�
		//for (int i = res.size() - 1; i > 0; i--)
		//{
		//	int rand = randINT(0, i);
		//	swap(res[i], res[rand]);
		//}
		return res;
	}
};


