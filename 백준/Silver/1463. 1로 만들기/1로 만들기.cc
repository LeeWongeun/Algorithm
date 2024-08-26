#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> vec(n + 1, 1e9);
	vec[0] = 0;
	vec[1] = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		if (i + 1 <= n)
		{
			if (vec[i] + 1 < vec[i + 1])
			{
				vec[i + 1] = vec[i] + 1;
			}
		}

		if (i * 2 <= n)
		{
			if (vec[i] + 1 < vec[i * 2])
			{
				vec[i * 2] = vec[i] + 1;
			}
		}

		if (i * 3 <= n)
		{
			if (vec[i] + 1 < vec[i * 3])
			{
				vec[i * 3] = vec[i] + 1;
			}
		}
	}

	cout << vec[n];
}