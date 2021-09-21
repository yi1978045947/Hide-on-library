#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
// unique_ptr: RAII + operator*()/operator->()+���ǳ������ʽ����ֹ����---��Դ��ռ
// һ����Դֻ�ܱ�һ�����������й�������֮�䲻�ܹ�����Դ

// Ӧ�ó�����ֻ��Ӧ������Դ��һ��������� ���Ҳ��ᱻ����ĳ�������

// ȱ�ݣ��������֮�䲻�ܹ�����Դ

// �����ͷ�new��Դ
template<class T>
class DFDef
{
public:
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}
};

// ����malloc����Դ���ͷ�
template<class T>
class Free
{
public:
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			free(ptr);
			ptr = nullptr;
		}
	}
};

// �ر��ļ�ָ��
class FClose
{
public:
	void operator()(FILE* & ptr)
	{
		if (ptr)
		{
			fclose(ptr);
			ptr = nullptr;
		}
	}
};


namespace yyw
{
	// T: ��Դ���������ݵ�����
	// DF: ��Դ���ͷŷ�ʽ
	// ����ɾ����
	template<class T, class DF = DFDef<T>>
	class unique_ptr
	{
	public:
		/////////////////////////////////////////////////////
		// RAII
		unique_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				// ���⣺_ptr�������Դ�������ǴӶ���������ڴ�ռ䡢�ļ�ָ�롢malloc�ռ�...
				// delete _ptr; // ע�⣺�˴����ͷ���Դ�ķ�ʽ����д���ˣ�Ӧ�ð�����Դ���Ͳ�ͬ�Ҷ�Ӧ�ķ�ʽ�ͷ�
				// malloc--->free
				// new---->delete
				// fopen--->fclose�ر�
				DF df;
				df(_ptr);
			}
		}

		////////////////////////////////////////////////////
		// ����ָ�����Ƶ���Ϊ
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* Get()
		{
			return _ptr;
		}

		////////////////////////////////////////////////////
		// ���ǳ������ʽ---��Դ��ռ������ֹ������

		// C++98
		/*
		���������캯���Լ���ֵ��������ط���ֻ���������壬������Ҫ����Ȩ������Ϊ˽�е�

		// ֻ����������,û�н�Ȩ������Ϊprivate---���еģ���Ϊ�������˿��������ⶨ��
		*/
	private:
		unique_ptr(const unique_ptr<T, DF>&);
		unique_ptr<T, DF>& operator=(const unique_ptr<T, DF>&);

		// C++11: �����ñ�����������Ĭ�ϵĿ��������Լ���ֵ���������---delete
		// ��C++11���У�delete�ؼ��ֵĹ�����չ���ͷ�new����Ŀռ�  ��������Ĭ�ϳ�Ա����������������������������
		// unique_ptr(const unique_ptr<T,DF>&) = delete;  // ��������������������Ĭ�ϵĿ������캯��
		// unique_ptr<T,DF>& operator=(const unique_ptr<T,DF>&) = delete;// ��������������������Ĭ�ϵĸ�ֵ���������
	private:
		T* _ptr;
	};

	// �û����ⲿ���ԶԷ������ж���---��unique_ptr�������������Ȩ������Ϊprivate��
	//template<class T>
	//unique_ptr<T>::unique_ptr(const unique_ptr<T>& up)
	//{}
}


#include <memory>

void TestUniquePtr()
{
	yyw::unique_ptr<int> up1(new int);
	yyw::unique_ptr<int, Free<int>> up2((int*)malloc(sizeof(int)));
	yyw::unique_ptr<FILE, FClose> up3(fopen("12345.txt", "w"));
}

int main()
{
	TestUniquePtr();

	yyw::unique_ptr<int> up1(new int);
	// yyw::unique_ptr<int> up2(up1);

	yyw::unique_ptr<int> up3(new int);

	// up1 = up3;

	///////////////////////////////////////
	// ��׼��
	unique_ptr<int> up4(new int);
	// unique_ptr<int> up5(up4);
	unique_ptr<int> up6(new int);
	// up4 = up6;
	return 0;
}
