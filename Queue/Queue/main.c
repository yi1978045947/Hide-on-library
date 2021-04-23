#define _CRT_SECURE_NO_WARNINGS   1
#include"Queue.h"
int main()
{
	struct Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (!QueueEmpty(&q))
	{
		printf("%d\n", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestroy(&q);
	return 0;
}