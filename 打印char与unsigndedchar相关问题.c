#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	unsigned char a = 200;
	unsigned char b = 100;
	unsigned char c = 0;
	c = a + b;
	printf("%d %d", a + b, c);
	return 0;
}
//00000000 00000000 00000000 11001000 200的原码
//00000000 00000000 00000000 01100100 100的原码
//00000000 00000000 00000001 00101100 相加发生截断,后整形提升
//00000000 00000000 00000000 00101100
/*
说明：printf在传入参数的时候如果是整形会默认传入四字节，所以a+b的结果是用一个四字节的整数接收的不会越界。而c已经在c = a + b这一步中丢弃了最高位的1，
所以只能是300-256得到的44了。
※由于printf是可变参数的函数，所以后面参数的类型是未知的，
所以甭管你传入的是什么类型，printf只会根据类型的不同将用两种不同的长度存储。
其中8字节的只有long long、float和double（注意float会处理成double再传入），
其他类型都是4字节。所以虽然a + b的类型是char，实际接收时还是用一个四字节整数接收的。
另外，读取时，%lld、%llx等整型方式和%f、%lf等浮点型方式读8字节，其他读4字节。
*/