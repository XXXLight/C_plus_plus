#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// �뵽�����������ֽ���취
class Solution {
public:
	vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
		int n = recipes.size();
		// ͼ������������ֹ�ϣ��Ĵ���ʽ����Ϊ��άvector��index�������ַ���
		unordered_map<string, vector<string>> depend;
		// ���ͳ��
		unordered_map<string, int> cnt;
		for (int i = 0; i < n; ++i) {
			for (const string& ing : ingredients[i]) {
				depend[ing].push_back(recipes[i]);
			}
			cnt[recipes[i]] = ingredients[i].size();
		}

		vector<string> ans;
		queue<string> q;
		// �ѳ�ʼ��ԭ���Ϸ�����У���ʼ���ϵ���ȶ���0
		for (const string& sup : supplies) {
			q.push(sup);
		}
		// ��������
		while (!q.empty()) {
			string cur = q.front();
			q.pop();
			if (depend.count(cur)) {
				for (const string& rec : depend[cur]) {
					--cnt[rec];
					// �����ȱ�Ϊ 0��˵���������������
					if (cnt[rec] == 0) {
						ans.push_back(rec);
						q.push(rec);
					}
				}
			}
		}
		return ans;
	}
};

