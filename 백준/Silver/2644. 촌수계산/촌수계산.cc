#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
	int value;
	int visit = 0;
};
void getInput(vector<vector<node>>& v, int &a, int &b)
{
	int m;
	node n1, n2;

	cin >> a >> b;

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> n1.value >> n2.value;
		v[n1.value].push_back(n2);
		v[n2.value].push_back(n1);
	}
}

int BFS(vector<vector<node>> v, int n, int a, int b)
{
	int cur;
	int count = 0;
	queue<int> q;
	queue<int> nextQ;
	nextQ.push(a);

	while (!nextQ.empty())
	{
		q = nextQ;
		nextQ = queue<int>();
		while (!q.empty())
		{
			cur = q.front();
			q.pop();

			for (int i=0; i < v[cur].size(); i++)
			{
				if (v[cur][i].visit == 0)
				{
					nextQ.push(v[cur][i].value);
					v[cur][i].visit = 1;
				}
				if (v[cur][i].value == b)
				{
					return ++count;
				}
			}
		}
		count++;
	}

	return -1;
}

int main()
{
	int n;
	int a, b;
	cin >> n;
	vector<vector<node>> v(n+1);

	getInput(v, a, b);
	cout << BFS(v, n, a, b);
}