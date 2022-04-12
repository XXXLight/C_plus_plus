#include<bits/stdc++.h>
using namespace std;

// 以空格 作为分隔符进行分割
// 思想是长的字符串流到小的temp字符串里面
vector<string> split2(const string &str)
{
	vector<string> res;
	stringstream input(str);   //读取str到字符串流中
	string temp;
	//使用getline函数从字符串流中读取,遇到分隔符时停止,和从cin中读取类似
	//注意,getline默认是可以读取空格的
	while (input >> temp)
	{
		res.push_back(temp);
	}
	return res;
}

// pattern作为分隔符，如':'，以单引号作为分隔符
vector<string> split3(const string &str, const char pattern)
{
	vector<string> res;
	stringstream input(str);   //读取str到字符串流中
	string temp;
	//使用getline函数从字符串流中读取,遇到分隔符时停止,和从cin中读取类似
	//注意,getline默认是可以读取空格的
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