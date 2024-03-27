#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void DFS(int start);
void BFS(int start);
void sortGraph();

vector<vector<int>> g;
vector<bool> isVisited;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, start;
	cin >> n >> m >> start;

	g.resize(n+1);
	isVisited = vector<bool>(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	sortGraph();

	DFS(start);
	cout << '\n';
	isVisited = vector<bool>(n + 1, 0);
	BFS(start);
}

void DFS(int start)
{
	if (isVisited[start] == 1)
	{
		return;
	}
	isVisited[start] = 1;
	cout << start << ' ';
	for (int i = 0; i < (int)g[start].size(); i++)
	{
		int next = g[start][i];
		if (isVisited[next] == 0)
		{
			DFS(next);
		}
	}
}

void BFS(int start)
{
	queue<int> q;
	q.push(start);

	int cur;
	isVisited[start] = 1;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		cout << cur << ' ';

		for (int i = 0; i < (int)g[cur].size(); i++)
		{
			int next = g[cur][i];
			if (isVisited[next] == 0)
			{
				q.push(next);
				isVisited[next] = 1;
			}
		}
	}
}

void sortGraph()
{
	for (int i = 0; i < (int)g.size(); i++)
	{
		sort(g[i].begin(), g[i].end());
	}
}