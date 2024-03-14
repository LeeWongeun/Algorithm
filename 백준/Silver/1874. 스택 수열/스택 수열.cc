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
	vector<char> vec;

	int n;
	cin >> n;
	vector<int> str(n);
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}

	int j = 0;
	int i = 0;
	while (1)
	{
		i++;
		while (!s.empty() && s.top() == str[j])
		{
			s.pop();
			vec.push_back('-');
			vec.push_back('\n');
			j++;
		}

		if (i > n) break;

		s.push(i);
		vec.push_back('+');
		vec.push_back('\n');
	}

	if (!s.empty())
	{
		cout << "NO";
		return 0;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
	}
}