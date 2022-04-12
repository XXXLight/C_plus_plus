#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>


using namespace std;

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
		vector<vector<string>> res;
		// ��Ϊ��Ҫ�����ж���չ���ĵ����Ƿ��� wordList ������Ҫ�� wordList �����ϣ����������Ϊ���ֵ䡹
		unordered_set<string> dict = { wordList.begin(), wordList.end() };
		// �޸��Ժ�һ�£���������Ͳ��� dict ���棬����
		if (dict.find(endWord) == dict.end()) {
			return res;
		}
		// ������������
		dict.erase(beginWord);

		// �� 1 ����������ȱ�����ͼ
		// ��¼��չ���ĵ������ڵڼ�����չ��ʱ��õ��ģ�key�����ʣ�value���ڹ�����ȱ����ĵڼ���
		unordered_map<string, int> steps = { {beginWord, 0} };
		// ��¼�˵����Ǵ���Щ������չ������key�����ʣ�value�������б���Щ���ʿ��Ա任�� key ��������һ�Զ��ϵ
		unordered_map<string, set<string>> from = { {beginWord, {}} };
		int step = 0;
		bool found = false;
		queue<string> q = queue<string>{ {beginWord} };
		int wordLen = beginWord.length();
		while (!q.empty()) {
			step++;
			int size = q.size();
			for (int i = 0; i < size; i++) {
				const string currWord = move(q.front());
				string nextWord = currWord;
				q.pop();
				// ��ÿһλ�滻�� 26 ��СдӢ����ĸ
				for (int j = 0; j < wordLen; ++j) {
					const char origin = nextWord[j];
					for (char c = 'a'; c <= 'z'; ++c) {
						nextWord[j] = c;
						if (steps[nextWord] == step) {
							from[nextWord].insert(currWord);
						}
						if (dict.find(nextWord) == dict.end()) {
							continue;
						}
						// �����һ��������չ�����ĵ�����ǰ������������һ����Զ��Ϊ�˱����������Ѿ����������Ҿ����Զ�ĵ��ʣ���Ҫ������ dict ��ɾ��
						dict.erase(nextWord);
						// ��һ����չ���ĵ��ʽ������
						q.push(nextWord);
						// ��¼ nextWord �� currWord ����
						from[nextWord].insert(currWord);
						// ��¼ nextWord �� step
						steps[nextWord] = step;
						if (nextWord == endWord) {
							found = true;
						}
					}
					nextWord[j] = origin;
				}
			}
			if (found) {
				break;
			}
		}
		// �� 2 ����������ȱ����ҵ����н⣬�� endWord �ָ��� beginWord ������ÿ�γ��Բ��� path �б��ͷ��
		if (found) {
			vector<string> Path = { endWord };
			dfs(res, endWord, from, Path);
		}
		return res;
	}

	void dfs(vector<vector<string>> &res, const string &Node, unordered_map<string, set<string>> &from,
		vector<string> &path) {
		if (from[Node].empty()) {
			res.push_back({ path.rbegin(), path.rend() });
			return;
		}
		for (const string &Parent : from[Node]) {
			path.push_back(Parent);
			dfs(res, Parent, from, path);
			path.pop_back();
		}
	}
};

