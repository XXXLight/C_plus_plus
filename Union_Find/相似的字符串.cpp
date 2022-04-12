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
	bool similiarAB(string &a, string& b) {
		if (a == b) return true;
		int len = a.size();
		int cnt = 0;
		for (int i = 0; i < len; i++) {
			if (a[i] != b[i]) cnt++;
		}
		if (cnt == 2) return true;
		return false;
	}
	int numSimilarGroups(vector<string>& strs) {
		int len = strs.size();
		UF uf(len);
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (similiarAB(strs[i], strs[j])) {
					uf.unionAB(i, j);
				}
			}
		}
		return uf.setCount;
	}
};