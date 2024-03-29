#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
priority_queue<int> positive;
priority_queue<int, vector<int>, greater<int>> negative;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp > 0)
		{
			positive.push(temp);
		}
		else
		{
			negative.push(temp);
		}
	}

	int sum = 0;
	while (positive.size() > 1)
	{
		int num1 = positive.top();
		positive.pop();
		int num2 = positive.top();
		positive.pop();

		if (num1 == 1 || num2 == 1)
		{
			sum += num1 + num2;
		}
		else
		{
			sum += (num1 * num2);
		}
	}
	if (positive.size() != 0)
	{
		sum += positive.top();
	}

	while (negative.size() > 1)
	{
		int num1 = negative.top();
		negative.pop();
		int num2 = negative.top();
		negative.pop();

		sum += (num1 * num2);
	}
	if (negative.size() != 0)
	{
		sum += negative.top();
	}

	cout << sum;
}