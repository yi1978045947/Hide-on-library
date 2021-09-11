#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

int rand3()
{
	int n = 5;
	// rand5 [1,2,3,4,5]
	while (n > 3)
	{
		n = rand5();
	}
	return n;
}

int Rand7()
{
	int x;
	do
	{
		x = Rand5() + (Rand5() - 1) * 5;
	} while (x > 21)
		return x % 7 + 1;
}

int Rand7()
{
	int x;
	do
	{
		x = Rand5() + (Rand5() - 1) * 5 + (rand5() - 1) * 20;
	} while (x > 70)
		return x;
}