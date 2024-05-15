#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int sRow, int sCol);
void GetEdges();
void SetLandNum();

int MST();
int find(int num);
void unionFunc(int a, int b);

struct node
{
	bool bIsLand;
	int LandNum = -1;
};
struct edge
{
	int s;
	int e;
	int cost;

	bool operator > (const edge& temp) const
	{
		return cost > temp.cost;
	}
};

int n, m;
int LandCnt = 1;
priority_queue<edge,vector<edge>,greater<edge>> edges, start, end;
vector<vector<node>> g;
vector<vector<bool>> bIsVisted;
vector<int> unionVec;

int dRow[4] = { 1,-1,0,0 };
int dCol[4] = { 0,0,1,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	bIsVisted = vector<vector<bool>>(n + 1, vector<bool>(m + 1));
	g = vector<vector<node>>(n + 1, vector<node>(m + 1));
	for (int i = 1; i <= n; i++)
	{
		node v;
		for (int j = 1; j <= m; j++)
		{
			cin >> v.bIsLand;
			g[i][j] = v;
		}
	}

	SetLandNum();
	GetEdges();
	
	unionVec = vector<int>(LandCnt + 1, 0);
	for (int i = 1; i < LandCnt + 1; i++)
	{
		unionVec[i] = i;
	}

	cout << MST();
}

int MST()
{
	int usedEdge = 0;
	int result = 0;

	while (!edges.empty())
	{
		edge cur = edges.top();
		edges.pop();

		if (find(cur.s) != find(cur.e))
		{
			unionFunc(cur.s, cur.e);
			result += cur.cost;
			usedEdge++;
		}

		if (usedEdge == LandCnt-1)
		{
			return result;
		}
	}

	return -1;
}

void unionFunc(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
	{
		unionVec[b] = a;
	}
}

int find(int num)
{
	if (unionVec[num] == num)
	{
		return num;
	}
	
	return unionVec[num] = find(unionVec[num]);
}

void SetLandNum()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (bIsVisted[i][j] == 0 && g[i][j].bIsLand)
			{
				BFS(i, j);
			}
		}
	}
	LandCnt--;
}

void GetEdges()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (g[i][j].LandNum == -1)
			{
				continue;
			}

			int row = i;
			int col = j - 1;
			for (; col > 0; --col)
			{
				if (g[row][col].LandNum == g[i][j].LandNum)
				{
					break;
				}
				else if (g[row][col].LandNum != -1)
				{
					if (j - col - 1 == 1)
					{
						break;
					}
					edges.push({ g[i][j].LandNum,g[row][col].LandNum, j - col - 1 });
					break;
				}
			}

			row = i - 1;
			col = j;
			for (; row > 0; --row)
			{
				if (g[row][col].LandNum == g[i][j].LandNum)
				{
					break;
				}
				else if (g[row][col].LandNum != -1)
				{
					if (i - row - 1 == 1)
					{
						break;
					}
					edges.push({ g[i][j].LandNum,g[row][col].LandNum, i - row - 1 });
					break;
				}
			}
		}
	}
}
void BFS(int sRow, int sCol)
{
	queue<pair<int, int>> q;
	q.push({ sRow, sCol });
	bIsVisted[sRow][sCol] = 1;
	g[sRow][sCol].LandNum = LandCnt;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nextRow = cur.first + dRow[i];
			int nextCol = cur.second + dCol[i];
			if (nextRow > 0 && nextRow <= n && nextCol > 0 && nextCol <= m)
			{
				if (bIsVisted[nextRow][nextCol] == 0 && g[nextRow][nextCol].bIsLand == 1)
				{
					g[nextRow][nextCol].LandNum = LandCnt;
					q.push({nextRow,nextCol});
					bIsVisted[nextRow][nextCol] = 1;
				}
			}
		}
	}

	LandCnt++;
}