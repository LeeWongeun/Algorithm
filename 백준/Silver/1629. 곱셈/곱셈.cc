#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
//3:10 ~ 3:44

long long fastMultiply(int a, int b, int c)
{
	if (b == 0) return 1;
	else if (b == 1) return a % c;

	long long temp = fastMultiply(a, b / 2, c) % c;
	long long mid = temp * temp % c;
	if (b % 2 == 1)
	{
		return mid * a % c;
	}
	else
	{
		return mid;
	}
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << fastMultiply(a,b,c);
}