#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<memory>
using namespace std;

class HeapOnly
{
public:
	static HeapOnly* GetObj()
	{
		return new HeapOnly;
	}
private:
	HeapOnly()
	{}
	//C++98声明为私有
	HeapOnly(HeapOnly&);
	
	//C++11
	HeapOnly(HeapOnly&) = delete;
};
int main()
{
	//HeapOnly* p = HeapOnly::GetObj(); 防止内存泄漏，用智能指针
	std::shared_ptr<HeapOnly> sp1(HeapOnly::GetObj());
	return 0;
}