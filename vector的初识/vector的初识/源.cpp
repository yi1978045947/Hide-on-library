#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void testvector1()   //无参和有参构造函数，拷贝构造函数
{
	vector<int> v1;  //vector<int>是类型 ，vector 是类名,类模板名字不是真正的类，而实例化的v才是真正的类
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.pop_back();

	vector<int>v2(v1); //构造函数

	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < v2.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	vector<int>::reverse_iterator vit = v1.rbegin();
	while (vit != v1.rend())
	{
		cout << *vit << " ";
		vit++;
	}
	cout << endl;

	vector<int>v3;
	v3.push_back(10);
	v3.push_back(9);
	v3.push_back(8);
	v3.push_back(7);
	v3.pop_back();
	v1 = v3;
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
}
void testvector2()   //遍历数据也是三种方法
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	for (size_t i = 0; i < v1.size(); i++)
	{
		v1[i] = v1[i] * 2;
		cout << v1[i] << " ";
	}
	cout << endl;
	vector<int>::iterator it = v1.begin();  //普通正向迭代器可以读可以写
	while (it != v1.end())
	{
		*it = *it * 2;
		cout << *it << " ";
		it++;
	}
	cout << endl;
	vector<int>::reverse_iterator vit = v1.rbegin();  //reverse逆置  reserve保留
	while (vit != v1.rend())
	{
		cout << *vit << " ";
		vit++;
	}
	cout << endl;
	for (auto e : v1)     //编译器替换成迭代器生成的
	{
		cout << e << " ";
	}
	cout << endl;
}
void print_vector(const vector<int>& v)  //传引用，加引用就加const,const 对象就要用const的迭代器
{
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		//*it = *it + 1;  const的迭代器不可以写，修改
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void testvector3()        //空间增长问题
{
	vector<int>v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.pop_back();
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	cout << v1.empty() << endl;

	size_t sz;
    vector<int> foo; 
	//foo.reserve(150);  //提前预留空间,改变容量
	foo.resize(1067);     //改变_size,开辟好了1067个空间，并初始化，后面如果push_back的话在1068下标开始增加空间 
	sz = foo.capacity();
	cout << "making foo grow:" << endl;
	for (int i = 0; i < 100; ++i)
	{
		//foo.push_back(i);
		foo[i] = i;
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << endl;
		}
	}
}

void testvector4()  //vector的增删查改
{
	vector<int> v1;
	v1.push_back(50);
	v1.push_back(-4);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(100);
	v1.push_back(200);
	v1.pop_back();
	for (size_t i = 0; i < v1.size(); i++) //[]访问，失败通过断言，记得写博客注明下,越界实现
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";          //at访问，失败抛异常
	}
	cout << endl;

	v1.insert(v1.begin(), 9);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	v1.erase(v1.begin());  //删除下标为0的值
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	v1.erase(v1.begin()+1); //删除下标为1的值
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>::iterator pos = find(v1.begin(), v1.end(), 100);  //查找算法
	if (pos != v1.end())
	{
		v1.erase(pos);
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	sort(v1.begin(), v1.end());  //排序算法
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	v1.erase(v1.begin(), v1.end());   //全部删除
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	//testvector1();   //构造函数
	 //testvector2();   //遍历方法
	vector<int>v1;   //const对象的迭代器
	v1.push_back(10);
	v1.push_back(9);
	//print_vector(v1);
	//testvector3();   //空间增长问题
	testvector4();
	return 0;
}