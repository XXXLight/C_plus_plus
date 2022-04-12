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

class Solution {
public:
	bool containsCycle(vector<vector<char>>& grid) {
		int row = grid.size();
		int col = grid[0].size();
		UF uf(row*col);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				// ���½���uf
				if (i + 1 < row&&grid[i][j] == grid[i + 1][j]) {
					if (!uf.checkAB(i*col + j, (i + 1)*col + j)) {
						uf.unionAB(i*col + j, (i + 1)*col + j);
					}
					else {
						return true;
					}
				}
				// ���ҽ���uf
				if (j + 1 < col&&grid[i][j] == grid[i][j + 1]) {
					if (!uf.checkAB(i*col + j, i*col + j + 1)) {
						uf.unionAB(i*col + j, i*col + j + 1);
					}
					else {
						return true;
					}
				}
			}
		}
		return false;
	}
};