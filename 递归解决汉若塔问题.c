#define _CRT_SECURE_NO_WARNINGS   1
#include <stdio.h>
//��i��Ԫ�ش�xͨ��y�ƶ���z��
void move(int i, char x, char y, char z)
{
	if (i == 1){
		printf("%c-->%c\n", x, z);//ֱ�Ӵ�x�ƶ���z��
	}
	else{
		move(i - 1, x, z, y);//��i-1��Ԫ�ش�xͨ��z�ƶ���y��
		printf("%c-->%c\n", x, z);//����i��Ԫ�ش�x�ƶ���z��
		move(i - 1, y, x, z);//��i-1��Ԫ�ش�yͨ��x�ƶ���z��
	}
}

int main()
{
	int i = 0;
	scanf("%d", &i);
	move(i, 'a', 'b', 'c');
	return 0;
}
