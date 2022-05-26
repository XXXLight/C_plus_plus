#include<bits/stdc++.h>
using namespace std;


//  һ�����������ٻ��־���ԭ���ĺ�����ʹ�ò�ֽ��������԰���������ת������������Ҷ˵㴦
class Solution {
public:
	vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
		map<int, int> mp;
		for (auto &it : flowers) mp[it[0]]++, mp[it[1] + 1]--;
		for (auto x : persons) mp[x];// ��仰�ȼ�����������
		/*for (auto x : persons) {
			if (not mp.count(x)) mp[x] = 0;
		};*/
		int sum = 0;
		for (auto &[x, y] : mp) {
			sum += y;
			y = sum;
		}
		// ֱ�ӽ���ӳ�䣬ԭ���Ǵ����øı�ԭ�������ݣ�����д��Ҫ����ѧϰ
		for (auto &x : persons)
			x = mp[x];
		return persons;
	}
};







// ��״����ⷨ
class Solution {
public:
	const int n = pow(10, 9) + 1;
	unordered_map<int, int> d;
	int low_bit(int x) {
		return x & -x;
	}
	void add(int x, int w) {
		while (x <= n) {
			d[x] += w;
			x += low_bit(x);
		}
	}
	int sum(int x) {
		int res = 0;
		while (x) {
			res += d[x];
			x -= low_bit(x);
		}
		return res;
	}
	vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
		for (auto fl : flowers) {
			int l = fl[0], r = fl[1];
			add(l, 1);
			add(r + 1, -1);
		}
		int size = persons.size();
		vector<int> res(size, 0);
		for (int i = 0; i < size; i++) {
			res[i] = sum(persons[i]);
		}
		return res;
	}
};




// ���ֲ��ҵ�������ͦ����ֲ��ҵ���Ŀ��ƾֱ��д�����Ĵ���
class Solution {
public:
	vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
		vector<vector<int>> v1, v2;
		v1 = flowers, v2 = flowers;
		// ������˵�����
		sort(v1.begin(), v1.end(), [](auto& e1, auto& e2) {
			return e1[0] < e2[0];
		});
		// �����Ҷ˵�����
		sort(v2.begin(), v2.end(), [](auto& e1, auto& e2) {
			return e1[1] < e2[1];
		});
		// �洢���������Ҷ˵�
		vector<int> vv1, vv2;
		for (auto& e : v1) {
			vv1.push_back(e[0]);
		}
		for (auto& e : v2) {
			vv2.push_back(e[1]);
		}
		vector<int> res;
		// ���ֲ���
		for (auto& e : persons) {
			int ind1 = upper_bound(vv1.begin(), vv1.end(), e) - vv1.begin();
			int ind2 = lower_bound(vv2.begin(), vv2.end(), e) - vv2.begin();
			res.push_back(abs(ind2 - ind1));
		}
		return res;
	}
};
