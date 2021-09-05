#define _CRT_SECURE_NO_WARNINGS   1
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char A[1000] = { '5', '0' };
	int B = 10;
	int m = 0;

	for (int i = 0; i<strlen(A); i++)
	{
		m = (m * 10 + A[i] - '0') % B;

	}
	cout << m << endl;
	return 0;
}

