#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
#include<memory>
int main()
{
	unique_ptr<int> up1(new int);
	// unique_ptr�����˼·�ǳ��Ĵֱ�-��������Ҳ���ǲ��ÿ����͸�ֵ
	
	unique_ptr<int> up2(up1);

	unique_ptr<int> up3(new int);
	up3 = up1;
	return 0;
}