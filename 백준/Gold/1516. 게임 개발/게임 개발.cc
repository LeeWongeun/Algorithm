#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void topologySort();

int n;
vector<vector<int>> vec;
vector<int> inDegree;
vector<int> result;
vector<int> cost;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vec.resize(n + 1);
	inDegree.resize(n + 1, 0);
	cost.resize(n + 1);
	result = vector<int>(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
		int node = 0;
		while (1)
		{
			cin >> node;
			if (node == -1)
			{
				break;
			}
			else
			{
				vec[node].push_back(i);
				inDegree[i]++;
			}
		}
	}

	topologySort();

	for (int i = 1; i < n + 1; i++)
	{
		cout << result[i] << '\n';
	}

}

void topologySort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
			result[i] = cost[i];
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < vec[cur].size(); i++)
		{
			inDegree[vec[cur][i]]--;
			if (result[vec[cur][i]] < result[cur] + cost[vec[cur][i]])
			{
				result[vec[cur][i]] = result[cur] + cost[vec[cur][i]];
			}
			if (inDegree[vec[cur][i]] == 0)
			{
				q.push(vec[cur][i]);
			}
		}
	}
}