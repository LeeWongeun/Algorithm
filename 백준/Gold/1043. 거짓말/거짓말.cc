#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void unionFunc(int a, int b);
int find(int a);
int checkParty();

int partyPeople[51][51];
int truthPeople[51];
int unionArr[51];
int peopleNum[51];

int n, m, t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> truthPeople[i];
	}
	for (int i = 0; i < 51; i++)
	{
		unionArr[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> peopleNum[i];
		for (int j = 0; j < peopleNum[i]; j++)
		{
			cin >> partyPeople[i][j];
		}
		for (int j = 1; j < peopleNum[i]; j++)
		{
			unionFunc(partyPeople[i][j - 1], partyPeople[i][j]);
		}
	}

	cout << checkParty();
}

void unionFunc(int a, int b)
{
	if (a != b)
	{
		unionArr[find(b)] = unionArr[find(a)];
	}
}

int find(int a)
{
	if (unionArr[a] == a)
	{
		return a;
	}
	else
	{
		return unionArr[a] = find(unionArr[a]);
	}
}

int checkParty()
{
	int cnt = 0;
	int flag = 0;
	vector<int> truthRoot(t);

	for (int i=0; i < t; i++)
	{
		truthRoot[i] = find(truthPeople[i]);
	}
	for (int i = 0; i < m; i++)
	{
		flag = 0;
		for (int j = 0; j < peopleNum[i]; j++)
		{
			int root = find(partyPeople[i][j]);
			for (int k = 0; k < t; k++)
			{
				if (root == truthRoot[k])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}

		if (flag == 0)
		{
			cnt++;
		}
	}

	return cnt;
}