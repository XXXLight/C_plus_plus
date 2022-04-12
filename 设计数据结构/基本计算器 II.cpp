#include<bits/stdc++.h>
using namespace std;

// �������һ��
class Solution {
public:
	int calculate(string s) {
		// vector�Ϳ���ģ��ջ
		vector<int> stk;
		char preSign = '+';
		int num = 0;
		int n = s.length();
		for (int i = 0; i < n; ++i) {
			if (isdigit(s[i])) {
				num = num * 10 + int(s[i] - '0');
			}
			if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
				switch (preSign) {
				case '+':
					stk.push_back(num);
					break;
				case '-':
					stk.push_back(-num);
					break;
				case '*':
					stk.back() *= num;
					break;
				default:
					stk.back() /= num;
				}
				preSign = s[i];
				num = 0;
			}
		}
		return accumulate(stk.begin(), stk.end(), 0);
	}
};


// Q1:�õ�ʲô���ݽṹ����ջ��������vectorģ�⣩
// 1.ʱ�临�ӶȺͿռ临�Ӷȶ���o(n)
class Solution {
public:
	int calculate(string s) {
		int res = 0;// ������
		int len = s.size();
		char presign = '+';  // ����ǰ��������
		long long tmp = 0;	// ��ʱ�������
		vector<int> v;	// ģ��ջ
		for (int i = 0; i < len; i++) {
			// �������֣���ͣ�ۼ�
			if (isdigit(s[i])) tmp = tmp * 10 + s[i] - '0';
			// ���������Ҳ��ǿո������������
			if (!isdigit(s[i]) && s[i] != ' ' || i == len - 1) {
				// �������Ϊ���࣬�Ӽ�ֱ�ӷţ��˳���ջ���������㼴��
				if (presign == '+') {
					v.push_back(tmp);
				}
				else if (presign == '-') {
					v.push_back((-1)*tmp);
				}
				else if (presign == '*') {
					v.back() *= tmp;
				}
				else {
					v.back() /= tmp;
				}
				//��һ�ֵ����������һ�ֵģ���һ��tmp=0
				presign = s[i];// ���ڽ�β������һ�ֵĶ���
				tmp = 0;
			}
		}
		return accumulate(v.begin(), v.end(), 0);
	}
};