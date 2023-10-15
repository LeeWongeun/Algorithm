#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
	int value;
	int dist = -1;
};

struct xy
{
	int row;
	int col;
};

vector<vector<node>> v;
int n, m;
int startRow, startCol;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		node temp;
		vector<node> tempVec;
		for (int j = 0; j < m; j++)
		{
			cin >> temp.value;
			if (temp.value == 2)
			{
				startRow = i;
				startCol = j;
			}
			tempVec.push_back(temp);
			if (temp.value == 0)
			{
				tempVec[j].dist = 0;
			}
		}
		v.push_back(tempVec);
	}

}

void BFS()
{
	queue<xy> q, nextQ;
	xy cur;
	xy direction[4] = { {1,0},{-1,0},{0,1},{0,-1} };
	int dist = 1;

	v[startRow][startCol].dist = 0;
	nextQ.push({ startRow, startCol });

	while (!nextQ.empty())
	{
		q = nextQ;
		nextQ = queue<xy>();
		while (!q.empty())
		{
			cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int row = cur.row + direction[i].row;
				int col = cur.col + direction[i].col;
				if (row >= 0 && row < n && col>=0 && col < m && v[row][col].dist==-1)
				{
					if (v[row][col].value == 1)
					{
						v[row][col].dist = dist;
						nextQ.push({ row,col });
					}
					else if(v[row][col].value == 0)
					{
						v[row][col].dist = 0;
					}
				}
			}
		}
		dist++;
	}
}

void printMaze()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << v[i][j].dist <<" ";
		}
		cout << "\n";
	}
}

int main()
{
	input();
	BFS();
	printMaze();
}