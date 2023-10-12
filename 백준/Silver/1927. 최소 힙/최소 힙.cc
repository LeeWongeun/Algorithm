#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, input;
	priority_queue<int, vector<int>, greater<int>> q;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input)
		{
			q.push(input);
		}
		else
		{
			if (q.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}
	}
}