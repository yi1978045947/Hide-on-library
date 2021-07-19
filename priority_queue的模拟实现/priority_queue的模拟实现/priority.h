#include<iostream>
#include<vector>
#include<algorithm>
#pragma once
namespace yyw
{
	template<class T>
	struct less
	{
		bool operator()(const T& left, const T& right)
		{
			return left < right;
		}
	};
	template<class T>
	struct greater
	{
		bool operator()(const T& left, const T& right)
		{
			return left > right;
		}
	};
	template<class T,class Container=vector<T>,class Compare=less<T>>
	//template<class T,class Container=vector<T>>
	class priorty_queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);  //logN
		}
		void front()
		{
			_con.front();
		}
		void back()
		{
			_con.back();
		}
		void pop()
		{
			if (empty())
			{
				return;
			}
			std::swap(_con.front(), _con.back());
			_con.pop_back();
			AdjustDown(0); //logN
		}
		T& top()
		{
			return _con[0];
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while ( child>0 )
			{
				//if (_con[child] > _con[parent])
				if (com(_con[parent],_con[child])) 
				{
					std::swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void AdjustDown(int root)
		{
			Compare com;
			int parent = root;
			int child = 2 * parent + 1;
			while (child<_con.size())
			{
				/*if (child+1<_con.size()&&_con[child+1] > _con[child])*/
				if (child + 1<_con.size() && com(_con[child],_con[child+1]))
				{
					child++;
				}
				/*if (_con[child]>_con[parent])*/
				if (com(_con[parent], _con[child]))
				{
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
				{
					break;
				}
			}
		}
	};
	void testPriorityQueue()
	{
		priorty_queue<int, std::vector<int>> pq;
		//priorty_queue<int,std::vector<int>,greater<int>> pq;  //这里的仿函数是类型，模板类型
		pq.push(10);
		pq.push(5);
		pq.push(2);
		pq.push(3);
		pq.push(4);
		std::cout << pq.size() << std::endl;
		std::cout << pq.empty() << std::endl;
		while (!pq.empty())
		{
			std::cout << pq.top() << " ";
			pq.pop();
		}
		std::cout << std::endl;
	}
	void testsort()
	{
		std::vector<int> v1;
		v1.push_back(5);
		v1.push_back(6);
		v1.push_back(4);
		v1.push_back(3);
		sort(v1.begin(), v1.end());
		for (auto e : v1)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
		sort(v1.begin(), v1.end(), greater<int>());//这里的仿函数是对象
		for (auto e : v1)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
}