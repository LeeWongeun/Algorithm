#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS();

int arr[3];
int isVisited[201][201];
int send[6] = { 0,0,1,1,2,2 };
int receive[6] = { 1,2,0,2,0,1 };
int result[201];

int main()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> arr[i];
	}
	BFS();
	for (int i = 0; i < 201; i++)
	{
		if (result[i])
		{
			cout << i << ' ';
		}
	}
}

void BFS()
{
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	pair<int, int> cur;
	isVisited[0][0] = 1;
	result[arr[2]] = 1;

	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		int A = cur.first;
		int B = cur.second;
		int C = arr[2] - A - B;
		for (int i = 0; i < 6; i++)
		{
			int next[] = { A,B,C };

			next[receive[i]] += next[send[i]];
			if (next[receive[i]] > arr[receive[i]])
			{
				next[send[i]] = next[receive[i]] - arr[receive[i]];
				next[receive[i]] = arr[receive[i]];
			}
			else
			{
				next[send[i]] = 0;
			}

			if (isVisited[next[0]][next[1]] == 0)
			{
				isVisited[next[0]][next[1]] = 1;
				q.push({ next[0],next[1] });
				if (next[0] == 0)
				{
					result[next[2]] = 1;
				}
			}
		}
	}
}