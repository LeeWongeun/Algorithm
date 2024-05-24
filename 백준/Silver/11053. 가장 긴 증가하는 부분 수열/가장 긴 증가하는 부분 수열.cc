#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<int> vec(n);
	vector<int> D(n, 1);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	
	for (int i = 1; i < n; i++)
	{
		for (int j = i-1; j >= 0; j--)
		{
			if (vec[i] > vec[j] && D[i] <= D[j])
			{
				D[i] = D[j] + 1;
			}
		}
	}

	cout << *max_element(D.begin(), D.end());
}