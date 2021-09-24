#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string reverseSentence(string A)
{
	std::reverse(A.begin(), A.end());
	int i = 0;
	int j = 0;
	for (i = 0; i < A.size(); i++)
	{
		j = i;
		while (j < A.size() && A[j] != ' ')
		{
			j++;
		}
		std::reverse(A.begin() + i, A.begin() + j);
		i = j;
	}
	return  A;
}
int main()
{
	string str = "";
	getline(cin, str);
	string rstr = "";
	rstr = reverseSentence(str);
	for (int i = 0; i < rstr.size(); i++)
	{
		cout << rstr[i];
	}
	cout << endl;
	return 0;
}