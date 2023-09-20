#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector<int> vec(3);
	vec[0] = 0;
	vec[1] = 1;
	vec[2] = 3;

	cin >> n;

	for (int i = 3; i <= n; i++)
	{
		vec.push_back(((2 * vec[i - 2]) + vec[i - 1]) % 10007);
	}

	cout << vec[n];
}