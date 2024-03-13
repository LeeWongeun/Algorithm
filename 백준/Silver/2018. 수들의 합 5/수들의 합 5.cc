#include <iostream>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int begin = 0, end = 0, cnt = 1;
	int n;
	int sum = 0;

	cin >> n;
	while (end!=n)
	{
		if (sum == n)
		{
			cnt++;
			end++;
			sum += end;
		}
		else if (sum < n)
		{
			end++;
			sum += end;
		}
		else if (sum > n)
		{
			sum -= begin;
			begin++;
		}
	}
	cout << cnt;
}