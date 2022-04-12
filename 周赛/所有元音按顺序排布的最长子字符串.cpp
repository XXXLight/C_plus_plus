#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int longestBeautifulSubstring(string word) {
		int len = word.size();
		int res = 0;
		for (int i = 0; i <= len - 5; i++) {
			if (word[i] == 'a') {
				int pa = i;
				while (word[pa] == 'a') pa++;
				int pe = pa;
				if (word[pe] != 'e') { i = pe - 1; continue; }// 因为i++的原因
				while (word[pe] == 'e') pe++;
				int pi = pe;
				if (word[pi] != 'i') { i = pi - 1; continue; }// 因为i++的原因
				while (word[pi] == 'i') pi++;
				int po = pi;
				if (word[po] != 'o') { i = po - 1; continue; }// 因为i++的原因
				while (word[po] == 'o') po++;
				int pu = po;
				if (word[pu] != 'u') { i = pu - 1; continue; }// 因为i++的原因
				while (word[pu] == 'u') pu++;
				if (pu - i > res) res = pu - i;
				if (pa == len || pe == len || pi == len || po == len) return 0;
				if (pu == len) break;
			}
		}
		return res;
	}
};


class Solution {
public:
	int longestBeautifulSubstring(string word) {
		int len = word.size();
		int res = 0;
		for (int i = 0; i <= len - 5;) {
			if (word[i] == 'a') {
				int pa = i;
				while (word[pa] == 'a') pa++;
				int pe = pa;
				if (word[pe] != 'e') { i = pe; continue; }
				while (word[pe] == 'e') pe++;
				int pi = pe;
				if (word[pi] != 'i') { i = pi; continue; }
				while (word[pi] == 'i') pi++;
				int po = pi;
				if (word[po] != 'o') { i = po; continue; }
				while (word[po] == 'o') po++;
				int pu = po;
				if (word[pu] != 'u') { i = pu; continue; }
				while (word[pu] == 'u') pu++;
				if (pu - i > res) res = pu - i;
				if (pa == len || pe == len || pi == len || po == len) return 0;
				if (pu == len) return res;
			}
			i++;
		}
		return res;
	}
};


class Solution {
public:
	int longestBeautifulSubstring(string word) {
		int len = word.size();
		int res = 0;
		int i = 0;
		while (i <= len - 5) {
			if (word[i] == 'a') {
				int pa = i;
				while (word[pa] == 'a') pa++;
				int pe = pa;
				if (word[pe] != 'e') { i = pe; continue; }
				while (word[pe] == 'e') pe++;
				int pi = pe;
				if (word[pi] != 'i') { i = pi; continue; }
				while (word[pi] == 'i') pi++;
				int po = pi;
				if (word[po] != 'o') { i = po; continue; }
				while (word[po] == 'o') po++;
				int pu = po;
				if (word[pu] != 'u') { i = pu; continue; }
				while (word[pu] == 'u') pu++;
				if (pu - i > res) res = pu - i;
				if (pa == len || pe == len || pi == len || po == len) return 0;
				if (pu == len) return res;
			}
			i++;
		}
		return res;
	}
};
