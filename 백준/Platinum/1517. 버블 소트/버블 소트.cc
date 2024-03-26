#include <iostream>
#include <vector>

using namespace std;

static vector<pair<int,int>> vec;
static vector<pair<int,int>> temp;
static long result = 0;

void mergeSort(int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int m = (start + end) / 2;
	mergeSort(start, m);
	mergeSort(m + 1, end);

	for (int i = start; i <= end; i++)
	{
		temp[i] = vec[i];
	}

	int index1 = start, index2 = m + 1;
	int i = start;
	while (index1 < m + 1 && index2 <= end)
	{
		if (temp[index1] < temp[index2])
		{
			vec[i] = temp[index1++];
		}
		else
		{
			vec[i] = temp[index2];
			result += index2 - i;
			index2++;
		}
		i++;
	}
	while (index1 < m + 1)
	{
		vec[i] = temp[index1++];
		i++;
	}
	while (index2 <= end)
	{
		vec[i] = temp[index2++];
		i++;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vec = vector<pair<int,int>>(n);
	temp = vector<pair<int,int>>(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i].first;
		vec[i].second = i;
	}

	mergeSort(0, n - 1);

	cout << result;
}