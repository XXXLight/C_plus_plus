#include<bits/stdc++.h>
using namespace std;

// �Կո� ��Ϊ�ָ������зָ�
// ˼���ǳ����ַ�������С��temp�ַ�������
vector<string> split2(const string &str)
{
	vector<string> res;
	stringstream input(str);   //��ȡstr���ַ�������
	string temp;
	//ʹ��getline�������ַ������ж�ȡ,�����ָ���ʱֹͣ,�ʹ�cin�ж�ȡ����
	//ע��,getlineĬ���ǿ��Զ�ȡ�ո��
	while (input >> temp)
	{
		res.push_back(temp);
	}
	return res;
}

// pattern��Ϊ�ָ�������':'���Ե�������Ϊ�ָ���
vector<string> split3(const string &str, const char pattern)
{
	vector<string> res;
	stringstream input(str);   //��ȡstr���ַ�������
	string temp;
	//ʹ��getline�������ַ������ж�ȡ,�����ָ���ʱֹͣ,�ʹ�cin�ж�ȡ����
	//ע��,getlineĬ���ǿ��Զ�ȡ�ո��
	while (getline(input, temp, pattern))
	{
		res.push_back(temp);
	}
	return res;
}

int main() {
	string s = "ghsv habvg ldbfh fsdh ksdf";
	vector<string> res = split2(s);
	for (auto e : res) cout << e << " ";
	return 0;
}