#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<assert.h>
typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(sizeof(DataType)*capacity);
		assert(_pData);
		_size = 0;
		_capacity = capacity;
	}
	~SeqList()                 //析构函数完成对类的资源清理
	{
		free(_pData);
		_pData = NULL;
		_size = _capacity = 0;
	}
private:
	DataType* _pData;
	int _size;
	int _capacity;
};