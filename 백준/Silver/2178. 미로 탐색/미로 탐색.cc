#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct coordinate
{
	int row, col;
};

void getInput(vector<vector<char>> &vec, int &n, int &m)
{
	char bufChar;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		vector<char> bufVec;
		for (int j = 0; j < m; j++)
		{
			cin >> bufChar;
			bufVec.push_back(bufChar);
		}
		vec.push_back(bufVec);
	}
}

void BFS(vector<vector<char>> vec, int n, int m)
{
	vector<vector<int>> distance(n, vector<int>(m,0));
	distance[0][0] = 1;

	queue<coordinate> q;
	coordinate cur = { 0,0 };
	coordinate direction[4] = { {0,-1},{0,1},{1,0},{-1,0} };

	q.push(cur);

	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			coordinate temp = { cur.row + direction[i].row, cur.col +direction[i].col };
			if (temp.row >= 0 && temp.row < n && temp.col >= 0 && temp.col < m && distance[temp.row][temp.col] == 0 && vec[temp.row][temp.col] == 49)
			{
				q.push(temp);
				distance[temp.row][temp.col] = distance[cur.row][cur.col] + 1;
			}
		}

		if (cur.row == n - 1 && cur.col == m - 1)
		{
			cout << distance[cur.row][cur.col];
			break;
		}
	}
}

int main()
{
	int n, m;
	vector<vector<char>> vec;

	getInput(vec, n, m);
	BFS(vec, n, m);
}