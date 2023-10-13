#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, int> nameM;
	map<int, string> indexM;
	int n, m;
	string tempS;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> tempS;
		nameM.insert({ tempS,i + 1 });
		indexM.insert({ i + 1,tempS });
	}

	for (int i = 0; i < m; i++)
	{
		cin >> tempS;
		if (isdigit(tempS[0]) == 0)
		{
			cout << nameM[tempS] << '\n';
		}
		else
		{
			cout << indexM[stoi(tempS)] << "\n";
		}
	}
}