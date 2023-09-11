#include <iostream>
#include<cmath>

using namespace std;

void getInput(int& m, int& n);
bool isPrime(int n);

int main()
{
    int m, n;
    getInput(m, n);
    for (int i = m; i <= n; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }
}

void getInput(int& m, int& n)
{
    cin >> m >> n;
}

bool isPrime(int n)
{
    if (n == 1)
        return false;

    if (sqrt(n) <= 1)
        return true;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}
