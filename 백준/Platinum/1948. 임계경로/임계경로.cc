#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void topologySort();
void findRoad();

int n, m;
int S, E;
int critialRoad = 0;

vector <vector<pair<int, int>>> g;
vector<vector<pair<int, int>>> rev;
vector<int> in;
vector<int> criticalCost;
vector<int> isVisited;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	g.resize(n + 1);
	rev.resize(n + 1);
	in = vector<int>(n + 1, 0);
	criticalCost = vector<int>(n + 1);
	isVisited = vector<int>(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({ b,c });
		rev[b].push_back({ a,c });

		in[b]++;
	}

	cin >> S >> E;

	topologySort();
	findRoad();

	cout << criticalCost[E] << '\n' << critialRoad << '\n';
}

void topologySort()
{
	queue<int> q;
	q.push(S);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < g[cur].size(); i++)
		{
			pair<int, int> road = g[cur][i];
			in[road.first]--;

			criticalCost[road.first] = max(criticalCost[road.first], criticalCost[cur] + road.second);

			if (in[road.first] == 0)
			{
				q.push(road.first);
			}
		}
	}
}

void findRoad()
{
	queue<int> q;
	q.push(E);
	isVisited[E] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < rev[cur].size(); i++)
		{
			pair<int, int> road = rev[cur][i];

			if (criticalCost[cur] == criticalCost[road.first] + road.second)
			{
				critialRoad++;
				
				if (isVisited[road.first] == 0)
				{
					q.push(road.first);
					isVisited[road.first] = 1;
				}
			}
		}
	}

}