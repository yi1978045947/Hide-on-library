#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string.h>
#include<assert.h>
#include<vector>
using namespace std;
#include<string>
void TestString1()            //构造函数
{
	string s1;                 //ok
	string s2("bit");          //ok
	string s3(s2);             //ok
	string s4("bit", 1);
	string s5("bit education", 1, 2);
	string s6("bit education", 1, string::npos); //npos是一个静态的全局变量为-1补码无穷大
	string s7("bit education", 1,20);
	string s8(5, 'a');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;
	cout << s8 << endl;
	s1 = s8;                //赋值 ok
	cout << s1 << endl;

}

void TestString2()         //[]+下标的遍历，重载了+=运算符----追加
{
	string s1("bit");

	s1 += 'e';
	cout << s1 << endl;
	s1 += ' ';
	s1 += "ducation";
	cout << s1 << endl;

	//[]+下标的遍历方式
	for (size_t i = 0; i < s1.size(); i++)   //读
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < s1.size(); i++)  //写，修改字符
	{
		s1[i] = s1[i] + 1;
	}
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
}

void TestString3()    //迭代器的遍历
{
	string s1("bit education");
	string::iterator it = s1.begin();
	//auto it=s1.begin();auto自动推导it是迭代器
	//vector<int>::iterator it=s1.begin();
	//读
	while (it != s1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//写
	it = s1.begin();
	while (it != s1.end())
	{
		*it = *it + 2;
		it++;
	}
	cout << s1 << endl;

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	vector<int>::iterator vit = v1.begin();
	while (vit != v1.end())
	{
		cout << *vit << " ";
		vit++;
	}
	cout << endl;
}
void TestString4()    //范围for的遍历 C++11原理是迭代器
{
	string s1("bit education");
	for (auto s : s1)   //依次取出容器s1里面的字符给s
	{
		cout << s << " ";
	}
	cout << endl;

	for (auto s : s1)
	{
		s = s + 1;
		cout << s << " ";
	}
	cout << endl;
}

void TestString5()    //反向迭代器,倒着遍历
{
	string s1("bit education");
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

int String2Int(const string& nums)  //const类型的参数就要用const类型的迭代器，const类型的迭代器只能读
{
	int val = 0;
	string::const_iterator it = nums.begin();
	while (it != nums.end())
	{
		//*it = 'a';
		val = val * 10;
		val = val + (*it - '0');
		it++;
	}
	return val;
}
int String2Int(string& nums)
{
	int val = 0;
	string::iterator it = nums.begin();
	while (it != nums.end())
	{
		val = val * 10;
		val = val + (*it - '0');
		it++;
	}
	return val;
}
void TestString6()//简单的字符串转为整形
{
	string nums("12345");
	int ret = String2Int(nums);
	cout << ret << endl;
}

void TestString7() //string类的容量操作
{
	string s1("bit education");
	string s2("C++");
	cout << s1.size() << endl;
	cout << s2.size() << endl;
	cout << s1.length() << endl;
	cout << s2.length() << endl;

	cout << s1.max_size() << endl;
	cout << s2.max_size() << endl;

	cout << s1.capacity() << endl;
	cout << s2.capacity() << endl;

	s1.clear();                  //size减为0
	cout << s1 << endl;
	cout << s1.capacity() << endl;

}

void TestString8()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:" << endl;
	for (size_t i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}
}
void TestString9 ()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow:" << endl;
	for (size_t i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}
}
void TestString10()
{
	string s;
	s.resize(100, 'a');
	size_t sz = s.capacity();
	cout << "making s grow:" << endl;
	for (size_t i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}
}

void TestString11()  //string 类对象的修改操作
{
	string s("bite");
	cout << s<< endl;
	s.push_back(' ');
	cout << s << endl;
	s.append("education");
	cout << s << endl;
	s += "!";
	cout << s << endl;

	s.insert(s.begin(), 'B');
	cout << s << endl;
	s.insert(0, "A");
	cout << s << endl;

	s.erase(2, 3);
	cout << s << endl;
	s.erase(s.begin(),s.end());
	cout << s << endl;

}

void TestString12()
{
	//获取字符数组首地址，用C字符串的形式遍历
	string s1("bie education");
	const char* str = s1.c_str();
	while (*str)
	{
		cout << *str << " ";
		str++;
	}
	cout << endl;
	s1 += '\0';
	s1 += "hello";
	cout << s1 << endl;           //调用的string重载operator<<  将对象数组中所有字符都输出
	cout << s1.c_str() << endl;   //直接输出const char* 遇到\0结束

	//打印所有字符256个
	for (unsigned char ch = 0; ch < 256; ch++)
	{
		cout << ch << " ";
	}
	cout << endl;
}

void TestString13()   //find获取文件的后缀,rfind可以倒着找
{
	string s1("string.cpp.zip");
	string s2("string.c");
	string s3("string.txt");
	size_t pos1 = s1.find('.');

	if (pos1 != string::npos)
	{
		cout << s1.substr(pos1) << endl;
	}
	size_t pos2 = s2.find('.');
	if (pos2 != string::npos)
	{
		cout << s2.substr(pos2) << endl;
	}
	size_t pos3= s3.find('.');
	if (pos3 != string::npos)
	{
		cout << s3.substr(pos3) << endl;
	}

	//协议 域名 资源名称
	string stringcpp("http://www.cplusplus.com/reference/string/string/find/");

	string &url = stringcpp;
	size_t pos4 = url.find(":");
	if (pos4 != string::npos)
	{
		cout << url.substr(0,pos4) << endl;
	}
	size_t pos5 = url.find('/', pos4 + 3);
	if (pos5 != string::npos)
	{
		cout << url.substr(pos4 + 3, pos5 - pos4-3) << endl;
	}
	cout << url.substr(pos5 + 1) << endl;
}

void TestString14()
{
	string s1("hello");
	string ret1 = s1 + "world";   //重载+不会改变s1
	string ret2 = s1 += "world";  //重载+=会改变s1
	cout << ret1 << endl;
	cout << ret2 << endl;

	string s2("aabbc");
	string s3("bbbdd");
	cout << (s2 > s3) << endl;
}

int main()
{
	//TestString1();
	//TestString2();
	//TestString3();
	//TestString4();
	//TestString5();
	//TestString6();
	//TestString7();
	//TestString8();
	//TestString9();
	//TestString10();
	//TestString11();
	//TestString12();
	//TestString13();
	TestString14();
	return 0;
}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
///*本题使用贪心算法，即保证每组的第二个值为当前最优选择
//*我们每次尽量选最大，但最大不能作为中位数，所以我们退而求次，取第二大
//*先排序：从大到小
//*再取第3n-1、3n-3、3n-5...作为每组第二个值累加起来*/
//int main()
//{
//	int n;//用来保存组数
//	while (cin >> n) //循环读取输入
//	{
//		long long sum = 0; //用来保存总和
//		vector<int> a(3 * n);//用来保存选手水平值
//		for (int i = 0; i < 3 * n; ++i)//循环读取选手水平值并保存
//		{
//			cin >> a[i];
//		}
//
//		sort(a.begin(), a.end());//对选手水平值从大到小排序
//		for (int i = n; i <= 3 * n - 2; i += 2)//从大到小分组并将每组第二大的值加起来
//		{
//			sum += a[i];
//		}
//		cout << sum << endl;//输出总和
//	}
//	return 0;
//}

