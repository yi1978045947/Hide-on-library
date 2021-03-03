#define _CRT_SECURE_NO_WARNINGS   1
#include <stdio.h>
//将i个元素从x通过y移动到z上
void move(int i, char x, char y, char z)
{
	if (i == 1){
		printf("%c-->%c\n", x, z);//直接从x移动到z上
	}
	else{
		move(i - 1, x, z, y);//将i-1个元素从x通过z移动到y上
		printf("%c-->%c\n", x, z);//将第i个元素从x移动到z上
		move(i - 1, y, x, z);//将i-1个元素从y通过x移动到z上
	}
}

int main()
{
	int i = 0;
	scanf("%d", &i);
	move(i, 'a', 'b', 'c');
	return 0;
}
