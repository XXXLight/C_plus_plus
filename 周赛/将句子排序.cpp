#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	// �ַ����и�
	vector<string> getStr(string s) {
		vector<string> res;
		istringstream str(s);
		string out;
		while (str.good()) {
			getline(str, out, ' ');		//��str��ȡ�ַ�����out�У������ո��ֹͣ
			if (!out.empty()) 			//���ԭ�ַ������������Ŀո�out��Ϊ��
				res.push_back(out);
		}
		return res;
	}
	string sortSentence(string s) {
		string ret = "";
		vector<string> res = getStr(s);
		vector<string> r(res.size());
		for (int i = 0; i < res.size(); i++) {
			string tmp = res[i];
			int index = (tmp[tmp.size() - 1]) - '0' - 1;
			r[index] = tmp.substr(0, tmp.size() - 1);
		}
		for (int i = 0; i < r.size(); i++) {
			if (i != r.size() - 1) {
				ret += r[i];
				ret += " ";
			}
			else {
				ret += r[i];
			}
		}
		return ret;
	}
};