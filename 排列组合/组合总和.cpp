#include<bits/stdc++.h>
using namespace std;

//�����Ӽ������д����

//��ʽһ�����벻��
class Solution {
public:
	vector<int> tmp; //���1���м���  ���2��ѡ�벻ѡ�γɵ�·��
	vector<vector<int>> res; //�洢���

	void backtrack(int depth, vector<int>& candidates, int target) {
		if (target == 0) {//
			res.push_back(tmp); //�Ѿ��γ����м�·��
			return;//������return
		}
		// ��Ϊ�±�[0,candidates.size()-1),Խ����
		if (depth == candidates.size() || target - candidates[depth] < 0) return;//�������β�����Ѿ��ǲ�������
		//��һ�λ�ȡ���Ԫ�أ�����һ��Ԫ�ؿ����ظ�ѡ��
		// if(target-candidates[depth]>=0) ������
		tmp.push_back(candidates[depth]);
		backtrack(depth, candidates, target - candidates[depth]);
		//��ȡ���Ԫ��
		tmp.pop_back();
		backtrack(depth + 1, candidates, target);//ע�ⲻȡʱ��depth+1

	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());//�������Ҫsort
		backtrack(0, candidates, target); // �±�[0,candidates.size()-1)
		return res;
	}
};

//��ʽ����д��forѭ����ʽ��"������"
// 1.���ǰҪ�������νṹ
// 2.for������������ÿ�εݹ�ķ�֧��Ŀ��ͬ����ʾ����ÿ���ڵ㶼����ͬ������֧
class Solution {
public:
	vector<int> tmp; //���1���м���  ���2��ѡ�벻ѡ�γɵ�·��
	vector<vector<int>> res; //�洢���

	void backtrack(int depth, vector<int>& candidates, int target) {
		if (target < 0) return; 
		if (target == 0) {//
			res.push_back(tmp); //�Ѿ��γ����м�·��
			return;//������return
		}
		for (int i = depth; i < candidates.size(); i++) {
			tmp.push_back(candidates[i]);
			backtrack(i, candidates, target - candidates[i]);
			tmp.pop_back();
		}

	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());// ����sortû�б�Ҫ
		backtrack(0, candidates, target);
		return res;
	}
};