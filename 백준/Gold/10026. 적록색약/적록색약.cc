#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
	char color;
	int visit = 0;
};
struct rowcol {
	int row;
	int col;
};
vector<vector<node>> v;
int n;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<node> tempVec;
		for (int j = 0; j < n; j++)
		{
			node tempNode;
			cin >> tempNode.color;
			tempVec.push_back(tempNode);
		}
		v.push_back(tempVec);
	}
}

void BFS(int startRow, int startCol, char color)
{
	rowcol cur;
	queue<rowcol> q;
	q.push({ startRow,startCol });
	
	while (!q.empty())
	{
		rowcol direction[4] = { {0,1},{0,-1},{1,0},{-1,0} };
		cur = q.front();
		q.pop();
		v[cur.row][cur.col].visit = 1;
		for (int i = 0; i < 4; i++)
		{
			int row = cur.row + direction[i].row;
			int col = cur.col + direction[i].col;
			if (row >= 0 && row < n && col >= 0 && col < n && v[row][col].color == color && v[row][col].visit == 0)
			{
				q.push({ row,col });
				v[row][col].visit = 1;
			}
		}
	}
}

void BFS_blind(int startRow, int startCol, char color)
{
	rowcol cur;
	queue<rowcol> q;
	q.push({ startRow,startCol });

	while (!q.empty())
	{
		rowcol direction[4] = { {0,1},{0,-1},{1,0},{-1,0} };
		cur = q.front();
		q.pop();
		v[cur.row][cur.col].visit = 0;
		for (int i = 0; i < 4; i++)
		{
			int row = cur.row + direction[i].row;
			int col = cur.col + direction[i].col;

			if (row >= 0 && row < n && col >= 0 && col < n && v[row][col].visit == 1)
			{
				char curColor = v[row][col].color;
				if ((color == 'R' || color == 'G') && (curColor == 'R' || curColor == 'G'))
				{
					q.push({ row,col });
					v[row][col].visit = 0;
				}
				else if (color=='B')
				{
					if (curColor == color)
					{
						q.push({ row,col });
						v[row][col].visit = 0;
					}
				}
			}
		}
	}
}

void solve()
{
	int normal = 0;
	int blind = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j].visit == 0)
			{
				BFS(i, j, v[i][j].color);
				normal++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j].visit == 1)
			{
				BFS_blind(i, j, v[i][j].color);
				blind++;
			}
		}
	}
	cout << normal << '\n' << blind;
}

int main()
{
	input();
	solve();
}