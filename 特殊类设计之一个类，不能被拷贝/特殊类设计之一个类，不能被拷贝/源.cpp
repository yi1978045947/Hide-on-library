#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

class CopyBan
{
public:
	CopyBan()
	{}
private:
	//ֻ���������壬��������Ϊ˽��
	CopyBan(const CopyBan&);
	CopyBan operator=(const CopyBan&);

	CopyBan(const CopyBan&) = delete;
	CopyBan operator=(const CopyBan&) = delete;

};
int main()
{
	CopyBan a;
	CopyBan b(a);
	CopyBan c;
	c = a;
	return 0;
}