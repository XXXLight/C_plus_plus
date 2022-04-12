#include<bits/stdc++.h>
using namespace std;


// ��ʱ��Ҫ���ǻ���һ��ģ��
class UF {
public:
	// ��¼��ͨ��������
	int setCount;
	// �洢���ɿ���
	vector<int> parent;
	// ��¼���ġ�������
	vector<int> size;

	UF(int n) {
		this->setCount = n;
		parent.resize(n);
		size.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	/* �� a �� b ��ͨ */
	void unionAB(int a, int b) {
		int rootA = findSet(a);
		int rootB = findSet(b);
		if (rootA == rootB)
			return;
		// С���ӵ��������棬��ƽ��
		if (size[rootA] < size[rootB]) swap(rootA, rootB);// B�Ǵ������򽻻���ʹ��B��С����A�Ǵ���
		size[rootA] += size[rootB];
		parent[rootB] = rootA;// B��С�����ϲ���A����������
		setCount--;
	}

	int findSet(int x)
	{
		return x == parent[x] ? x : (parent[x] = findSet(parent[x]));
	}

	/* �ж� a �� b �Ƿ�����ͨ */
	bool checkAB(int a, int b) {
		int rootA = findSet(a);
		int rootB = findSet(b);
		// ����ͬһ�����ϵĽڵ㣬�໥��ͨ
		return rootA == rootB;
	}

	int count_num() {
		return this->setCount;
	}
};

class Solution {
public:
	vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
		int n1 = edgeList.size(), n2 = queries.size();
		// �Ա�Ȩ��������
		sort(edgeList.begin(), edgeList.end(), [](auto& e1, auto& e2) {
			return e1[2] < e2[2];
		});
		// queries���һά����һ������
		for (int i = 0; i < n2; i++) {
			queries[i].push_back(i);
		}
		// ��ѯҲͬ�����ձ�Ȩ��������
		sort(queries.begin(), queries.end(), [](auto& e1, auto& e2) {
			return e1[2] < e2[2];
		});
		UF uf(n);
		// �����
		vector<bool> res(n2, 0);
		int k = 0;// ע��k=0д������
		for (int i = 0; i < n2; i++) {
			// ����ÿ����ѯ�㣬��ʱ���������Լ�����������
			int p1 = queries[i][0], p2 = queries[i][1], p3 = queries[i][2], p4 = queries[i][3];
			while (k < n1&&edgeList[k][2] < p3) {
				uf.unionAB(edgeList[k][0], edgeList[k][1]);
				k++;
			}
			int r = uf.checkAB(p1, p2);
			res[p4] = r;
		}
		return res;
	}
};