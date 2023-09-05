#include <iostream>

using namespace std;

int main()
{
	int n, num = 1 , ans = 1;
	
	cin >> n;
	do
	{
		n = n - num;
		num = (6 * ans);
		ans++;
	} while (n > 0);

	cout << ans - 1;
}