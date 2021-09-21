#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
// unique_ptr: RAII + operator*()/operator->()+解决浅拷贝方式：禁止拷贝---资源独占
// 一份资源只能被一个对象来进行管理，对象之间不能共享资源

// 应用场景：只能应用与资源被一个对象管理 并且不会被共享的场景当中

// 缺陷：多个对象之间不能共享资源

// 负责释放new资源
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

// 负责：malloc的资源的释放
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

// 关闭文件指针
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
	// T: 资源中所放数据的类型
	// DF: 资源的释放方式
	// 定制删除器
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
				// 问题：_ptr管理的资源：可能是从堆上申请的内存空间、文件指针、malloc空间...
				// delete _ptr; // 注意：此处的释放资源的方式不能写死了，应该按照资源类型不同找对应的方式释放
				// malloc--->free
				// new---->delete
				// fopen--->fclose关闭
				DF df;
				df(_ptr);
			}
		}

		////////////////////////////////////////////////////
		// 具有指针类似的行为
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
		// 解决浅拷贝方式---资源独占，即防止被拷贝

		// C++98
		/*
		将拷贝构造函数以及赋值运算符重载方法只声明不定义，并且需要将其权限设置为私有的

		// 只声明不定义,没有将权限设置为private---不行的：因为方法别人可以再类外定义
		*/
	private:
		unique_ptr(const unique_ptr<T, DF>&);
		unique_ptr<T, DF>& operator=(const unique_ptr<T, DF>&);

		// C++11: 可以让编译器不生成默认的拷贝构造以及赋值运算符重载---delete
		// 在C++11当中，delete关键字的功能扩展：释放new申请的空间  用其修饰默认成员函数，表明：编译器不会生成了
		// unique_ptr(const unique_ptr<T,DF>&) = delete;  // 表明：编译器不会生成默认的拷贝构造函数
		// unique_ptr<T,DF>& operator=(const unique_ptr<T,DF>&) = delete;// 表明：编译器不会生成默认的赋值运算符重载
	private:
		T* _ptr;
	};

	// 用户在外部可以对方法进行定义---在unique_ptr的类中如果将该权限设置为private的
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
	// 标准库
	unique_ptr<int> up4(new int);
	// unique_ptr<int> up5(up4);
	unique_ptr<int> up6(new int);
	// up4 = up6;
	return 0;
}
