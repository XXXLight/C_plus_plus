#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int P = 131, N = 100010;// 131,1331,13331
ULL h[N], p[N];
// unsign long long ���Զ�ȡģ!!!!!!!���ull���͵���������ˣ����൱��ȡģ2^64-1�ˡ���Ϊull�ķ�Χ��[0,2^64-1]��
ULL get(int l, int r) {
	if (l == 0) return h[r];// �ر�l=0ʱ����h[r]�����Ǳ߽����
	return h[r] - h[l - 1] * p[r - l + 1];// ��ʽ
}
void Init(string s) {
	int n = s.size();
	p[0] = 1;
	h[0] = s[0] - 'a' + 1;
	for (int i = 1; i < n; i++) {
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + s[i] - 'a' + 1;
	}
}
