// ��������ָ��i��j������
#include<bits/stdc++.h>
using namespace std;



// ��״����
// C[1] = A[0];
// C[2] = A[0] + A[1];
// C[3] = A[2];
// C[4] = A[0] + A[1] + A[2] + A[3];
// C[5] = A[4];
// C[6] = A[4] + A[5];
// C[7] = A[6];
// C[8] = A[0] + A[1] + A[2] + A[3] + A[4] + A[5] + A[6] + A[7];
class BIT {
private:
	vector<int> tree;// ��״����Ĵ�С��ԭʼ�����1
	int n;

public:
	// ���������Ϊn�����飬����n+1���ȵ���״����treeά�������޸ĺ������ѯ
	BIT(int _n) : n(_n), tree(_n + 1) {}
	// ȡ��λ��������1010110��ȡ������10
	static constexpr int lowbit(int x) {
		return x & (-x);
	}
	// ����ԭʼ������A[0]��A[1]....A[n-1], update(x,d)��ʾA[x-1]+=d
	void update(int x, int d) {
		while (x <= n) {
			tree[x] += d;
			x += lowbit(x);
		}
	}
	// ��ѯǰ׺��A[0]+A[1]+....+A[x-1]
	int query(int x) const {
		int ans = 0;
		while (x) {
			ans += tree[x];
			x -= lowbit(x);
		}
		return ans;
	}
};