#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void getInput(vector<int>(&vertex)[1001], int m);
void DFS(vector<int> vertex[], int start);
void BFS(vector<int> vertex[], int start);

int main()
{
	int n, m, start;
	cin >> n >> m >> start;
	
	vector<int> vertex[1001];

	getInput(vertex, m);

	for (int i = 0; i < n+1; i++)
	{
		sort(vertex[i].begin(), vertex[i].end());
	}

	DFS(vertex, start);
	cout << endl;
	BFS(vertex, start);
}

void getInput(vector<int>(&vertex)[1001], int m)
{
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		vertex[a].push_back(b);
		vertex[b].push_back(a);
	}
}

void DFS(vector<int> vertex[], int start)
{
	stack<int> stack;
	bool isVisited[1001] = { 0 };
	int current = start, next;
	stack.push(current);

	while (!stack.empty())
	{
		current = stack.top();
		stack.pop();

		if (isVisited[current] == false)
		{
			isVisited[current] = true;
			cout << current << " ";
		}

		for (int i = 0; i < (int)(vertex[current].size()); i++)
		{
			next = vertex[current][i];
			if (isVisited[next] == false)
			{
				stack.push(current);
				stack.push(next);
				break;
			}
		}
	}
}

void BFS(vector<int> vertex[], int start)
{
	queue<int> queue;
	bool isVisited[1001] = { 0 };
	int current = start, next;

	queue.push(current);
	cout << current << " ";
	isVisited[current] = true;

	while (!queue.empty())
	{
		current = queue.front();
		queue.pop();
		for (int i = 0; i < (int)(vertex[current].size()); i++)
		{
			next = vertex[current][i];
			if (isVisited[next] == false)
			{
				queue.push(next);
				cout << next << " ";
				isVisited[next] = true;
			}
		}
	}
}