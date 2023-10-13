#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int temp;
	vector<int> inputV;
	vector<int> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		inputV.push_back(temp);
	}
	v = inputV;
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++)
	{
		cout << lower_bound(v.begin(), v.end(), inputV[i]) - v.begin() << " ";
	}
}