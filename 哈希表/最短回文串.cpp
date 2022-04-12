#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	typedef unsigned long long ULL;
	static const int P = 131;
	// static const int N=1e7+10;
	// ULL p[N],h[N],b[N];
	//������t�ˣ��ĳ�vector����
//�����ϣ��ʱ���±껻���� 1-n,����ת���±�Ҫ�ֶ���һ�£���������
	vector<ULL> p, h, b;
	int n;
	string ans;
	//��ǰ��������ϣ
	ULL geth(int l, int r) {
		return h[r] - h[l - 1] * p[r - l + 1];
	}
	//�Ӻ���ǰ�����ϣ
	ULL getb(int l, int r) {
		//���ҷ�����
		int rr = n - l + 1, ll = n - r + 1;
		// cout<<"rr="<<rr<<",ll="<<ll<<endl;
		return b[rr] - b[ll - 1] * p[rr - ll + 1];
	}
	string shortestPalindrome(string s) {
		n = s.size();
		if (n == 0) return s;
		// p[0]=1;
		// cout<<h[0]<<endl;
		//�����һ��ֵ��ȷ��p,h,b���Ǵ��±�1��ʼ
		p.push_back(1);
		h.push_back(0);
		b.push_back(0);

		for (int i = 1; i <= n; i++) {
			//Ԥ����p����
			p.push_back(p[i - 1] * P);
			//������ϣ
			h.push_back(h[i - 1] * P + s[i - 1]);
			b.push_back(b[i - 1] * P + s[n - i]);
		}

		for (int i = n; i >= 1; i--) {
			//����s�ַ����ĳ���
			int mid = i / 2, pl, pr, sl, sr;
			if (i & 1) {
				//���������
				//ǰ׺Prefix  ��׺suffix
				//��ߴ�0��ʼ�����е����
				pl = 0, pr = mid - 1;
				//�ұߴ��е��ұ߿�ʼ�������һ��ֵ
				sl = mid + 1, sr = i - 1;
			}
			else {
				//ͬ�ϣ���ߴ�0��ʼ�����е����
				pl = 0, pr = mid - 1;
				//�ұߴ��е㣬�����һ��ֵ
				sl = mid, sr = i - 1;
			}
			//�ǵð��±��0-n-1 ת�� 1-n;
			if (geth(pl + 1, pr + 1) == getb(sl + 1, sr + 1)) {
				if (i == n) {
					//������֣��ַ����������һ�����Ĵ��������䱾��
					return s;
				}
				else {
					//�ַ��������ǻ��Ĵ���ȡ���ַ��������ȡ���Ĵ��Ĳ���  suffix
					string suffix = s.substr(i);
					//��תһ��
					reverse(suffix.begin(), suffix.end());
					//�ӵ��ַ���ǰ������
					return suffix + s;
				}
			}
		}
		return ans;
	}
};

