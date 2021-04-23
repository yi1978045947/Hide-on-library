#define _CRT_SECURE_NO_WARNINGS   1
#include"Stack.h"
int main()
{
	struct Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		printf("\n");
		StackPop(&st);
	}
	StackDestroy(&st);
	return 0;
}