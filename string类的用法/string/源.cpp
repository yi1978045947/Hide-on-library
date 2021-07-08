#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string.h>
#include<assert.h>
#include<vector>
using namespace std;
#include<string>
void TestString1()            //���캯��
{
	string s1;                 //ok
	string s2("bit");          //ok
	string s3(s2);             //ok
	string s4("bit", 1);
	string s5("bit education", 1, 2);
	string s6("bit education", 1, string::npos); //npos��һ����̬��ȫ�ֱ���Ϊ-1���������
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
	s1 = s8;                //��ֵ ok
	cout << s1 << endl;

}

void TestString2()         //[]+�±�ı�����������+=�����----׷��
{
	string s1("bit");

	s1 += 'e';
	cout << s1 << endl;
	s1 += ' ';
	s1 += "ducation";
	cout << s1 << endl;

	//[]+�±�ı�����ʽ
	for (size_t i = 0; i < s1.size(); i++)   //��
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < s1.size(); i++)  //д���޸��ַ�
	{
		s1[i] = s1[i] + 1;
	}
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
}

void TestString3()    //�������ı���
{
	string s1("bit education");
	string::iterator it = s1.begin();
	//auto it=s1.begin();auto�Զ��Ƶ�it�ǵ�����
	//vector<int>::iterator it=s1.begin();
	//��
	while (it != s1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//д
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
void TestString4()    //��Χfor�ı��� C++11ԭ���ǵ�����
{
	string s1("bit education");
	for (auto s : s1)   //����ȡ������s1������ַ���s
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

void TestString5()    //���������,���ű���
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

int String2Int(const string& nums)  //const���͵Ĳ�����Ҫ��const���͵ĵ�������const���͵ĵ�����ֻ�ܶ�
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
void TestString6()//�򵥵��ַ���תΪ����
{
	string nums("12345");
	int ret = String2Int(nums);
	cout << ret << endl;
}

void TestString7() //string�����������
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

	s1.clear();                  //size��Ϊ0
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

void TestString11()  //string �������޸Ĳ���
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
	//��ȡ�ַ������׵�ַ����C�ַ�������ʽ����
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
	cout << s1 << endl;           //���õ�string����operator<<  �����������������ַ������
	cout << s1.c_str() << endl;   //ֱ�����const char* ����\0����

	//��ӡ�����ַ�256��
	for (unsigned char ch = 0; ch < 256; ch++)
	{
		cout << ch << " ";
	}
	cout << endl;
}

void TestString13()   //find��ȡ�ļ��ĺ�׺,rfind���Ե�����
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

	//Э�� ���� ��Դ����
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
	string ret1 = s1 + "world";   //����+����ı�s1
	string ret2 = s1 += "world";  //����+=��ı�s1
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
///*����ʹ��̰���㷨������֤ÿ��ĵڶ���ֵΪ��ǰ����ѡ��
//*����ÿ�ξ���ѡ��󣬵��������Ϊ��λ�������������˶���Σ�ȡ�ڶ���
//*�����򣺴Ӵ�С
//*��ȡ��3n-1��3n-3��3n-5...��Ϊÿ��ڶ���ֵ�ۼ�����*/
//int main()
//{
//	int n;//������������
//	while (cin >> n) //ѭ����ȡ����
//	{
//		long long sum = 0; //���������ܺ�
//		vector<int> a(3 * n);//��������ѡ��ˮƽֵ
//		for (int i = 0; i < 3 * n; ++i)//ѭ����ȡѡ��ˮƽֵ������
//		{
//			cin >> a[i];
//		}
//
//		sort(a.begin(), a.end());//��ѡ��ˮƽֵ�Ӵ�С����
//		for (int i = n; i <= 3 * n - 2; i += 2)//�Ӵ�С���鲢��ÿ��ڶ����ֵ������
//		{
//			sum += a[i];
//		}
//		cout << sum << endl;//����ܺ�
//	}
//	return 0;
//}

