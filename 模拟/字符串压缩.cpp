#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string compressString(string S) {
		string res;
		// ָ�� i-1 i�ж�ǰ���ϵ
		for (int i = 1; i < S.size(); i++) {
			// ��ʼ���������͵�ǰ��ĸ
			int cnt = 1;
			char tmp = S[i - 1]; // string�ĵ�����char
			while (S[i] == S[i - 1]) {
				cnt++;
				i++;
			}
			// S[i-1]!=S[i]��Ҫ���¼���������ĸ������ѭ���ˣ����Բ����ظ���
			res += tmp;  // char����ֱ����string���
			res += to_string(cnt);
			if (i == S.size() - 1) { res += S[i]; res += "1"; }
		}
		if (res.size() >= S.size() || S.size() == 1) return S;
		return res;
	}
};