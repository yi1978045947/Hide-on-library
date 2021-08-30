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

		//��xλ�ı���λ����Ϊ1
		void set(size_t x)
		{
			size_t index = x / 32;           //ӳ���x�ڵڼ�������
			size_t pos = x % 32;             //ӳ���x�����εĵڼ���λ��
			_bits[index] |= (1 << pos);
			_num++;
		}

		//��xλ�ı���λ����Ϊ0
		void reset(size_t x)
		{
			size_t index = x / 32;
			size_t pos = x % 32;
			_bits[index] &= ~(1 << pos);
			_num--;
		}

		//�ж�xλ�Ƿ��ڲ���
		bool test(size_t x)
		{
			size_t index = x / 32;
			size_t pos = x % 32;

			return _bits[index] & (1 << pos);
		}

		//λͼ�б���λ���ܸ���
		size_t size()
		{
			return _num;
		}
	private:
		std::vector<int> _bits;
		size_t _num;            //ӳ��洢�˶��ٸ�����
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

		//40�ڸ����ݣ��ж�ĳ�����Ƿ���������
		//bs.reset(-1);
		//bs.reset(pow(2, 32));
	}
}