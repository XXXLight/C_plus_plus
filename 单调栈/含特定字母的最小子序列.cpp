#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	string smallestSubsequence(string s, int k, char letter, int repetition) {
		int  n = s.size();
		int cnt = 0;  // ���滹δɨ�赽�� letter������
		for (int i = 0; i < n; ++i)  //ͳ��letter���ֵ�����
			if (s[i] == letter) cnt++;
		int toErase = n - k;   // Ҫɾȥn - k ��Ԫ��
		string res;         // ��
		int p = 0;          // ĿǰΪֹletter��ɨ���˵Ĵ���
		for (int i = 0; i < n; ++i)
		{
			while (toErase && res.size() && s[i] < res.back()) {  // ɾȥ�������ĸ
				if (res.back() == letter) {
					if (repetition > p - 1 + cnt)  // �����letter �����ճ�repetition ��letter
						break;
					p--;      // ����ɾ��
				}
				res.pop_back();
				toErase--;  //ɾȥһ��
			}
			if (s[i] == letter) p++, cnt--;  // ǰ�����ӣ��������
			res += s[i];
		}

		while (res.size() > k) {      // ����Ϊ������ĸ���ܲ�����ԭ�� ��©ɾһЩ Ԫ�أ����ڼ�鲹��
			if (res.back() == letter) p--;
			res.pop_back();
		}
		for (int i = k - 1; i >= 0; --i) { // ��Ϊǰ���Ԫ�ؿ��ܱ�letter��С������Ҫ���һ�²���letter
			if (p < repetition  && res[i] != letter) {//(����Ϊ�˱�֤letter�����㹻����letter����С�����ԵôӺ���ǰ������֤��С)
				res[i] = letter;
				++p;
			}
		}
		return res;
	}
};

