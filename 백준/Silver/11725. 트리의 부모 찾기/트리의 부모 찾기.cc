#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> answer;
vector<vector<int>> edges;

void dfs(int parent, int cur, vector<int>& visited)
{
	visited[cur] = 1;
	answer[cur] = parent;

	for (int i = 0; i < edges[cur].size(); i++)
	{
		if (visited[edges[cur][i]] == 1) continue;
		dfs(cur, edges[cur][i], visited);
	}
}

int main()
{
	int n;
	cin >> n;
	edges.resize(n+1);
	answer.resize(n + 1);
	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	vector<int> visited(n + 1, 0);
	dfs(0, 1, visited);

	for (int i = 2; i <= n; i++)
	{
		cout << answer[i] << '\n';
	}
}