#include<iostream>
#include<string>
#include<cstring>
using namespace std;


class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param str string字符串
	 * @return string字符串
	 */
	string compress(string str) {
		// write code here
		for (int i = 0; i < str.length(); i++)
		{
			//找到 ']'
			if (str[i] == ']')
			{
				//j为 '['的位置
				int j = i;
				//K为“|”的位置
				int k = 0;
				//往前找到 '['和 '|'
				while (str[j] != '[')
				{
					if (str[j] == '|')
					{
						k = j;//记录|的位置
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
