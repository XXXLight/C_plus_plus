#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long int str2int(string s, int l, int r) {
		// �ַ��� ת ����
		long long int res = 0;
		for (int i = l; i < r; i++) {
			res *= 10;
			res += s[i] - '0';
			if (res > 184467440737095516) // ��ֹԽ��, ���дһ���ͺ���
				return -10;
		}
		return res;
	}
	bool splitString(string s) {
		if (s.size() <= 1) return false;
		long long int arr[21][21];
		memset(arr, 0, sizeof(arr));

		// �������� arr
		for (int i = 0; i < s.size(); i++) {
			for (int j = i + 1; j <= s.size(); j++) {
				arr[i][j] = str2int(s, i, j);
			}
		}

		// �������м���ʼ��
		queue<int> q;
		queue<long long int> num;
		for (int i = 1; i < s.size(); i++) {
			q.push(i);
			num.push(arr[0][i]);
		}
		while (q.size() > 0) {
			// ÿ�δӶ���ͷ��ȡֵ
			long long int idx = q.front();
			long long int last_num = num.front();
			q.pop();
			num.pop();

			// Ѱ������������ ��һ�� �±� �� ��ֵ
			for (int i = 1; idx + i <= s.size(); i++) {
				if (arr[idx][idx + i] == last_num - 1) { // ����ҵ���
					if (idx + i == s.size()) return true; // �ж��Ƿ�ɹ�
					q.push(idx + i);        // ��Ԫ�����
					num.push(last_num - 1);
				}
				// ���û�ҵ���ʲôҲ����
			}
		}
		return false;
	}
};
