#include <stdio.h>

int main()
{
	int n, i, m, ans;
	
	scanf("%d", &n);
	
	ans = n / 5;
	m = n % 5;
	while (m>0)
	{
		if (n < m)
		{
			ans = -1;
			break;
		}
		else if (m % 3 == 0)
		{
			ans = ans + (m / 3);
			break;
		}
		m += 5;
		ans--;
	}
	printf("%d", ans);
}