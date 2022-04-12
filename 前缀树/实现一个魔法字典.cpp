#include<bits/stdc++.h>
using namespace std;


class Trie
{
public:
	Trie * child[26];
	bool isWord;

	Trie()
	{
		memset(child, 0, sizeof(child));
		isWord = false;
	}

	void insert(string word)
	{
		Trie * root = this;
		for (char c : word)
		{
			int ID = c - 'a';
			if (root->child[ID] == NULL)
				root->child[ID] = new Trie();
			root = root->child[ID];
		}
		root->isWord = true;
	}

	bool search(string & word)
	{
		Trie * root = this;
		for (char c : word)
		{
			int ID = c - 'a';
			if (root->child[ID] == NULL)
				return false;
			root = root->child[ID];
		}
		return root->isWord == true;
	}

};

class MagicDictionary
{
public:
	Trie * T;

	/** Initialize your data structure here. */
	MagicDictionary()
	{
		T = new Trie();
	}

	void buildDict(vector<string> dictionary)
	{
		for (string word : dictionary)
			T->insert(word);
	}

	bool search(string searchWord)
	{
		int sn = searchWord.size();
		for (int i = 0; i < sn; i++)
		{
			for (int ID = 0; ID < 26; ID++)
			{
				char nc = 'a' + ID;
				if (searchWord[i] != nc)
				{
					string nxt_word = searchWord;
					nxt_word[i] = nc;
					if (T->search(nxt_word) == true)
						return true;
				}
			}
		}

		return false;
	}
};

