#include<bits/stdc++.h>
using namespace std;


// Q1:�ĸ����������ĸ����ƺ��򣿣�pointNum��������for��������
class Solution {
private:
	vector<string> result;// ��¼���
	// startIndex: ��������ʼλ�ã�pointNum:��Ӷ��������
	void backtracking(string& s, int startIndex, int pointNum) {
		if (pointNum == 3) { // ��������Ϊ3ʱ���ָ�����
			// �жϵ��Ķ����ַ����Ƿ�Ϸ�������Ϸ��ͷŽ�result��
			// �������Ҷ�ӽڵ�
			if (isValid(s, startIndex, s.size() - 1)) {
				result.push_back(s);
			}
			return;
		}
		for (int i = startIndex; i < s.size(); i++) {
			if (isValid(s, startIndex, i)) { // �ж� [startIndex,i] ���������Ӵ��Ƿ�Ϸ�
				s.insert(s.begin() + i + 1, '.');  // ��i�ĺ������һ������
				pointNum++;
				backtracking(s, i + 2, pointNum);   // ���붺��֮����һ���Ӵ�����ʼλ��Ϊi+2
				pointNum--;                         // ����
				s.erase(s.begin() + i + 1);         // ����ɾ������
			}
			else break; // ���Ϸ���ֱ�ӽ�������ѭ��
		}
	}
	// �ж��ַ���s������ֱ�����[start, end]����ɵ������Ƿ�Ϸ�
	bool isValid(const string& s, int start, int end) {
		if (start > end) {
			return false;
		}
		if (s[start] == '0' && start != end) { // 0��ͷ�����ֲ��Ϸ�
			return false;
		}
		int num = 0;
		for (int i = start; i <= end; i++) {
			if (s[i] > '9' || s[i] < '0') { // �����������ַ����Ϸ�
				return false;
			}
			// ���ִ���������ۼ�
			num = num * 10 + (s[i] - '0');
			if (num > 255) { // �������255�˲��Ϸ�
				return false;
			}
		}
		return true;
	}
public:
	vector<string> restoreIpAddresses(string s) {
		result.clear();
		backtracking(s, 0, 0);
		return result;
	}
};




class Solution {
private:
	static constexpr int SEG_COUNT = 4;

private:
	vector<string> ans;
	vector<int> segments;

public:
	void dfs(const string& s, int segId, int segStart) {
		// ����ҵ��� 4 �� IP ��ַ���ұ��������ַ�������ô����һ�ִ�
		if (segId == SEG_COUNT) {
			if (segStart == s.size()) {
				string ipAddr;
				for (int i = 0; i < SEG_COUNT; ++i) {
					ipAddr += to_string(segments[i]);
					if (i != SEG_COUNT - 1) {
						ipAddr += ".";
					}
				}
				ans.push_back(move(ipAddr));
			}
			return;
		}

		// �����û���ҵ� 4 �� IP ��ַ���Ѿ����������ַ�������ô��ǰ����
		if (segStart == s.size()) {
			return;
		}

		// ���ڲ�����ǰ���㣬�����ǰ����Ϊ 0����ô��һ�� IP ��ַֻ��Ϊ 0
		if (s[segStart] == '0') {
			segments[segId] = 0;
			dfs(s, segId + 1, segStart + 1);
		}

		// һ�������ö��ÿһ�ֿ����Բ��ݹ�
		int addr = 0;
		for (int segEnd = segStart; segEnd < s.size(); ++segEnd) {
			addr = addr * 10 + (s[segEnd] - '0');
			if (addr > 0 && addr <= 0xFF) {
				segments[segId] = addr;
				dfs(s, segId + 1, segEnd + 1);
			}
			else {
				break;
			}
		}
	}

	vector<string> restoreIpAddresses(string s) {
		segments.resize(SEG_COUNT);
		dfs(s, 0, 0);
		return ans;
	}
};

