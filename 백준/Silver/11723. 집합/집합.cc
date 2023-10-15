#include <iostream>
#include <set>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, input;
	string s;
	set<int> set;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (!s.compare("add"))
		{
			cin >> input;
			set.insert(input);
		}
		else if (!s.compare("remove"))
		{
			cin >> input;
			if (set.count(input))
				set.erase(set.find(input));
		}
		else if (!s.compare("check"))
		{
			cin >> input;
			cout << set.count(input) << "\n";
		}
		else if (!s.compare("toggle"))
		{
			cin >> input;
			if (set.count(input))
				set.erase(set.find(input));
			else
				set.insert(input);
		}
		else if (!s.compare("all"))
		{
			for (int j = 0; j < 20; j++)
			{
				set.insert(j + 1);
			}
		}
		else if (!s.compare("empty"))
		{
			set.clear();
		}
	}
}