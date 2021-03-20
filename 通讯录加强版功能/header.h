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

struct PeoInfo //����һ���ṹ����,���нṹ������˵Ļ�����Ϣ
{
	char name[NAME_MAX];  //����
	int age;              //����
	char sex[SEX_MAX];   //�Ա�
	char tel[TEL_MAX];  //�绰
	char addr[ADDR_MAX]; //��ַ
};

//struct Contact //ͨѶ¼�Ľṹ�壬��̬���ٵ��ڴ�ռ�
//{
//	struct PeoInfo data[MAX];//����һ���������˵���Ϣ
//	int sz;  //����ͨѶ¼�е�ǰ����˵���Ϣ����
//};

struct Contact //ͨѶ¼�Ľṹ�壬��̬�ڴ濪��
{
	struct PeoInfo* data;
	int sz; //��ǰ������ݵĴ�С
	int capacity;  //�ܵ����ݵĴ�С
};


//����������
void InitContact(struct Contact* pc); //��ʼ��ͨѶ¼
void AddContact(struct Contact* pc);  //����һ������Ϣ
void ShowContact(struct Contact* pc); //��ʾͨѶ¼
void DelContact(struct Contact* pc);  //ɾ��һ���˵���Ϣ
void SearchContact(struct Contact* pc); //����һ���˵���Ϣ
void ModifyContact(struct Contact* pc); //�޸ĸ�����Ϣ
void SortContact(struct Contact* pc);  //��ͨѶ¼�еĳ�Ա����,��������ĸ˳������
void ClearContact(struct Contact* pc); //���ͨѶ¼
void SaveContact(struct Contact* pc);  //�����ļ�