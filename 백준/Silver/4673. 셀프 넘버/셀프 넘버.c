#include <stdio.h>

int main()
{
	int dn = 0, n, i, a[11000] = { 0 };
	for (i = 1; i < 10000; i++)
	{
		n = i;
		dn = i;
		while (n > 0)
		{
			dn = dn + (n % 10);
			n = n / 10;
		}
		a[dn] = 1;
	}

	for (i = 1; i < 10000; i++)
	{
		if (a[i] == 0)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}