#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int BFS(int start);

vector<vector<int>> g;
vector<int> isVisited;
vector<int> result;
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	g.resize(n + 1);
	result = vector<int>(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[b].push_back(a);
	}

	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		isVisited = vector<int>(n + 1, 0);
		if (isVisited[i] == 0)
		{
			int num = BFS(i);
			if (num > max)
			{
				max = num;
			}
			result[i] = num;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (result[i] == max)
		{
			cout << i << ' ';
		}
	}
}

int BFS(int start)
{
	queue<int> q;
	int cur;
	isVisited[start] = 1;
	q.push(start);

	int cnt = 0;
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
				isVisited[next] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}