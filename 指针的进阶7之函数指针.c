#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
void test1(int* pa)
{

}
void test2(int(*pc)[5])
{

}
int add(int x, int y)
{
	return x + y;
}
int my_strlen(const char* str)
{
	int count = 0;
	assert(str);
	while (*str)
	{
		str++;
		count++;
	}
	return count;
}
int main()
{
	int arr1[10];    //һά����
	int* pa = arr1;  //��Ԫ�صĵ�ַ
	int(*pb)[10] = &arr1;  //��������ĵ�ַ
	test1(arr1);

	int arr2[3][5];
	int(*pc)[5] = arr2;  //��Ԫ�صĵ�ַ����ά������Ԫ�صĵ�ַ�����һ�еĵ�ַ������������ָ�����
	int(*pd)[3][5] = &arr2;
	test2(arr2);


	//����ָ��---->������εĵ�ַ
	//����ָ��---->�������ĵ�ַ
	//����ָ��---->��ź����ĵ�ַ
	int a = 10;
	int* pe = &a;
	char arr3[10] = { 0 };
	char(*pf)[10] = &arr3;

	printf("%p\n", &add);
	printf("%p\n", add);  //&�������ͺ��������Ǻ����ĵ�ַ
	int(*pg)(int, int) = &add;  //pg���Ǻ���ָ��
	int(*ph)(int, int) = add;  //ph��pg������˼һ��

	//����ָ��ĵ���
	int sum = (*pg)(2, 3); //==  int usm=add(2,3);
	int ret = (pg)(2, 3);
	printf("%d\n", ret);
	printf("%d\n", sum);

	int(*str)(const char*) = &my_strlen;
	int len = (*str)("bit education");
	printf("%d\n", len);

	//������()�������ǿ������ת��-->��0ǿ������ת��Ϊ����ָ�����ͣ�Ȼ������õ���0��ַ���ĺ������ú�������ֵΪvoid������Ϊ�޲���
	(*(void(*)())0) ();

	//����һ����������
	//�����ĺ�����signal,signal������������������һ������������int,�ڶ������������Ǻ���ָ��
	//�ú����ķ���ֵ�ǿգ�������int
	//signal�����ķ���������һ������ָ�룬�ú���ָ��ָ��ĺ���������int������������void
	void(*signal (int, void(*)(int)) ) (int);   //void(*)(int) signal(int, void(*)(int));
	/*void(*)(int) ��һ������-->pfun_t;
	typedef void(*pfun_t)(int);
	pfun_t signal(int, pfun_t);
	*/
	return 0; 
}