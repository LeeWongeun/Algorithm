#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int BFS(int start);

vector<vector<int>> g;
vector<int> isVisited;
int n, m;
int testcase;
int result = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> testcase;
	for (int t = 0; t < testcase; t++)
	{
		cin >> n >> m;
		g = vector<vector<int>>(n + 1);
		isVisited = vector<int>(n + 1, 0);

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		result = 1;
		for (int i = 1; i <= n; i++)
		{
			if (isVisited[i]==0 && BFS(i) == 0)
			{
				result = 0;
				break;
			}
		}

		if (result)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}

int BFS(int start)
{
	queue<int> q;
	q.push(start);
	int cur = start;
	isVisited[start] = 1;

	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		for (int i = 0; i < g[cur].size(); i++)
		{
			int next = g[cur][i];
			if (isVisited[next] == 0)
			{
				q.push(next);
				isVisited[next] = isVisited[cur] * -1;
			}
			else if (isVisited[next] == isVisited[cur])
			{
				return 0;
			}
		}
	}
	return 1;
}