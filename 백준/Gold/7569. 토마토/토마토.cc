#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Direction
{
	int nd;
	int md;
	int hd;
};

Direction d[6] = {
	{-1,0,0},
	{1,0,0},
	{0,-1,0},
	{0,1,0},
	{0,0,-1},
	{0,0,1}
};

void getInput(vector<vector<vector<int>>>& v, int& n, int& m, int& h)
{
	cin >> n >> m >> h;

	int temp;
	vector<int> temp_vec1;
	vector<vector<int>> temp_vec2;

	for (int i=0; i < h; i++)
	{
		for (int j=0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> temp;
				temp_vec1.push_back(temp);
			}
			temp_vec2.push_back(temp_vec1);
			temp_vec1.clear();
		}
		v.push_back(temp_vec2);
		temp_vec2.clear();
	}
}

int checkTomato(vector<vector<vector<int>>> v, int n, int m, int h) // return 0 == 다 익음, 1 == 안 익은게 있음, -1 == 다 못익음
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (v[i][j][k] == 0)
				{// 안익은 토마토가 있음
					return -1;
				}
			}
		}
	}
	return 0;
}

void printV(vector<vector<vector<int>>> v, int n, int m, int h)
{
	cout << "\n";

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cout << v[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

int BFS(vector<vector<vector<int>>> &v, int n, int m, int h)
{
	int count = 0;
	Direction cur;
	queue<Direction> q;
	queue<Direction> nextQ;
	
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (v[i][j][k] == 1)
				{
					nextQ.push({ k,j,i });
				}
			}
		}
	}

	while (!nextQ.empty())
	{

		q = nextQ;
		nextQ = queue<Direction>();

		while (!q.empty())
		{
			cur = q.front();
			q.pop();

			for (int l = 0; l < 6; l++)
			{
				int i = cur.hd + d[l].hd;
				int j = cur.md + d[l].md;
				int k = cur.nd + d[l].nd;
				if ( //토마토 사방 확인
					i >= 0 && i < h &&
					j >= 0 && j < m &&
					k >= 0 && k < n &&
					v[i][j][k] == 0 &&
					v[i][j][k] != -1)
				{
					v[i][j][k] = 1;
					nextQ.push({ k,j,i });
				}
			}
		}
		count++;

		//printV(v, n, m, h);
	}

	return count - 1;
}

int main()
{
	vector<vector<vector<int>>> v;
	int n, m, h;

	getInput(v, n, m, h);
	int count = BFS(v, n, m, h);

	if (checkTomato(v, n, m, h) == -1)
	{
		cout << -1;
	}
	else
	{
		cout << count;
	}
}