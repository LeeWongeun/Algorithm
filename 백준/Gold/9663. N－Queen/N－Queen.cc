#include <iostream>

using namespace std;

int answer = 0;
int vec[15];

bool checkCanAttack(int depth)
{
	if (depth < 1) return false;

	for (int i = 0; i < depth; i++)
	{
		if ((abs(i - (depth)) == abs(vec[i] - vec[depth])) || vec[i] == vec[depth])
		{
			return true;
		}
	}

	return false;
}

void backTracking(int n, int depth)
{
	if (depth == n)
	{
		answer++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		vec[depth] = i;
		if (!checkCanAttack(depth))
		{
			backTracking(n, depth + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	backTracking(n, 0);

	cout << answer;
}