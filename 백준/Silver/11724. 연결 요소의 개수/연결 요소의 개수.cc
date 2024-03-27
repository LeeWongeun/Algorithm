#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(int start);

vector<vector<int>> g;
vector<bool> isVisited;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n, m;
	cin >> n >> m;
	g = vector<vector<int>>(n + 1);
	isVisited = vector<bool>(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		if (isVisited[i] == false)
		{
			DFS(i);
			result++;
		}
	}

	cout << result;
}

void DFS(int start)
{
	stack<int> s;
	s.push(start);

	int cur;
	while (!s.empty())
	{
		cur = s.top();
		s.pop();
		for (int i = 0; i < g[cur].size(); i++)
		{
			int next = g[cur][i];
			if (isVisited[next] == false)
			{
				s.push(next);
				isVisited[next] = 1;
			}
		}
	}
}