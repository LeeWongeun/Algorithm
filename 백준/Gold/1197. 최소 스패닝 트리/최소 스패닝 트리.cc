#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> u;

int find(int a)
{
	if (a == u[a]) return a;

	return find(u[a]);
}

void unionFunc(int a, int b)
{
	int rootA = find(a);
	int rootB = find(b);

	u[rootB] = rootA;
}

int main()
{
	int answer = 0;
	int cnt = 0;
	int v, e;
	cin >> v >> e;

	vector<vector<int>> edges;
	for (int i = 0; i < e; i++)
	{
		int s, e, cost;
		cin >> s >> e >> cost;
		edges.push_back({ cost,s,e });
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i <= v; i++)
	{
		u.push_back(i);
	}

	for (int i = 0; i < e; i++)
	{
		if (find(edges[i][1]) == find(edges[i][2])) continue;

		cnt++;
		answer += edges[i][0];
		unionFunc(edges[i][1], edges[i][2]);
		if (cnt == v - 1) break;
	}

	cout << answer;
	return 0;
}