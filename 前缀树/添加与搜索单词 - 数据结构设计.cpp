#include<bits/stdc++.h>
using namespace std;

//ֻ�в���Ͳ��������ӿ�
class WordDictionary {
private:
	struct Trie {//����ǰ׺��
		Trie *children[26]{ nullptr };//26�����ӽڵ�
		bool is_string = false;//β����־
	};
	Trie *root;
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new Trie();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		Trie *note = root;
		for (const auto &w : word)
		{
			if (note->children[w - 'a'] == nullptr)
				note->children[w - 'a'] = new Trie();
			note = note->children[w - 'a'];
		}
		note->is_string = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return dfs(root, word, 0);
	}

	bool dfs(Trie* root, string word, int i)
	{
		if (root == nullptr)return false;
		if (i == word.size())return root->is_string;//�ݹ�߽磬����뵥�ʳ�����ͬ
		if (word[i] != '.')//���ַ���Ϊ��.
		{
			if (root->children[word[i] - 'a'] != nullptr)
				return dfs(root->children[word[i] - 'a'], word, i + 1);//���ַ���ǰ׺���У����������������
			else return false;//���ַ�����ǰ׺���У�ֱ�ӷ���false
		}
		for (int j = 0; j < 26; ++j)//������root�ĺ������ַ���·����ֻҪ��һ���ַ���·������ͷ���true
		{
			if (root->children[j] && dfs(root->children[j], word, i + 1))
				return true;
		}
		return false;
	}
};



