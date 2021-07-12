#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void testvector1()   //�޲κ��вι��캯�����������캯��
{
	vector<int> v1;  //vector<int>������ ��vector ������,��ģ�����ֲ����������࣬��ʵ������v������������
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.pop_back();

	vector<int>v2(v1); //���캯��

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
void testvector2()   //��������Ҳ�����ַ���
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
	vector<int>::iterator it = v1.begin();  //��ͨ������������Զ�����д
	while (it != v1.end())
	{
		*it = *it * 2;
		cout << *it << " ";
		it++;
	}
	cout << endl;
	vector<int>::reverse_iterator vit = v1.rbegin();  //reverse����  reserve����
	while (vit != v1.rend())
	{
		cout << *vit << " ";
		vit++;
	}
	cout << endl;
	for (auto e : v1)     //�������滻�ɵ��������ɵ�
	{
		cout << e << " ";
	}
	cout << endl;
}
void print_vector(const vector<int>& v)  //�����ã������þͼ�const,const �����Ҫ��const�ĵ�����
{
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		//*it = *it + 1;  const�ĵ�����������д���޸�
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void testvector3()        //�ռ���������
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
	//foo.reserve(150);  //��ǰԤ���ռ�,�ı�����
	foo.resize(1067);     //�ı�_size,���ٺ���1067���ռ䣬����ʼ�����������push_back�Ļ���1068�±꿪ʼ���ӿռ� 
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

void testvector4()  //vector����ɾ���
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
	for (size_t i = 0; i < v1.size(); i++) //[]���ʣ�ʧ��ͨ�����ԣ��ǵ�д����ע����,Խ��ʵ��
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";          //at���ʣ�ʧ�����쳣
	}
	cout << endl;

	v1.insert(v1.begin(), 9);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	v1.erase(v1.begin());  //ɾ���±�Ϊ0��ֵ
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	v1.erase(v1.begin()+1); //ɾ���±�Ϊ1��ֵ
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>::iterator pos = find(v1.begin(), v1.end(), 100);  //�����㷨
	if (pos != v1.end())
	{
		v1.erase(pos);
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	sort(v1.begin(), v1.end());  //�����㷨
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	v1.erase(v1.begin(), v1.end());   //ȫ��ɾ��
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	//testvector1();   //���캯��
	 //testvector2();   //��������
	vector<int>v1;   //const����ĵ�����
	v1.push_back(10);
	v1.push_back(9);
	//print_vector(v1);
	//testvector3();   //�ռ���������
	testvector4();
	return 0;
}