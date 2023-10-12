#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int a, b;
	cin >> n >> m;

	vector<int> sum;
	sum.push_back(0);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if(i == 0)
		{
			sum.push_back(temp);
		}
		else
		{
			sum.push_back(sum[i] + temp);
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		cout<< sum[b]-sum[a-1]<<"\n";
	}
}