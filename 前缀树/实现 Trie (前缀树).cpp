#include<bits/stdc++.h>
using namespace std;



// ����ǰ׺���ļ��㣺
//	1.ǰ׺����˼�����ÿռ䣨���ṹ����ʱ�䣨���ң�
//  2.�����ӿ�д������ͬС�죬������΢�Ķ�����
//  3.���Ӷȷ�����ʱ�临�Ӷ�:(o(Len))  �ռ临�Ӷ�:(o(nk)),����Len�ǲ������ҵ��ַ������ȣ�n�ǽڵ�������k���ַ����ĸ���26
//  4.ǰ׺����Ӧ�ã����������


//ǰ׺����N������һ��
class Trie
{
public:
	bool is_string = false;//�ýڵ��Ƿ��ܱ�ʾһ���������ַ���,β����־
	Trie* next[26] = { nullptr };//ÿ���ڵ���26�����ӣ�26�����ӽڵ㣩
public:
	Trie() {}

// insert/search/startsWith�⼸���ӿ�д����𲻴󣬿���ֱ��copyһ�ݵ���һ�ݽ����޸�
	void insert(const string& word)//���뵥��
	{
		Trie* root = this;	//��ǰ���ĵ�ַ
		for (const auto& w : word) {
			if (root->next[w - 'a'] == nullptr)root->next[w - 'a'] = new Trie();//root��nextΪ�գ�Ϊ������һ���ռ�
			root = root->next[w - 'a'];//root��next�ڵ㲻Ϊ�գ��Ͳ��ò����ַ���root����Ϊnext�ڵ�
		}
		root->is_string = true;//β����־
	}

	bool search(const string& word)//���ҵ���
	{
		Trie* root = this;
		for (const auto& w : word) {
			if (root->next[w - 'a'] == nullptr)return false;//w�ַ�����ǰ׺���У�����false
			root = root->next[w - 'a'];
		}
		return root->is_string;//�õ�����ǰ׺�����Ƿ�Ϊһ���������ַ�����β����־
	}

	bool startsWith(string prefix)//����ǰ׺
	{
		Trie* root = this;
		for (const auto& p : prefix) {
			if (root->next[p - 'a'] == nullptr)return false;//w�ַ�����ǰ׺���У�����false
			root = root->next[p - 'a'];
		}
		return true;//ǰ׺�������ַ�����ǰ׺�У�����true
	}
};


//ǰ׺���ı���
vector<vector<char>> res;
vector<char> tmp;
void DFS(Trie *trie) {
	if (trie == nullptr) return;
	if (trie->is_string == true) {
		res.push_back(tmp);
		tmp.clear();//���tmp
		return;
	}
	for (int i = 0; i < 26; i++) {
		if (trie->next[i] != nullptr) {
			tmp.push_back(i + 'a');
			DFS(trie->next[i]);
		}
	}
}