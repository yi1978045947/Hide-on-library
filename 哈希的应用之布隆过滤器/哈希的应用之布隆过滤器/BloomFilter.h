#include<iostream>
#include"bitset.h"
#include<string>
namespace yyw
{
	struct HashStr1
	{
		//BKDR1
		size_t operator()(const std::string& str)
		{
			size_t hash = 0;
			for (size_t i = 0; i < str.size(); i++)
			{
				hash *= 131;
				hash += str[i];
			}
			return hash;
		}
	};

	struct HashStr2
	{
		//RSHash
		size_t operator()(const std::string& str)
		{
			size_t hash = 0;
			size_t magic = 63689; //魔数
			for (size_t i = 0; i < str.size();i++)
			{
				hash *= magic;
				hash += str[i];
				magic *= 378551;
			}
			return hash;
		}
	};

	struct HashStr3
	{
		//SDBHash
		size_t operator()(const std::string& str)
		{
			size_t hash = 0;
			for (size_t i = 0; i < str.size(); i++)
			{
				hash *= 65599;
				hash += str[i];
			}
			return hash;
		}
	};

	//假设布隆过滤器元素类型为K，如果类型为K要自己配置仿函数
	template<class K,class Hash1=HashStr1,class Hash2=HashStr2,class Hash3=HashStr3>
	class bloomfilter
	{
	public:
		bloomfilter(size_t num)
			:_bs(5*num)
			, _N(5*num)
		{

		}
		void set(const K& key)
		{
			size_t index1 = Hash1()(key) % _N;
			size_t index2 = Hash2()(key) % _N;
			size_t index3 = Hash3()(key) % _N;

			_bs.set(index1);   //三个位置都设置为1
			_bs.set(index2);
			_bs.set(index3);
		}

		bool test(const K& key)
		{
			size_t index1 = Hash1()(key) % _N;
			if (_bs.test(index1) == false)
			{
				return false;
			}

			size_t index2 = Hash1()(key) % _N;
			if (_bs.test(index2) == false)
			{
				return false;
			}

			size_t index3 = Hash3()(key) % _N;
			if (_bs.test(index3) == false)
			{
				return false;
			}

			return true;  //但是这里也不一定是真的在，还有可能存在误判

			//判断不在是正确的，判断在可能存在误判
		}


	private:
		bitset _bs;                  //布隆过滤器底层是一个位图
		size_t _N;
	};

	void test_bloomfilter()
	{
		bloomfilter<std::string> bf(100);
		bf.set("aabb");
		bf.set("bbaa");
		bf.set("bbcc");
		std::cout << bf.test("aabb") << std::endl;
		std::cout << bf.test("bbaa") << std::endl;
		std::cout << bf.test("bbcc") << std::endl;
	}
}