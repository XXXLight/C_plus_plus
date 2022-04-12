#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	typedef unsigned long long ULL;
	static const int P = 131;
	// static const int N=1e7+10;
	// ULL p[N],h[N],b[N];
	//用数组t了，改成vector过了
//计算哈希的时候下标换成了 1-n,所以转换下标要手动算一下，免得算错了
	vector<ULL> p, h, b;
	int n;
	string ans;
	//从前往后计算哈希
	ULL geth(int l, int r) {
		return h[r] - h[l - 1] * p[r - l + 1];
	}
	//从后往前计算哈希
	ULL getb(int l, int r) {
		//左右反过来
		int rr = n - l + 1, ll = n - r + 1;
		// cout<<"rr="<<rr<<",ll="<<ll<<endl;
		return b[rr] - b[ll - 1] * p[rr - ll + 1];
	}
	string shortestPalindrome(string s) {
		n = s.size();
		if (n == 0) return s;
		// p[0]=1;
		// cout<<h[0]<<endl;
		//先填充一个值，确保p,h,b都是从下标1开始
		p.push_back(1);
		h.push_back(0);
		b.push_back(0);

		for (int i = 1; i <= n; i++) {
			//预处理p数组
			p.push_back(p[i - 1] * P);
			//正反哈希
			h.push_back(h[i - 1] * P + s[i - 1]);
			b.push_back(b[i - 1] * P + s[n - i]);
		}

		for (int i = n; i >= 1; i--) {
			//遍历s字符串的长度
			int mid = i / 2, pl, pr, sl, sr;
			if (i & 1) {
				//如果是奇数
				//前缀Prefix  后缀suffix
				//左边从0开始，到中点左边
				pl = 0, pr = mid - 1;
				//右边从中点右边开始，到最后一个值
				sl = mid + 1, sr = i - 1;
			}
			else {
				//同上，左边从0开始，到中点左边
				pl = 0, pr = mid - 1;
				//右边从中点，到最后一个值
				sl = mid, sr = i - 1;
			}
			//记得把下标从0-n-1 转成 1-n;
			if (geth(pl + 1, pr + 1) == getb(sl + 1, sr + 1)) {
				if (i == n) {
					//如果发现，字符串本身就是一个回文串，返回其本身
					return s;
				}
				else {
					//字符串本身不是回文串，取出字符串本身除取回文串的部分  suffix
					string suffix = s.substr(i);
					//反转一下
					reverse(suffix.begin(), suffix.end());
					//加到字符串前，即可
					return suffix + s;
				}
			}
		}
		return ans;
	}
};

