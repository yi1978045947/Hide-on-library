#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<process.h>
#include<errno.h>
#define NAME_MAX 20
#define SEX_MAX 5
#define TEL_MAX 12
#define ADDR_MAX 32
#define MAX 1000
#define DEFAULT_SIZE 3

struct PeoInfo //定义一个结构体人,其中结构体包括人的基本信息
{
	char name[NAME_MAX];  //名字
	int age;              //年龄
	char sex[SEX_MAX];   //性别
	char tel[TEL_MAX];  //电话
	char addr[ADDR_MAX]; //地址
};

//struct Contact //通讯录的结构体，静态开辟的内存空间
//{
//	struct PeoInfo data[MAX];//创建一个数组存放人的信息
//	int sz;  //定义通讯录中当前存放人的信息个数
//};

struct Contact //通讯录的结构体，动态内存开辟
{
	struct PeoInfo* data;
	int sz; //当前存放数据的大小
	int capacity;  //总的数据的大小
};


//函数的声明
void InitContact(struct Contact* pc); //初始化通讯录
void AddContact(struct Contact* pc);  //增加一个人信息
void ShowContact(struct Contact* pc); //显示通讯录
void DelContact(struct Contact* pc);  //删除一个人的信息
void SearchContact(struct Contact* pc); //查找一个人的信息
void ModifyContact(struct Contact* pc); //修改个人信息
void SortContact(struct Contact* pc);  //对通讯录中的成员排序,按名字字母顺序来排
void ClearContact(struct Contact* pc); //清空通讯录
void SaveContact(struct Contact* pc);  //保存文件