#include <iostream>
#include <cmath>

using namespace std;

void getInput(int& a, int& b, int& v)
{
	cin >> a >> b >> v;
}

int calcDay(int a, int b, int v)
{
	int day = 0;
	day = ceil((double)(v - a) / (double)(a - b));
	return ++day;
}

int main()
{
	int a, b, v;
	getInput(a, b, v);
	int ans = calcDay(a, b, v);
	
	cout << ans;
}