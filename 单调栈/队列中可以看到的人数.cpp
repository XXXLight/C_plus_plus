#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> canSeePersonsCount(vector<int>& heights) {
		int n = heights.size();
		vector<int> ans(n);
		stack<int> s;
		for (int i = n - 1; i >= 0; --i) {
			while (!s.empty()) {
				++ans[i];
				if (heights[i] > heights[s.top()]) {
					s.pop();
				}
				else {
					break;
				}
			}
			s.push(i);
		}
		return ans;
	}
};


// ��һ�������8 1 2 3 4 9	��8�ܿ���4��������1 2 3 4�ǵ����ģ�9��Ϊ��8����ջ���գ����Ի�Ҫ��һ��
// �ڶ��������8 1 2 3 4	��8�ܿ���4��������1 2 3 4�ǵ����ģ�
class Solution {
public:
	vector<int> canSeePersonsCount(vector<int>& heights) {
		int len = heights.size();
		vector<int> res(len);//Ԥ�������ÿռ�
		stack<int> st;//���ڴ��ÿ���˵����
		for (int i = len - 1; i >= 0; i--) {//�Ӻ���ǰ����
			while (!st.empty() && st.top() < heights[i]) {//���û�����������ߵ���
				st.pop(); //ɾ����Щ�����͵��ˣ��ں����ı������Щ�˻ᱻ�������ס��
				res[i]++;//�������͵������ܿ���
			}
			if (!st.empty()) res[i]++;//����ǿգ������ܿ���һ���ˣ������һ���ѱ�����ס���ˣ�
			st.push(heights[i]);//������˸��浽ջ��
		}
		return res;
	}
};