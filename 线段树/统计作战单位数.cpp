#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


#define N 1005
// ��״������
class NumArray {
public:
	int n;
	int tree[N + 1];
	int lowbit(int x) {
		return (x) & (-x);
	}
	NumArray(int len) {
		n = len;
		memset(tree, 0, 4 * n + 1);
	}

	void update(int index) {
		int i = index + 1;
		while (i <= n) {
			tree[i] ++;
			i += lowbit(i);
		}
		return;
	}
	int query(int p) {
		// ��ѯ �±� {0,1,...,p-1} ��ǰ׺��
		int res = 0;
		while (p > 0) {
			res += tree[p];
			p -= lowbit(p);
		}
		return res;
	}
};
class Solution {
public:
	unordered_map<int, int> mp;// �������� mp[i] = j ��ʾ i ����ԭ�����е� j С��
	int numTeams(vector<int>& rating) {
		int n = rating.size();
		NumArray* u = new NumArray(n + 1);
		vector<int> h(n, 0);
		for (int i = 1; i < n; i++) h[i] = i;
		sort(h.begin(), h.end(), [&](int& a, int& b) {
			return rating[a] < rating[b];
		});// ����
		for (int i = 0; i < n; i++) mp[rating[h[i]]] = i + 1;// ��������
		int res = 0;
		for (int i = 0; i < n; i++) {
			// �ڵ�ǰ��ǰ������� i �� �ڵ�ǰ����������� n - i - 1 ��
			// ��������ǰ�����С������ a �� ������������� b = i - a ��
			int index = mp[rating[i]];
			int a = u->query(index);// ǰ�����С�ĸ���
			int b = i - a;// ǰ�������ĸ���
			int c = index - 1 - a;// �������С�ĸ���
			int d = n - 1 - a - b - c;// ���������ĸ���
			res += a * d + b * c;// ����Ҫ����´�
			u->update(index);
		}
		return res;
	}
};

