#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
	int visited = 0;
	vector<int> connected;
};

void getInput(int& n, int& m, vector<node>& graph)
{
	int a, b;
	cin >> n >> m;
	graph.resize(n);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[a - 1].connected.push_back(b - 1);
		graph[b - 1].connected.push_back(a - 1);
	}
}

void BFS(int n, vector<node>& graph, int &cnt)
{
	queue<int> q;
	int current;

	q.push(n);
	
	while (!q.empty())
	{
		current = q.front();
		q.pop();

		for (int i = 0; i < graph[current].connected.size(); i++)
		{
			if (graph[graph[current].connected[i]].visited == 0)
			{
				q.push(graph[current].connected[i]);
				graph[graph[current].connected[i]].visited = 1;
			}
		}
	}

	cnt++;
}

int countConnectedComponent(vector<node> graph)
{
	int cnt = 0;

	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[i].visited == 0)
		{
			BFS(i, graph, cnt);
		}
	}

	return cnt;
}

int main()
{
	int n, m, cnt;
	vector<node> graph;

	getInput(n, m, graph);
	cnt = countConnectedComponent(graph);

	cout << cnt;
}