#include <iostream>

using namespace std;

void getInput(int (&arr)[10], int n);
int calcCoin(int arr[], int n, int k);


int main()
{
	int n, k, ans;
	int arr[10];
	cin >> n >> k;

	getInput(arr,n);
	ans = calcCoin(arr, n, k);

	cout << ans;
}

void getInput(int(&arr)[10], int n)
{
	for (int i=0; i < n; i++)
	{
		cin >> arr[i];
	}
}

int calcCoin(int arr[], int n, int k)
{
	int cnt = 0;
	
	for (int i = n-1; i >= 0; i--)
	{
		cnt = cnt + (k / arr[i]);
		k = k - (arr[i] * (k / arr[i]));
		if (k <= 0)
		{
			break;
		}
	}
	return cnt;
}