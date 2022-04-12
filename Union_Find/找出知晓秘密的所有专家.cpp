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
	// ȥ�����Ӳ���
	void disConnect(int x) {
		parent[x] = x;
	}

	int count_num() {
		return this->setCount;
	}
};

class Solution {
public:
	vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
		UF uf(n);
		uf.unionAB(0, firstPerson);
		sort(meetings.begin(), meetings.end(), [](auto &e1, auto &e2) {
			return e1[2] < e2[2];
		});
		int m = meetings.size();
		for (int i = 0; i < m; ++i) {
			//ͬһʱ��Ľ�������
			int j = i + 1;
			while (j < m && meetings[j][2] == meetings[i][2])++j;
			//��ʼ�ϲ�
			for (int k = i; k < j; ++k) {
				uf.unionAB(meetings[k][0], meetings[k][1]);
			}
			//Ȼ���ж��ǲ��Ǹ���֪��ר��һ��ģ�
			for (int k = i; k < j; ++k) {
				if (!uf.checkAB(meetings[k][0], 0)) {
					uf.disConnect(meetings[k][0]);
					uf.disConnect(meetings[k][1]);
				}
			}
			i = j - 1;
		}
		unordered_map<int, vector<int>> mp;
		for (int i = 0; i < n; i++) {
			mp[uf.findSet(i)].push_back(i);
		}
		int r = uf.findSet(0);
		return mp[r];
	}
};