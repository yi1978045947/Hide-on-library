int main()
{
	int i = 0;
	int a = 0;
	while (i < 20)
	{
		for (;;)
		{
			if ((i % 10) == 0)
				break;
			else
				i--;
		}
		i += 11;
		a += i;
	}
	printf("%d\n", a);
	return 0;
}