#define _CRT_SECURE_NO_WARNINGS   1
//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	static int _n; 
//};
//// ��̬��Ա�����Ķ����ʼ��
//int A::_n = 10;
//int main()
//{
//	A a;
//	//��̬��Ա��������ĳ������ͻ��������ܷ���
//	cout << a._n << endl;   //����1.ͨ�������ͻ��������з���
//	cout << A()._n << endl; //����2.ͨ����������ͻ��������з���
//	cout << A::_n << endl;  //����3.ͨ������ͻ��������з���
//	return 0;
//}

#include <iostream>
using namespace std;
class A
{
public:
	static int GetN()
	{
		return _n;
	}
private:
	static int _n;
};
// ��̬��Ա�����Ķ����ʼ��
int A::_n = 10;
int main()
{
	A a;
	cout << a.GetN() << endl;   //1.ͨ��ʵ�����Ķ�����ó�Ա�������з���
	cout << A().GetN() << endl; //2.ͨ������������ó�Ա�������з���
	cout << A::GetN() << endl;  //3.ͨ���������þ�̬��Ա�������з���
	return 0;
}

