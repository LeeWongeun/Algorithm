#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	if (!(a > 0 && b < 10))
	{
		return 0;
	}
	else
	{
		printf("%d", a + b);
		return 0;
	}
}