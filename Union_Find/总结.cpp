#include<bits/stdc++.h>
using namespace std;

// ���鼯��ĺܼ򵥣����鼯�����νṹ
// ·��ѹ����https://www.runoob.com/data-structures/union-find-compress.html
// д��1����ȫû��·��ѹ��
	/*int findSet(int x) {
		while (x != parent[x]) {
			x = parent[x];
		}
		return x;
	}*/
	// ·��ѹ������1��
	//int findSet(int x) {
	//	while (parent[x] != x) {
	//		// ����·��ѹ��
	//		parent[x] = parent[parent[x]]; //��x��parent[x]��Ԫ
	//		x = parent[x];
	//	}
	//	return x;
	//}
	// ·��ѹ������2��
	/*int findSet(int x)
	{
		return x == parent[x] ? x : (parent[x] = findSet(parent[x]));
	}*/
class UF {
public:
	vector<int> parent;
	int setCount;// ��ͨ�����ĸ���
	UF(int n) {
		parent.resize(n);
		setCount = n;
		for (int i = 0; i < n; i++) parent[i] = i;
	}
	void unionAB(int a, int b) {
		int fa = findSet(a);
		int fb = findSet(b);
		if (fa != fb) {
			setCount--;// �ϲ��ˣ���ͨ��������������
			parent[fa] = fb;
		}
	}
	
	int findSet(int x)
	{
		if (parent[x] != x) {
			parent[x] = findSet(parent[x]);
		}
		// ��Ϊparent[x]==x,����return parent[x]��x������
		return parent[x];
	}
	
	bool checkAB(int a, int b) {
		int fa = findSet(a);
		int fb = findSet(b);
		if (fa == fb) return true;
		return false;
	}
};


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