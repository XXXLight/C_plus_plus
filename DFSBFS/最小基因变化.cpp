#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	struct node {
		string str;
		int step;
	};
	//�ж�a��b�Ƿ�ֻ��1����ͬ��
	bool ischangeOne(string a, string b) {
		int n = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i])n++;
		}
		return n == 1;
	}
	int minMutation(string start, string end, vector<string>& bank) {
		vector<bool> vis = vector<bool>(bank.size());//����Ƿ���ʹ�
		queue<node> qq;
		qq.push({ start,0 });
		while (!qq.empty()) {
			auto[str, step] = qq.front(); qq.pop();
			if (str == end) {
				return step;
			}
			for (int i = 0; i < bank.size(); i++) {
				//������ʹ����������������1��������
				if (vis[i] || !ischangeOne(str, bank[i]))continue;
				qq.push({ bank[i],step + 1 });
				vis[i] = 1;
			}
		}
		return -1;
	}
};

