#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

void findPrime(int n, int num);
bool isPrime(int n);

int N;
int firstNum[4] = { 2,3,5,7 };
int numbers[5] = { 1,3,5,7,9 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < 4; i++)
	{
		findPrime(1, firstNum[i]);
	}
}

void findPrime(int n, int num)
{
	if (n == N)
	{
		cout << num << '\n';
	}
	for (int i = 0; i < 5; i++)
	{
		int next = num * 10 + numbers[i];
		if (isPrime(next))
		{
			findPrime(n+1,next);
		}
	}
}

bool isPrime(int n)
{
	if (n == 1)
	{
		return false;
	}
	if (n == 2)
	{
		return true;
	}
	
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}