#include <iostream>
#include <vector>

using namespace std;

int white = 0;
int blue = 0;

void getInput(vector<vector<int>>& v, int& n)
{
	int a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> tempVector;
		for (int j = 0; j < n; j++)
		{
			cin >> a;
			tempVector.push_back(a);
		}
		v.push_back(tempVector);
	}
}

void check(vector<vector<int>>& v, int startRow, int startCol, int endRow, int endCol)
{
	int a = v[startRow][startCol];

	//cout << startRow << " " << startCol << '\n' << endRow << " " << endCol << "\n\n";

	for (int i = startRow; i < endRow; i++)
	{
		for (int j = startCol; j < endCol; j++)
		{
			if (a != v[i][j]) // 다 똑같지 않을 때
			{
				check(v, startRow, (startCol + endCol) / 2, (startRow + endRow) / 2, endCol);
				check(v, startRow, startCol, (startRow + endRow) / 2, (startCol + endCol) / 2);
				check(v, (startRow + endRow) / 2, startCol, endRow, (startCol + endCol) / 2);
				check(v, (startRow + endRow) / 2, (startCol + endCol) / 2, endRow, endCol);
				return;
			}
		}
	}
	if (a == 0)
	{
		white++;
	}
	else
	{
		blue++;
	}
}

int main()
{
	vector<vector<int>> v;
	int n;

	getInput(v, n);
	check(v, 0, 0, n, n);

	cout << white << "\n" << blue << "\n";
}