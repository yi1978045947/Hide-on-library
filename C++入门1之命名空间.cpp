#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>  //�ϵı�������iostream.h

//C++Ϊ�˷�ֹ������ͻ�����Լ�������Ķ�����������һ��std�������ռ���
//Ҫʹ�ñ�׼������Ķ����������ַ�ʽ
//1.ָ�������ռ�--�鷳��ÿ���ط���Ҫָ������Ҳ����淶�ķ�ʽ
int c = 100;
namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
	int Sub(int left, int right)
	{
		return left - right;
	}
}
//2.��std����չ�����൱�ڿ�����Ķ���ȫ����ȫ��������ȥ�ˣ�ʹ����������
//���ǿ��ܻ������Լ������ռ䶨��ĳ�ͻ���淶�����в��Ƽ����֣��ճ���ϰ����������
using namespace std;

//3.�Բ��ֳ��õĿ�����Ķ���չ��->���1��2�����з�������Ŀ��Ҳ����ʹ��
using std::cout;
using std::endl;
int main()
{
	printf("%d\n", N::a);
	printf("%d\n", N::b);
	printf("%d\n", N::Add(1, 2));
	printf("%d\n", N::Sub(1, 2));
	int c = 10;
	printf("%d\n", c);   //�ֲ��������ȣ�����cΪ10
	printf("%d\n", ::c); //ָ����������򣬿հױ�ʾȫ����
}