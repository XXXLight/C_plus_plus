#include<bits/stdc++.h>
using namespace std;


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

// ��С�������㷨��ʵ�ǳ���
class Solution {
public:
	int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
		UF uf(n + 1);
		int lenW = wells.size(), lenP = pipes.size();
		for (int i = 0; i < lenW; i++) {
			pipes.push_back({ 0,i + 1,wells[i] });
		}
		sort(pipes.begin(), pipes.end(), [](auto& e1, auto& e2) {// �Ӳ�����������ǳ���
			return e1[2] < e2[2];
		});
		int res = 0;
		for (auto& e : pipes) {
			if (!uf.checkAB(e[0], e[1])) {
				uf.unionAB(e[0], e[1]);
				res += e[2];
			}
		}
		return res;
	}
};