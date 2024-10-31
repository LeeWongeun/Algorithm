#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;
vector<int> visited;
vector<int> vec;

void BFS(int start, int end)
{
	int cnt = 0;
	queue<int> q;
	q.push(start);
	vec[start] = 0;
	visited[start] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur + U <= F && visited[cur + U] == 0)
		{
			visited[cur + U] = 1;
			vec[cur + U] = vec[cur]+1;
			q.push(cur + U);
		}

		if (cur - D > 0 && visited[cur - D] == 0)
		{
			visited[cur - D] = 1;
			vec[cur - D] = vec[cur] + 1;
			q.push(cur - D);
		}

		if (visited[G] == 1) return;
	}
}

int main()
{
	cin >> F >> S >> G >> U >> D;

	vec.resize(F + 1, -1);
	visited.resize(F + 1, 0);

	BFS(S, G);

	if (S == G) cout << 0;
	else if (vec[G] == -1) cout << "use the stairs";
	else cout << vec[G];
}