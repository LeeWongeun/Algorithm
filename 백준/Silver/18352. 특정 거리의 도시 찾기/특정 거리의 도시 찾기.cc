#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(int start);

vector<vector<int>> g;
vector<int> isVisited;
int n, e, x, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> e >> k >> x;
	g.resize(n+1);
	isVisited = vector<int>(n+1, 0);
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}

	BFS(x);
}

void BFS(int start)
{
	vector<int> result;
	queue<int> q;
	q.push(start);

	int cur = start;
	isVisited[cur] = 1;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		for (int i=0;i<g[cur].size();i++)
		{
			int next = g[cur][i];
			if (isVisited[next] == 0)
			{
				q.push(next);
				isVisited[next] = isVisited[cur] + 1;
				if (isVisited[next] == k+1)
				{
					result.push_back(next);
				}
			}
		}
	}
	
	if (result.size() == 0)
	{
		cout << "-1";
	}
	else
	{
		sort(result.begin(), result.end());
		for (int i : result)
		{
			cout << i << '\n';
		}
	}
}