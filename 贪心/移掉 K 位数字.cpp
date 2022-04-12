#include<bits/stdc++.h>
using namespace std;

// ɾ����һ�������λ��
class Solution {
public:
	string removeKdigits(string num, int k) {
		string res;
		// �ܹ�nλ���Ƴ�kλ��ʣ��n-kλ
		int n = num.size(), m = n - k;
		for (auto c : num) {
			while (k && res.size() && res.back() > c) {
				res.pop_back();
				--k;
			}
			res.push_back(c);
		}
		res.resize(m);
		//ȥ��ǰ��0�� ��10200��k = 1
		while (!res.empty() && res[0] == '0') {
			res.erase(res.begin());
		}
		return res.empty() ? "0" : res;
	}
};



class Solution {
public:
	string removeKdigits(string num, int k) {
		while (k--) {
			int n = num.size(), i = 0;
			while (i + 1 < n && num[i] <= num[i + 1]) ++i;
			num.erase(i, 1); // ÿ�� erase ��ʱ�临�Ӷ�ΪO(n)
		}
		auto i = num.find_first_not_of("0");
		return i == string::npos ? "0" : num.substr(i);
	}
};
