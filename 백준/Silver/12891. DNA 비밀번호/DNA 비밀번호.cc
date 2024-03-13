#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int check(char c)
{
	if (c == 'A')
	{
		return 0;
	}
	else if (c == 'C')
	{
		return 1;
	}
	else if (c == 'G')
	{
		return 2;
	}
	else if (c == 'T')
	{
		return 3;
	}

}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int s, p;
	int acgt[4];
	cin >> s >> p;

	vector<char> str(s);
	for (int i = 0; i < s; i++)
	{
		cin >> str[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> acgt[i];
	}

	int begin = 0, end = begin + p, result = 0;
	int acgtCnt[4] = { 0 };
	for (int i = begin; i < end; i++)
	{
		acgtCnt[check(str[i])]++;
	}
	for (int j = 0; j < 4; j++)
	{
		if (acgtCnt[j] < acgt[j])
		{
			break;
		}
		else if (j == 3)
		{
			result++;
		}
	}
	while (end < s)
	{
		acgtCnt[check(str[begin])]--;
		begin++;

		acgtCnt[check(str[end])]++;
		end++;
		for (int j = 0; j < 4; j++)
		{
			if (acgtCnt[j] < acgt[j])
			{
				break;
			}
			else if (j == 3)
			{
				result++;
			}
		}
		if (end >= s)
		{
			break;
		}
	}

	cout << result;
}