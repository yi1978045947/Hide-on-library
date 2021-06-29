#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
#include<assert.h>
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)
		: _array(new T[capacity + 3])
		, _capacity(capacity + 3)
		, _size(0)
	{}

	// [fist, last)区间中包含的元素要放置到顺序表中
	SeqList(T* first, T* last)
	{
		T* it = first;
		size_t count = 0;
		while (it != last)
		{
			++it;
			++count;
		}

		_size = count;
		_capacity = count;
		_array = new T[_capacity];
		for (size_t i = 0; i < _size; ++i)
		{
			_array[i] = *first;
			++first;
		}
	}

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	void PushBack(const T& data)
	{
		_CheckCapacity();
		_array[_size++] = data;
	}

	void PopBack()
	{
		if (Empty())
			return;

		_size--;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	size_t Size()const
	{
		return _size;
	}

	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	const T& operator[](size_t index)const
	{
		assert(index < _size);
		return _array[index];
	}


private:
	void _CheckCapacity();

private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

template<class T>
void SeqList<T>::_CheckCapacity()
{}



int main()
{
	// SeqList不是具体的类，是类模板，是编译器根据实例化结果生成具体类的模具
	// SeqList s;

	SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	cout << s1[2] << endl;
	cout << typeid(s1).name() << endl;

	int array[] = { 1, 2, 3, 4, 5 };
	const SeqList<int> s3(array, array + sizeof(array) / sizeof(array[0]));
	cout << s3.Size() << endl;
	cout << s3[2] << endl;

	SeqList<double> s2;
	s2.PushBack(1.0);
	s2.PushBack(2.0);
	s2.PushBack(3.0);
	s2.PushBack(4.0);

	cout << s2.Size() << endl;
	cout << s2.Capacity() << endl;
	s2.PopBack();
	cout << s2.Size() << endl;
	cout << typeid(s2).name() << endl;

	return 0;
}