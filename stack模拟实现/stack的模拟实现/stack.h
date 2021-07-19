#include<iostream>
#include<vector>
#include<list>
namespace yyw
{
	template<class T,class Container>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		T& top()
		{
			return _con.back();
		}

		T& size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};
	void teststack1()
	{
		stack<int, std::vector<int>> st1;
		st1.push(1);
		st1.push(2);
		st1.push(3);
		st1.push(4);
		while (!st1.empty())
		{
			std::cout << st1.top() << " ";
			st1.pop();
		}
		std::cout << std::endl;
	}
	void teststack2()
	{
		stack<int, std::list<int>> st1;
		st1.push(10);
		st1.push(9);
		st1.push(8);
		st1.push(7);
		while (!st1.empty())
		{
			std::cout << st1.top() << " ";
			st1.pop();
		}
		std::cout << std::endl;
	}
}