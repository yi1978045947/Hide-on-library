#define _CRT_SECURE_NO_WARNINGS   1
//�������壬�����򵥸�
void reverse(char* left, char* right)
{
	while (left < right)
	{
		char tmp = 0;
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
char* reverseWords(char* s)
{
	int len = strlen(s);
	reverse(s, s + len - 1);
	char* start = s;
	char* end = s;
	while (*start != '\0')
	{
		end = start;
		while (*end != ' '&&*end != '\0')
		{
			end++;
		}
		reverse(start, end - 1);//����һ������

		if (*end == ' ')  //Ѱ����һ������
		{
			start = end + 1;
		}
		else
		{
			start = end;
		}
	}
	return s;
}
int main()
{
	return 0;
}