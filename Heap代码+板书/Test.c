	#include<stdio.h>

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n){
		// 选出左右孩子中小的那一个
		if (child+1 < n && a[child+1] > a[child]){
			++child;
		}

		if (a[child] > a[parent]){
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}

// 排升序，建大堆，还是小堆呢？-》大堆
void HeapSort(int* a, int n)
{
	// 建堆 -》 时间复杂度是多少？O(N) 大家下去自己先尝试理解证明？我们下节课讲解
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		// 选出次大的
		AdjustDown(a, end, 0);
		--end;
	}
}

int main()
{
	//int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	//AdjustDown(a, n, 0);

	int a[] = { 15, 18, 28, 34, 65, 19, 49, 25, 37, 27 };
	int n = sizeof(a) / sizeof(a[0]);
	HeapSort(a, n);

	return 0;
}