#include <iostream>
#include <map>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	map<string, string> map;

	int n, m;

	cin >> n >> m;

	for (int i=0; i < n; i++)
	{
		string url;
		string pwd;
		cin >> url >> pwd;

		map.insert({ url,pwd });
	}

	for (int i=0; i < m; i++)
	{
		string url;
		cin >> url;
		cout << map.find(url)->second << '\n';
	}
}