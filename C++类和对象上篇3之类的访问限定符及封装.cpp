#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
typedef int STDateType;
//class������಻�ӷ����޶���Ĭ��Ϊ˽�б�����structĬ��Ϊ���б���
//��Ա����(��Ա����)������˷��ʶ���Ϊ���У���������˷��ʶ���Ϊ˽��
class Stack
{
public:
	//��Ա����������
	void StackInit(int initSize = 4);
	void StackPush(STDateType x);

private:
	//��Ա����������
	STDateType* a;
	int size;
	int capacity;
};

//��Ա�����Ķ���
void Stack::StackInit(int initSize)
{
	a = (STDateType*)malloc(sizeof(STDateType)*initSize);
	size = 0;
	capacity = initSize;
}
void Stack::StackPush(STDateType x)
{
	a[size] = x;
	size++;
}
int main()
{
	Stack st;
	st.StackInit();
	st.StackPush(1);
	st.StackPush(2);
	return 0;
}