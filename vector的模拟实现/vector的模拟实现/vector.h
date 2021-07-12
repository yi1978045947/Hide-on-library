#include<iostream>
#include<assert.h>
namespace yyw
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		T& operator[](size_t i)
		{
			return _start[i];
		}

		//ǰ��һ��const����д,ֻ�ܶ��������const ��Ա��������Ϊconst����ֻ�ܵ���const��Ա����
		//��const����ȿ��Ե��÷�const��Ա����Ҳ���Ե���const��Ա����
		const T& operator[](size_t i) const   
		{
			return _start[i];
		}

		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _endofstorage - _start;
		}
		bool empty()
		{
			return (_finish - _start == 0);
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldsize = size();                      //��ֹ������ʧЧ������
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T)*size());   
					//memcpy��strcpy��һ�ο�����ʱ���ܸ���,memcpy����ʹ�ý��ж���֮��Ŀ���,���ֽڿ�����ǳ����
					for (size_t i = 0; i < oldsize; i++)
					{
						tmp[i] = _start[i];   //���õ���T��operator=�����
					}
					delete[] _start;
				}
				_start = tmp;
				//_finish = tmp + size();
				//_endofstorage = tmp + capacity();
				_finish = tmp + oldsize;
				_endofstorage = tmp + n;
			}
		}
		void resize(size_t n, const T& value = T())
		{
			if (n <= size())                    //nС��ԭ����sizeʱ��������С��n
			{
				_finish = _start + n;
				return;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}  //memset���ܶ��Զ������ͳ�ʼ������һ��һ����ֵ
				iterator it = _finish;
				_finish = _start + n;
				while (it != _finish)
				{
					*it = value;
					it++;
				}
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 2:capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;
		}
		void pop_back()
		{
			assert(_start < _finish);
			_finish--;
		}
		iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);       //=_finish����β��
			if (_finish == _endofstorage)
			{
				size_t n = pos - _start; //��ֹ������ʧЧ����

				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;

				reserve(newcapacity);
				pos = _start + n;  //��ֹ������ʧЧ����
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			_finish++;
			return pos;
		}
		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			iterator it = pos;   
			while (it < _finish)  //����ǰ�it�ƶ���_finish����ȥ��
			{
				*it = *(it + 1);
				it++;
			}
			_finish--;
			return pos;
		}



		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
		//v2(v1)
		vector(const vector<T>& v)     //��������
		{
			_start = new T[v.capacity()];
			_finish = _start;
			_endofstorage = _start + v.capacity();
			for (size_t i = 0; i < v.size(); i++)
			{
				*_finish = v[i];
				_finish++;
			}
		}

		//v2(v1)�Ȱ�v2��ʼ��Ϊ�գ�����v1����v1�����v2;
		//vector(vector<T>& v)
		//	:_start(nullptr)
		//	, _finish(nullptr)
		//	, _endofstorage(nullptr)
		//{
		//	for (auto& e : v)
		//	{
		//		reserve(v.capacity());
		//		push_back(e);
		//	}
		//}
		
		//s2=s1;  //��ֵ���������
		void Swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		//v3=v1;
		vector<T>& operator=(vector<T>& v)
		{
			//Swap(v);
			//return *this;
			if (this != &v)   //��ֵ���������Ҫ����Ƿ��Լ����Լ���ֵ
			{
				delete[] _start;
				_start = new T[v.capacity()];
				memcpy(_start, v._start, sizeof(vector<T>)*size());
			}
			return *this;
		}
	//private:
	//	T* _a;
	//	size_t size;
	//	size_t capacity;
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	void testvector1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.pop_back();
		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			//*it += 1;
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
		for (size_t i = 0; i < v1.size(); i++)
		{
			v1[i] -= 1;
			std::cout << v1[i] << " ";
		}
		std::cout << std::endl;
		for (auto& e : v1)          //֧�ֵ�������֧�ַ�Χfor
		{ 
			e -= 1;
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
	void testvector2()
	{
		const vector<int> v2;     //const�����vector
		vector<int>::const_iterator vit = v2.begin();
		while (vit != v2.end())
		{
			//*vit += 1;
			std::cout << *vit << " ";
		}
		std::cout << std::endl;
	}
	void testvector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.insert(v1.begin() + 1, 10);
		v1.erase(v1.begin() + 1);
		for (auto e : v1)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
	void testvector4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);

		std::cout << v1.size() << std::endl;
		std::cout << v1.capacity() << std::endl;
		v1.resize(10);
		v1.reserve(20);
		for (auto& e : v1)          //֧�ֵ�������֧�ַ�Χfor
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
		std::cout << v1.size() << std::endl;
		std::cout << v1.capacity() << std::endl;

		v1.resize(12);
		v1.reserve(30);
		for (auto& e : v1)          //֧�ֵ�������֧�ַ�Χfor
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
		std::cout << v1.size() << std::endl;
		std::cout << v1.capacity() << std::endl;
	}
	void testvector5()
	{
		vector<int> v1;
		v1.push_back(10);
		v1.push_back(9);
		v1.push_back(8);
		v1.push_back(7);
		v1.push_back(6);
		vector<int>v2(v1);
		for (auto& e : v1)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
		for (auto& e : v2)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
		vector<int> v3;
		v3 = v1;
		for (auto& e : v2)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
}
