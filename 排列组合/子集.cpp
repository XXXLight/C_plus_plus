#include<bits/stdc++.h>
using namespace std;

// �ο��ĵ���https://leetcode-cn.com/problems/subsets/solution/c-zong-jie-liao-hui-su-wen-ti-lei-xing-dai-ni-gao-/

//	backtrack���
//	��1���߽�
//	��2��tmp��
//	��3��tmp����
//

//��ʽһ��д�ɷ��벻������״̬��˼·�ǳ�������������⣨�Ӽ����������һ�е�Ҷ�ӽڵ�洢���
//                              []             depth=0             
//						      /    \
//							[1]     []        --------�Ƿ��1;depth=1
//                          / \    /  \
//                       [12] [1] [2]  []     --------�Ƿ��2;depth=2


class Solution {
public:
	//��Ϊ��Ա�����ĺô��ǲ������ô�����ȥ
	vector<int> tmp; //���1���м���  ���2��ѡ�벻ѡ�γɵ�·��
	vector<vector<int>> res; //�洢���

	void backtrack(int depth, vector<int>& nums) {
		//�Ӽ�����ĵݹ�߽��Ǵﵽ����β��,��Ϊ��0��ʼ��[0,nums.size()-1)
		if (depth == nums.size()) {//depth��ʾ�ݹ���ȣ��ﵽ����ĩβ����Ҫ��Ž����
			res.push_back(tmp); //�Ѿ��γ����м�·��
			return;//������return
		}
		//����ʽ
		//��Ԫ��
		tmp.push_back(nums[depth]);
		backtrack(depth + 1, nums);
		//����Ԫ��
		tmp.pop_back();
		backtrack(depth + 1, nums);//���б����У��Թ�
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		backtrack(0, nums); //����ֻ��Ҫ��ԭʼ�������Ⱦ�����
		return res;
	}
};

//д��for(a a���Ե���ļ���)��"��������ʽ"
// ����ʽ��Ӧ�����νṹ��ÿ���м�ڵ�洢���
//                                 1 2 3
//                            /    |    \    \
//					         []    1     2    3
//                                / \     \
//                               12  13   23  
//                               /
//						       123
class Solution {
public:
	//��Ϊ��Ա�����ĺô��ǲ������ô�����ȥ
	vector<int> tmp; //���1���м���  ���2��ѡ�벻ѡ�γɵ�·��
	vector<vector<int>> res; //�洢���

	void backtrack(int depth, vector<int>& nums) {
		res.push_back(tmp); //ÿ���ڵ��ϴ洢������Ա����棬����û��return�Ĳ���
		// 1 2 3 i=0 {1}+[2,3]�Ӽ�  {} i=1 {2}+[3]���Ӽ�  i=2 ,{3}
		for (int i = depth; i < nums.size(); i++) {//����ÿһ��
			//3��ʽ
			tmp.push_back(nums[i]);
			backtrack(i + 1, nums); // ע��������i,����depth
			//����Ԫ��
			tmp.pop_back();
		}
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		backtrack(0, nums); //����ֻ��Ҫ��ԭʼ�������Ⱦ�����
		return res;
	}
};


//����һ�ַ���������һ�����Ͱ������Ӽ����ϸ�������µ��Ӽ���������ϼ��������Ӽ�
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.size() == 0) return { {} };//return {}��return {{}}�ǲ�һ����
		int n = nums.back();
		nums.pop_back();//��ɾ��һ��Ԫ�����Ӽ�
		vector<vector<int>> res = subsets(nums); // �˴�����ͨ�����Ʊ��������е���
		int len = res.size();
		for (int i = 0; i < len; i++) {
			res.push_back(res[i]);
			res.back().push_back(n);
		}
		return res;
	}
};

//��һ�ַ�����λ������
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		int len = pow(2, nums.size());//int len = 1 << (nums.size());  ��1������λ������ʾ
		vector<int> r;
		for (int mask = 0; mask < len; mask++) {
			for (int j = 0; j < nums.size(); j++) {
				if ((1 << j)&mask)   // if ((i >> j) & 1)
					r.push_back(nums[j]);
			}
			res.push_back(r);
			r.clear();
		}
		return res;
	}
};



class Solution {
public:
	//��Ϊ��Ա�����ĺô��ǲ������ô�����ȥ
	vector<int> tmp; //���1���м���  ���2��ѡ�벻ѡ�γɵ�·��
	vector<vector<int>> res; //�洢���

	void backtrack(int depth, vector<int>& nums) {
		//�Ӽ�����ĵݹ�߽��Ǵﵽ����β��,��Ϊ��0��ʼ��[0,nums.size()-1)
		if (depth == nums.size()) {//depth��ʾ�ݹ���ȣ��ﵽ����ĩβ����Ҫ��Ž����
			res.push_back(tmp); //�Ѿ��γ����м�·��
			return;//������return
		}
		//����ʽ
		//��Ԫ��
		tmp.push_back(nums[depth]);
		backtrack(depth + 1, nums);
		cout << "���" << depth << " ";
		for (auto e : tmp) cout << e << " ";
		cout << endl;
		//����Ԫ��
		tmp.pop_back();
		backtrack(depth + 1, nums);//���б����У��Թ�
		cout << "���" << depth << " ";
		for (auto e : tmp) cout << e << " ";
		cout << endl;
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		backtrack(0, nums); //����ֻ��Ҫ��ԭʼ�������Ⱦ�����
		return res;
	}
};





// ��һ�ַ�����λ������
// λ���ĵ������������bitset<λ��>(����n)�ķ�����ʵ��
// ע�����ʱ���Խ������Ʊ�������˼�룬�̶�i���䣬��j��
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		int len = pow(2, nums.size());//int len = 1 << (nums.size());  ��1������λ������ʾ��pow(2, nums.size())==1 << (nums.size())
		vector<int> r;
		for (int mask = 0; mask < len; mask++) {
			for (int j = 0; j < nums.size(); j++) {
				if ((1 << j)&mask)   // if ((i >> j) & 1)
				{
					r.push_back(nums[j]);
				}
			}
			// [1,2,3,4,5,6]�ļ��ϵĵ��Է���
			cout << bitset<6>(mask) << " ";// ������6λ����6λ������λ������ʾ
			for (auto e : r) cout << e << " ";
			cout << endl;
			res.push_back(r);
			r.clear();
		}
		return res;
	}
};