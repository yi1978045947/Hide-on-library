#define _CRT_SECURE_NO_WARNINGS   1
#include <stdio.h>
struct stu
{
	char name[20];
	int age;
	float score;
};
int main() //sprintf文件的写入到一个缓冲区里面
{
	struct stu s = { "鱼王", 20, 65.5f };
	char buff[200] = { 0 };
	//sprintf可以把一个结构化的数据转换为一个字符串
	sprintf(buff, "%s %d %f", s.name, s.age, s.score);
	printf("%s\n", buff); //从缓冲区里面把文件读取到屏幕上

	struct stu tmp = { 0 };
	//scanf可以把一个字符串转换为一个结构化的数据
	sscanf(buff, "%s%d%f", tmp.name, &(tmp.age), &(tmp.score));
	printf("%s %d %f\n", tmp.name, tmp.age, tmp.score);
	return 0;
}

//区分scanf,printf,fscanf,fprintf,sscanf,sprintf
//1.scanf、printf适用于标准的输入输出流的格式化输入输出语句
//2.fscanf、fprintf适用于所有的标准输入输出流的格式化输入输出语句
//3.sscanf、sprintf可以把结构化的数据转化为字符串，也可以把字符串中读取格式化的数据
//格式化数据:某种数据的格式