#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
// ר�Ŵ���int�ļӷ�����
int Add(int left, int right)
{
	return left + right;
}
// ͨ�üӷ�����
template<class T>
T Add(T left, T right)
{
	return left + right;
}
void Test()
{
	std::cout << Add(1, 2) << std::endl;       // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
	std::cout << Add<int>(1, 2) << std::endl; // ���ñ������ػ���Add�汾
}
int main()
{
	Test();
	return 0;
}

