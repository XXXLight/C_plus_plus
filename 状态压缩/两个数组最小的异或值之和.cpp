#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		vector<int> f(1 << n, INT_MAX);
		f[0] = 0;
		for (int mask = 1; mask < (1 << n); ++mask) {
			for (int i = 0; i < n; ++i) {
				if (mask & (1 << i)) {
					f[mask] = min(f[mask], f[mask ^ (1 << i)] + (nums1[__builtin_popcount(mask) - 1] ^ nums2[i]));
				}
			}
		}
		return f[(1 << n) - 1];
	}
};



// ������ԣ����ǲ����
class Solution {
public:
	int minimumXORSum(vector<int>& a, vector<int>& b) {
		using ll = long long;
		int n = a.size();
		const int INF = 0x3f3f3f3f;
		vector<int> f(1 << n, INF);
		f[0] = 0;
		for (int mask = 1; mask < (1 << n); mask++) {
			for (int i = 0; i < n; i++) {
				if (mask&(1 << i)) {
					cout << bitset<3>(mask) << " " << "ȡb�ĵ�" << i << "��Ԫ�� ";
					f[mask] = min(f[mask], f[mask ^ (1 << i)] + (a[__builtin_popcount(mask) - 1] ^ b[i]));
					cout << bitset<3>(mask ^ (1 << i)) << " " << "ȡa�ĵ�" << __builtin_popcount(mask) - 1 << "��Ԫ��" << endl;
				}
			}
		}
		return f[(1 << n) - 1];
	}
};




// ģ���˻��㷨���е���
const double eps = 1e-18;
const double delta = 0.999;//����һ��Ĳ���һ��Ϊ0.97~1.0
class Solution {
public:
	vector<int> a, b;
	int ans = INT_MAX;//��
	double fun() {
		int res = 0;
		for (int i = 0; i < a.size(); i++)
			res += (a[i] ^ b[i]);
		ans = min(ans, res); //ȡ��С
		return res;
	}

	int sa() {
		random_shuffle(b.begin(), b.end()); //���ң�����ֲ�
		int n = a.size();
		for (double t = 1e6; t > eps; t *= delta) {
			int x = rand() % n, y = rand() % n;
			int last = fun(); //û�н���ǰ�����ֵ֮��
			swap(b[x], b[y]); //����������ֵ֮��
			int now = fun();
			int de = now - last;
			if (de < 0) { //�ȵ�ǰ�����Ҫ
			}
			else if (!(exp(-1.0*de / t)*RAND_MAX > rand()))  // ģ���˻�ķ�����Ҳ�㲻������һ�¾ͺ���
				swap(b[x], b[y]);  //�����Ϸ��򣬻��ݡ�
		}
		return ans;
	}

	int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
		for (int i : nums1) a.push_back(i);
		for (int i : nums2) b.push_back(i);
		return sa();
	}
};