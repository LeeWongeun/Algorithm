#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*
	0,0부터 m,n까지 하나씩 탐색, 만약 번지 수가 안붙어 있다면 bfs로 단지 번호 붙이고 단지 몇개인지 저장.
*/

using namespace std;

struct node {
	int house;
	int complex = -1;
};

struct rowCol
{
	int row;
	int col;
};

void getInput(int& n, vector<vector<node>>& vec)
{
	char chTemp;
	node nodeTemp;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		vector<node> vecTemp;
		for (int j = 0; j < n; j++)
		{
			cin >> chTemp;
			nodeTemp.house = chTemp;
			vecTemp.push_back(nodeTemp);
		}
		vec.push_back(vecTemp);
	}
}

int BFS(int n, vector<vector<node>>& vec, int startRow, int startCol, int currentComplex)
{
	queue<rowCol> q;
	rowCol direction[4] = { { 1,0 }, { -1,0 }, { 0,1 }, { 0,-1 } }; // up, down, right, left
	rowCol current;
	int count = 1;

	q.push({ startRow,startCol });
	vec[startRow][startCol].complex = currentComplex;

	while (!q.empty())
	{
		current = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			rowCol temp = { current.row + direction[i].row, current.col + direction[i].col };
			if (temp.row >= 0 && temp.row < n && temp.col >= 0 && temp.col < n && vec[temp.row][temp.col].house == 49 && vec[temp.row][temp.col].complex == -1)
			{
				q.push({ temp.row, temp.col });
				vec[temp.row][temp.col].complex = currentComplex;
				count++;
			}
		}
	}

	return count;
}

vector<int> processingComplex(int n, vector<vector<node>>& vec)
{
	int currentComplex = 1;
	vector<int> ans;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vec[i][j].complex == -1 && vec[i][j].house == 49)
			{
				ans.push_back(BFS(n, vec, i, j, currentComplex));
				currentComplex++;
			}
		}
	}
	return ans;
}

void printAns(vector<int> ans)
{
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}

int main()
{
	int n;
	vector<vector<node>> vec;
	vector<int> ans;

	getInput(n, vec);
	ans = processingComplex(n, vec);
	printAns(ans);
}