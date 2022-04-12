#include<bits/stdc++.h>
using namespace std;

class UF {
public:
	// ��¼��ͨ��������
	int count;
	// �洢���ɿ���
	int* parent;
	// ��¼���ġ�������
	int* size;

	UF(int n) {
		this->count = n;
		parent = new int[n];
		size = new int[n];
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	/* �� p �� q ��ͨ */
	void union_(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		if (rootP == rootQ)
			return;

		// С���ӵ��������棬��ƽ��
		if (size[rootP] > size[rootQ]) {
			parent[rootQ] = rootP;
			size[rootP] += size[rootQ];
		}
		else {
			parent[rootP] = rootQ;
			size[rootQ] += size[rootP];
		}
		count--;
	}

	/* �ж� p �� q �Ƿ�����ͨ */
	bool connected(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		// ����ͬһ�����ϵĽڵ㣬�໥��ͨ
		return rootP == rootQ;
	}

	/* ���ؽڵ� x �ĸ��ڵ� */
	int find(int x) {
		while (parent[x] != x) {
			// ����·��ѹ��
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}

	int count_num() {
		return this->count;
	}
};
class Solution {
public:
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		string res(s); //��������
		int n = s.size(); //���鼯Ԫ�ظ���
		UF* uf = new UF(n); //���캯��
		for (auto e : pairs) {
			uf->union_(e[0], e[1]);
		}

		// �뵽��ʲô���ݽṹ����Ҫ
		// ���������ڵ�(int) ֵ���ڸ������ϵĽڵ�(vector<int>)
		unordered_map<int, vector<int>> mp;
		for (int i = 0; i < n; i++) {
			mp[uf->find(i)].push_back(i);
		}

		// auto&[u, v] : mpѧϰ
		for (auto&[u, v] : mp) {
			// ȡ��������
			vector<int> index = v;
			string tmp;
			for (auto e : v) {
				tmp += s[e];
			}
			sort(tmp.begin(), tmp.end());
			// �ź���Ż�ȥ�����ü�����
			int cnt = 0;
			for (auto e : index) {
				res[e] = tmp[cnt++];
			}
		}

		return res;
	}
};