#include<iostream>
#include<vector>
#include<math.h>
namespace yyw
{
	class bitset
	{
	public:
		bitset(size_t N)
		{
			_bits.resize(N / 32 + 1, 0);
			_num = 0;
		}

		//将x位的比特位设置为1
		void set(size_t x)
		{
			size_t index = x / 32;           //映射出x在第几个整形
			size_t pos = x % 32;             //映射出x在整形的第几个位置
			_bits[index] |= (1 << pos);
			_num++;
		}

		//将x位的比特位设置为0
		void reset(size_t x)
		{
			size_t index = x / 32;
			size_t pos = x % 32;
			_bits[index] &= ~(1 << pos);
			_num--;
		}

		//判断x位是否在不在
		bool test(size_t x)
		{
			size_t index = x / 32;
			size_t pos = x % 32;

			return _bits[index] & (1 << pos);
		}

		//位图中比特位的总个数
		size_t size()
		{
			return _num;
		}
	private:
		std::vector<int> _bits;
		size_t _num;            //映射存储了多少个数据
	};

	void tes_bitset()
	{
		bitset bs(100);
		bs.set(99);
		bs.set(98);
		bs.set(97);

		bs.set(10);

		for (size_t i = 0; i < 100; i++)
		{
			printf("[%d]:%d\n", i, bs.test(i));
		}

		//40亿个数据，判断某个数是否在数据中
		//bs.reset(-1);
		//bs.reset(pow(2, 32));
	}
}