#include<iostream>
#include<string>
#include<cstring>
using namespace std;


class Solution {
public:
	/**
	 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	 *
	 *
	 * @param str string�ַ���
	 * @return string�ַ���
	 */
	string compress(string str) {
		// write code here
		for (int i = 0; i < str.length(); i++)
		{
			//�ҵ� ']'
			if (str[i] == ']')
			{
				//jΪ '['��λ��
				int j = i;
				//KΪ��|����λ��
				int k = 0;
				//��ǰ�ҵ� '['�� '|'
				while (str[j] != '[')
				{
					if (str[j] == '|')
					{
						k = j;//��¼|��λ��
					}
					j--;
				}

				int Num1 = stoi(str.substr(j + 1, k - j - 1));
				int Num2 = i - k - 1;
				string str2;
				for (int s1 = 0; s1 < Num1; s1++)
				{
					for (int s2 = 0; s2 < Num2; s2++)
					{
						str2 += str[k + 1 + s2];
					}
				}
				str.replace(j, i - j + 1, str2);
				str2.clear();
				i = 0;
			}
		}
		return str;
	}
};
