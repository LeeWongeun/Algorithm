#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int arr[100001];
	arr[0] = 0;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		arr[i] = arr[i - 1] + temp;
	}

	for (int i=0; i < m; i++)
	{
		int begin, end;
		cin >> begin >> end;
		cout << arr[end] - arr[begin - 1] << '\n';
	}
}