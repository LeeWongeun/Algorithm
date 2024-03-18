#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
		{
			return a > b;
		}
		return abs(a) > abs(b);
	}
};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, cmp> pq;
	
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (input == 0)
		{
			if (pq.empty())
			{
				cout << '0' << '\n';
			}
			else
			{
				cout << pq.top() <<'\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(input);
		}
	}
}