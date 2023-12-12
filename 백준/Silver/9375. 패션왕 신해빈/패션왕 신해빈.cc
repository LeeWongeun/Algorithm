#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int m;
		int ans=1;
		string category, item;
		map<string, vector<string>> map;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> item >> category;
			auto iter = map.find(category);
			if (iter != map.end())
			{
				iter->second.push_back(item);
			}
			else
			{
				vector<string> temp;
				temp.push_back(item);
				map.insert({ category,temp });
			}
		}
		for (auto iter = map.begin(); iter != map.end(); iter++)
		{
			ans *= iter->second.size() + 1;
		}
		cout << ans-1 << '\n';
	}
}