#include<bits/stdc++.h>
using namespace std;
const int num = 1e7 + 50;

class UF {
public:
	vector<int> parent;
	vector<int> cnt;	// �¿�һ����������
	int res = 1;
	UF(int n) {
		parent.resize(n);
		cnt.resize(n);
		for (int i = 0; i <= n; i++) { parent[i] = i; cnt[i] = 1; }
	}
	int find(int x) {
		while (x != parent[x]) {
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}
	bool check(int a, int b) {
		int fa = find(a);
		int fb = find(b);
		if (fa != fb) return false;
		return true;
	}
	void unionAB(int a, int b) {
		int fa = find(a);
		int fb = find(b);
		if (fa != fb)
		{	// ����ͼ�������ˣ��ǰ�a�ӵ�b�£�����b�Ǹ��ڵ�
			parent[fa] = fb;
			cnt[fb] += cnt[fa];
			res = max(res, cnt[fb]);
		}
	}
	int getRes() {
		return this->res;
	}
};

int main() {

	int T;
	cin >> T;
	while (T--) {
		int m;
		cin >> m;
		UF* uf = new UF(num);
		while (m--) {
			int a, b;
			cin >> a >> b;
			uf->unionAB(a, b);
		}
		cout << uf->getRes() << endl;
		//ע�⣺û�����������ڴ���������ڴ泬��
		delete uf;
	}
	return 0;
}
