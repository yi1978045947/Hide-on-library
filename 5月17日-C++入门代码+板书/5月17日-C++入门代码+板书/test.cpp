// C++ ����C���﷨
//#include<stdio.h>
//
//int main()
//{
//	printf("hello world\n");
//
//	return 0;
//}

// C/C++

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cout << "hello world" << endl;
//
//	return 0;
//}

// namespace �������һ����
// ���C����������ͻ����
//#include <stdio.h>
//
//int main()
//{
//	// ������ͻ
//	// C���ԵĿ����棬������������scanf��strlen����
//	// �����ҵĴ������������������������������
//	int scanf = 10;
//	int strlen = 20;
//
//	// C���Խ�����˳�ͻ������
//	scanf("%d", &scanf);
//
//	printf("%d\n", scanf);
//	printf("%d\n", strlen);
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include "List.h"
//
//// ������ͻ
//// C���ԵĿ����棬������������scanf��strlen����
//// �����ҵĴ������������������������������
//// ��
//namespace bit
//{
//	int scanf = 10;
//	int strlen = 20;
//
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	// Ƕ�׶��������ռ�
//	namespace N3
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//
//		// ����������
//	}
//}
//
//int main()
//{
//	// C���Խ�����˳�ͻ������
//	// C++,�����ռ䣬���ָ���
//	//scanf("%d", &scanf);
//
//	// Ĭ�Ϸ��ʵĲ��ֻ���ȫ��
//	printf("%x\n", scanf);
//	printf("%x\n", strlen);
//
//	// ָ������bit�����ռ���
//	printf("%x\n", bit::scanf);
//	printf("%x\n", bit::strlen);
//	bit::Add(1, 2);
//	bit::N3::Sub(10, 3);
//	bit::ListNode* phead = NULL;
//
//	return 0;
//}
//

//#include <iostream.h>  // ��һ���C++��׼�õ������VC6.0�����ã�û��std�����ռ�

//#include <iostream>
//#include <vector>
//#include <string>
//// C++��Ϊ�˷�ֹ������ͻ�����Լ�������Ķ�����������һ��std�������ռ���
//// Ҫʹ�ñ�׼���еĶ����������ַ�ʽ
//// 1��ָ�������ռ� -> �鷳��ÿ���ط�Ҫ�ö�Ҫָ��������ʱ������淶�ķ�ʽ
//// 2����std����չ�����൱�ڿ�����Ķ�������ȫ������ -> 
//// �����������ˣ���������Լ�����Ķ��������ͻ�˾�û�취����ˡ�
//// һҹ�ص����ǰ�����Թ淶�Ĺ�����Ŀ���ǲ��Ƽ����ַ�ʽ�ġ� -���ճ���ϰ�Ϳ�����
////using namespace std;
//
//// 3���Բ��ֳ��õĿ�����Ķ���չ�� -> ���1��2���з�������Ŀ��Ҳ�ᾭ����
//using std::cout;
//using std::endl;
//
//int a = 0;
//
//int main()
//{
//	// 1��ָ�������ռ� -> �鷳��ÿ���ط�Ҫ�ö�Ҫָ��������ʱ������淶�ķ�ʽ
//	std::cout << "hello world" << std::endl;
//	std::vector<int> v;
//	std::string s;
//
//	cout << "hello world" << endl;
//
//	int a = 1;
//	printf("%d\n", a);
//	printf("%d\n", ::a);
//
//	return 0;
//}

//#include <iostream>
//using namespace std;

// cout ������ʵ������������Ǵ���֪ʶ�����㡢������˽�һ�£���ס����ʹ��
// ostream ����ȫ�ֶ��� cout
// istream ����ȫ�ֶ��� cin
// endl ȫ�ֵĻ��з���

//int main()
//{
//	std::cout << "hello world";
//	std::cout << "hello world" << std::endl << std::endl;
//
//	// �Ա�C����printf scanf������ʲô -�� �Զ�ʶ������(ԭ����������+��������أ��Ժ��ٽ���)
//	int a = 10;
//	int* p = &a;
//	printf("%d,%p\n", a, p);
//	std::cout << a << "," << p << std::endl;
//
//	char str[10];
//	std::cin >> a;
//	std::cin >> str;
//	std::cout << a << str << std::endl;
//
//	return 0;
//}

struct Person
{
	char name[10];
	int age;
};

//int main()
//{
//	int a = 0;
//	cin >> a;			// scanf("%d", &a);
//	cout << a << endl;
//
//	struct Person p = {"С��", 10};
//	printf("name:%s\nage:%d\n", p.name, p.age); // ��ʽ�����
//	cout << "name:" << p.age << "\n" << "age:" << p.age << endl;
//	// ���飺���Ի����ã��ĸ����þ����ĸ�
//
//	return 0;
//}

// ȱʡ����
//void TestFunc(int a = 0)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	TestFunc(10);
//	TestFunc();
//
//	return 0;
//}

//// ȫȱʡ
//void TestFunc(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	TestFunc(1, 2, 3);
//	TestFunc();
//	TestFunc(1);
//	TestFunc(1,2);
//
//	return 0;
//}

// ��ȱʡ
//void TestFunc(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//// ȱʡ������������ʲô�����ø����
//
//int main()
//{
//	TestFunc(1);
//	TestFunc(1, 2);
//	TestFunc(1, 2, 3);
//
//	return 0;
//}
//struct Stack
//{
//	int* a;
//	int size;
//	int capacity;
//};
//
//void StackInit(struct Stack* ps, int InitCapacity = 4)
//{
//	ps->a = (int*)malloc(sizeof(int) * InitCapacity);
//	ps->size = 0;
//	ps->capacity = InitCapacity;
//}
//
//// ȱʡ����-������ʱ�����
//int main()
//{
//	struct Stack st1;
//	// ������֪��ջ��������Ҫ��100������
//	StackInit(&st1, 100);
//
//
//	struct Stack st2;
//	// ������֪��ջ�������Ҫ��10������
//	StackInit(&st2, 10);
//
//	struct Stack st3;
//	// �����Ҳ�֪��ջ������ܴ��������
//	StackInit(&st2);
//
//	return 0;
//}

// C���Բ�������ͬ������
// C++����-���������� -����������ͬ��������ͬ  ���������Ͳ�ͬ�����߸�����ͬ��
//int Add(int left, int right)
//{
//	return left + right;
//}

//int Add(int left = 10, int right = 20)
//{
//	return left + right;
//}
//
//char Add(char left, char right)
//{
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	return left + right;
//}
//
//// �������أ���������һ����
//void f(int a, int b, int c = 1)
//{}
//
//void f(int a, int b)
//{}
//
//int main()
//{
//	cout << Add() << endl;
//	cout << Add(1, 2) << endl;  // ������  ��������Ĭ���㳣��
//	cout << Add('1', '2') << endl;
//	cout << Add(1.1, 2.2) << endl;
//
//	f(1, 2, 3);
//	// f(1, 2);
//
//	return 0;
//}

//void swap(int* a, int* b)
//{
//	// ...
//}
//
//void swap(double* a, double* b)
//{
//	// ...
//}
//
//// ѧϰ��Щϸ����﷨
//// 1����Щ�﷨һ���������ٶ�c���Ե�һЩ�����õط�������
//// 2��ѧϰ��Щ��Ҳ��Ϊ����ѧϰC++��Ͷ������̵�
//int main()
//{
//	int x = 0, y = 1;
//	swap(&x, &y);
//
//	double m = 1.1, n = 2.2;
//	swap(&m, &n);
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	// b��a������(����)
//	int& b = a;
//	b = 20;
//
//	int& c = b;
//	c = 30;
//
//	return 0;
//}

void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void swap(int& r1, int& r2)
{
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}

struct Stack
{
	int* a;
	int size;
	int capacity;
};

void StackInit(struct Stack* ps)
{}

void StackInit(struct Stack& s)
{}

int main()
{
	int a = 1, b = 2;
	swap(&a, &b);
	swap(a, b);

	struct Stack st;
	StackInit(&st);

	StackInit(st);

	return 0;
}