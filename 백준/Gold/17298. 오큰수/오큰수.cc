#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	stack<int> s;

	int n;
	cin >> n;
	vector<int> vec(n);
	vector<int> result(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	s.push(0);
	for (int i = 1; i < n; i++)
	{
		while (!s.empty() && vec[s.top()] < vec[i])
		{
			result[s.top()] = vec[i];
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty())
	{
		result[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++)
	{
		cout << result[i] << " ";
	}
}