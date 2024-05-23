#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[10] = { 0 };
bool isVisited[10] = { 0 };

void dfs(int num, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; i++)
	{
		if (!isVisited[i])
		{
			isVisited[i] = true;
			arr[cnt] = i;
			dfs(i + 1, cnt + 1);
			isVisited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	dfs(1, 0);
}