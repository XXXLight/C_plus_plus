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
		if (size[rootA] < size[rootB]) swap(rootA, rootB);
		size[rootA] += size[rootB];
		parent[rootB] = rootA;
		setCount--;
	}

	/* ���ؽڵ� x �ĸ��ڵ� */
	int findSet(int x) {
		while (parent[x] != x) {
			// ����·��ѹ��
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
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
	int dirX[4] = { 0,0,1,-1 }, dirY[4] = { 1,-1,0,0 }; // �ĸ���������
	int largestIsland(vector<vector<int>>& grid) {
		int n = grid.size();
		UF uf(n*n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {// ��ǰλ����1�����ĸ�����ϲ�
					for (int k = 0; k < 4; k++) {// ע�������k����ֹ�ظ�
						int newX = i + dirX[k], newY = j + dirY[k];// �µ�����
						// ���겻Խ��
						if (newX >= 0 && newX < n&&newY >= 0 && newY < n&&grid[newX][newY] == 1) {
							uf.unionAB(i*n + j, newX*n + newY);
						}
					}
				}
			}
		}
		unordered_map<int, vector<int>> mp;// ���ڵ�----�����ڵ��������
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					mp[uf.findSet(i*n + j)].push_back(i*n + j);
				}
			}
		}
		// û��0�Ļ���ֱ�ӷ��ؾ������
		int cnt = 0;
		for (auto&[u, v] : mp) {
			cnt += v.size();
		}
		if (cnt == n * n) return n * n;

		set<int> flag;
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) {
					int sum = 1;
					flag.clear();// ע�����ﲻ����
					for (int k = 0; k < 4; k++) {
						int newX = i + dirX[k], newY = j + dirY[k];
						if (newX >= 0 && newX < n&&newY >= 0 && newY < n&&grid[newX][newY] == 1 && !flag.count(uf.findSet(newX*n + newY))) {
							flag.insert(uf.findSet(newX*n + newY));
							sum += mp[uf.findSet(newX*n + newY)].size();
						}
					}
					res = max(res, sum);
				}
			}
		}
		return res;
	}
};



