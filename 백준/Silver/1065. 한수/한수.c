#include <stdio.h>

int isHansu(int num)
{
	int a = 0, b = 0;
	int c[3];
	if (num < 100)
	{
		return 1;
	}
	else if (num >= 1000)
	{
		return 0;
	}
	for (int i = 0; i < 3; i++)
	{
		c[i] = num % 10;
		num = num / 10;
	}
	if (c[0] - c[1] == c[1] - c[2])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int n, cnt = 0;
	scanf("%d", &n);

	for (int i = 1; i < n+1; i++)
	{
		if (isHansu(i))
		{
			cnt++;
		}
	}
	printf("%d", cnt);
}