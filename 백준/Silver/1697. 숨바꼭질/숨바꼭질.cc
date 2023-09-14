#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int visited = 0;
	int dist = 0;
};

int BFS(int x, int k)
{
	int vecSize = max(x, k);
	vector<node> vec(100001);
	queue<int> q;
	int current;

	q.push(x);

	vec[x].visited = 1;
	vec[x].dist = 0;
	while (!q.empty())
	{
		current = q.front();
		q.pop();

		int arr[3] = { current * 2, current - 1,current + 1 };
		for (int i = 0; i < 3; i++)
		{
			if (arr[i] >= 0 && arr[i] <= 100000 && vec[arr[i]].visited == 0)
			{
				vec[arr[i]].visited = 1;
				vec[arr[i]].dist = vec[current].dist + 1;

				q.push(arr[i]);
			}

			if (arr[i] == k)
			{
				return vec[arr[i]].dist;
			}
		}
	}
}
int main()
{
	int x, k, ans;
	
	cin >> x >> k;
	ans = BFS(x, k);

	cout << ans;
}