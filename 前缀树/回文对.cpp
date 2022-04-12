#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		if (words.empty())return {};
		vector<vector<int>> result;
		unordered_map<string, int> m;//����->�±�
		set<int> s;//���ʵĳ�������

		//��һ�α���������map���set��
		for (int i = 0; i < words.size(); ++i)
		{
			m[words[i]] = i;
			s.insert(words[i].size());
		}

		//�ڶ��α�����Ѱ�һ��Ķ�
		for (int i = 0; i < words.size(); ++i)
		{
			string word = words[i];
			int size = word.size();
			reverse(word.begin(), word.end());//��ת����
			//��һ����������ĶԾ�������������ȵĵ��ʻ�Ϊ��ת�ַ���,����abcd��dcba,����Ҫ�ų�bb���ַ�ת���������Լ����ַ���
			if (m.count(word) != 0 && m[word] != i) { result.push_back({ i,m[word] }); }
			//�ڶ�����������Ķ����������Ȳ�һ�ĵ��ʣ�����lls,��ת��Ϊsll,������set���ҵ�����Ϊ1�ĵ��ʣ���ȥ����1�ĺ�ll�Ƿ�Ϊ���Ķ�
			auto a = s.find(size);
			for (auto it = s.begin(); it != a; ++it)
			{
				int d = *it;//set�г���Ϊd�ĵ���
				//����str=���Ķ�+��ĸ������ddcba,�����ҵ�����Ϊ3�ĵ��ʣ����ж�dd�Ƿ���ģ�Ȼ���жϼ�ȥdd���cba�Ƿ���map��
				if (isValid(word, 0, size - d - 1) && m.count(word.substr(size - d)))
					result.push_back({ i,m[word.substr(size - d)] });
				//����str=��ĸ+���Ķԣ�����bcdaa,�����ҵ�����Ϊ3�ĵ��ʣ����ж�aa�Ƿ���ģ�Ȼ����жϼ�ȥaa���bcd�Ƿ���map��
				if (isValid(word, d, size - 1) && m.count(word.substr(0, d)))
					result.push_back({ m[word.substr(0,d)],i });
			}
		}
		return result;
	}

	bool isValid(string word, int left, int right)//�ж�word�Ƿ�Ϊ���Ķ�
	{
		while (left < right)
		{
			if (word[left++] != word[right--])
				return false;
		}
		return true;
	}
};

