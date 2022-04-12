#include<bits/stdc++.h>
using namespace std;


class NumArray {
public:
	vector<int> Bit, _nums; // ��״���� Binary Indexed Tree
	int lowbit(int x) {
		return x & -x;
	}
	// ����ԭʼ����_nums��ǰx��֮�ͣ���[0,i-1]��֮��
	int getSum(int x) {
		int ans = 0;
		while (x >= 1) {
			ans += Bit[x];
			x -= lowbit(x);
		}
		return ans;
	}
	// �����޸ģ�����ԭʼ�����index+1��Ϊk
	void add(int k, int v) {
		while (k < Bit.size()) {
			Bit[k] += v;
			k += lowbit(k);
		}
	}
	// �����ӿڵĹ����ڹ��캯������в���
	NumArray(vector<int>& nums) {
		Bit.resize(nums.size() + 1);// ��״������±��1��ʼ
		for (int i = 0; i < nums.size(); i++) {
			// �����޸ģ�ԭʼ��״����nums[i]=0
			add(i + 1, nums[i]);
			_nums.push_back(nums[i]);
		}
		// C[1] = A[1];
		// C[2] = A[1] + A[2];
		// C[3] = A[3];
		// C[4] = A[1] + A[2] + A[3] + A[4];
		// C[5] = A[5];
		// C[6] = A[5] + A[6];
		// C[7] = A[7];
		// C[8] = A[1] + A[2] + A[3] + A[4] + A[5] + A[6] + A[7] + A[8];
				// _nums����ԭʼ����
				// for(auto e:_nums) cout<<e<<" ";
				// cout<<endl;
				// // Bit����״���飬�±��1��ʼ
				// for(auto e:Bit) cout<<e<<" ";
				// cout<<endl;
				// �Ӵ�ӡ���������֤���߼�Ĺ�ϵ

				// update(1,9);
				// for(auto e:_nums) cout<<e<<" ";
	}
	// ԭʼ�����indexλ���޸�Ϊval
	// ԭʼ������A[i],i=[0,n-1],����add������Ҳ����A[index]+=val-_nums[index]
	void update(int index, int val) {
		// �޸�ԭ����indexλ�õȼ����޸���״����index+1λ�õ����ݣ���_nums[index]--->val��������val-nums[index]
		add(index + 1, val - _nums[index]); // �±��1��ʼ
		// �����޸�
		_nums[index] = val;
	}

	int sumRange(int left, int right) {
		return getSum(right + 1) - getSum(left);
		// ����һ��ǰ׺�͵Ĺ�ʽ�ͺܺ������
	}
};