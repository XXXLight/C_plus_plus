#include<bits/stdc++.h>
using namespace std;



class MagicDictionary {
private:
	// ����ǰ׺���ڵ�
	class Trie {
	public:
		// һ��27����֧��26��ĸ+1flag��
		bool isWord;// ��β��ʶ��
		vector<Trie*> children;// ���ʾ��Ƕ����
		Trie() : isWord(false), children(26, nullptr) {}

		void insert(const string& str) {
			Trie* node = this;
			for (auto& ch : str) {
				if (node->children[ch - 'a'] == nullptr) {
					node->children[ch - 'a'] = new Trie();
				}
				node = node->children[ch - 'a'];
			}
			node->isWord = true;
		}
	};
	Trie* root;
	bool dfs(Trie* root, string& word, int i, int edit) {
		// �����϶�û���滻һ��word���ַ���
		if (root == nullptr) {
			return false;
		}
		// �ݹ�߽磬�����ַ�����β��ǰ׺����flagΪtrue��word����ĩβ���޸Ĵ�����1
		if (root->isWord && i == word.size() && edit == 1) {
			return true;
		}
		// ��26����֧����DFS
		if (i < word.size() && edit <= 1) {
			bool found = false;
			for (int j = 0; j < 26 && !found; ++j) {
				int next = (j == word[i] - 'a') ? edit : edit + 1;
				if (dfs(root->children[j], word, i + 1, next)) found = true;
			}
			return found;
		}
		return false;
	}

public:
	/** Initialize your data structure here. */
	MagicDictionary() {
		root = new Trie();
	}
	// ���ôʿ��������ֵ���
	void buildDict(vector<string> dictionary) {
		for (auto& word : dictionary) {
			root->insert(word);
		}
	}

	bool search(string searchWord) {
		return dfs(root, searchWord, 0, 0);
	}
};







// ֱ�ӱ�������Ƚ�
class MagicDictionary {
public:
	vector<string> dic;
	/** Initialize your data structure here. */
	MagicDictionary() {

	}
	bool canchange(string d, string s) {
		if (d.length() != s.length()) return false;
		int num = 0;
		for (int i = 0; i < d.length(); i++) {
			if (s[i] != d[i]) {
				num++;
				if (num > 1) return false;
			}
		}
		return num == 1;
	}

	void buildDict(vector<string> dictionary) {
		this->dic = dictionary;
	}

	bool search(string searchWord) {
		for (int i = 0; i < dic.size(); i++) {
			if (canchange(dic[i], searchWord)) return true;
		}
		return false;

	}
};

