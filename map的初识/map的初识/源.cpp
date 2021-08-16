#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;


void test_map1()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 1));
	m.insert(pair<int, int>(2, 2));
	m.insert(pair<int, int>(3, 3));
	m.insert(make_pair(4, 4));
	map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		it++;
	}

	for (auto e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
}
void test_map2()
{
	map<string, string> m;

	m.insert(pair<string, string>("water", "水"));
	m.insert(pair<string, string>("apple", "苹果"));
	m.insert(make_pair("banan", "香蕉"));

	map<string, string>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		it++;
	}

	cout << m.size() << endl;
	cout << m.empty() << endl;

	m.erase("apple");

	for (auto e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << m.size() << endl;

	map<string, string>::iterator pos1 = m.find("banan");
	if (pos1 != m.end())
	{
		m.erase(pos1);
	}
	for (auto e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << m.size() << endl;

	//map<string,string>::iterator pos2 = find(m.begin(), m.end(),"water");
	//m.erase(pos2);

	for (auto e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << m.size() << endl;
}
void test_map3()  //第一种方法
{
	string str[] = { "西瓜", "西瓜", "菠萝", "西瓜", "西瓜", "西瓜", "苹果", "苹果" };
	map<string, int>countMap;
	for (auto& e : str)
	{
		map<string, int>::iterator pos = countMap.find(e);
		if (pos != countMap.end())
		{
			pos->second++;
		}
		else
		{
			countMap.insert(pair<string, int>(e, 1));
		}
	}

	for (auto e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}
void test_map4()
{
	string str[] = { "西瓜", "西瓜", "菠萝", "西瓜", "西瓜", "西瓜", "苹果", "苹果" };
	map<string, int>countMap;
	
	for (auto e : str)
	{
		countMap[e]++;
	}

	for (auto e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}
int main()
{
	test_map1();
	test_map2();
	test_map3();
	test_map4();
	return 0;
}