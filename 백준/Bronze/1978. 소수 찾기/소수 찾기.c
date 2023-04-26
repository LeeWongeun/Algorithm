#include <stdio.h>

int isDecimal(int num)
{
	if (num == 1)
	{
		return 0;
	}
	for (int i = 2; i < num; i++)
	{
		if (num == 2)
		{
			return 1;
		}
		else if (num % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int a, n, cnt=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (isDecimal(a))
		{
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}