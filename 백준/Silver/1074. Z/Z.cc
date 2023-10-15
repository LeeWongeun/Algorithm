#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void input(int &n, int &r, int &c)
{
	cin >> n >> r >> c;
}
void z(int n, int startRow, int startCol, int &value, int r, int c)
{
	if (n == 1)
	{
		if (startRow == r && startCol == c)
			cout << value + 1;
		else if (startRow == r && startCol+1 == c)
			cout << value + 2;
		else if (startRow+1 == r && startCol == c)
			cout << value + 3;
		else if (startRow+1 == r && startCol+1 == c)
			cout << value + 4;

		value += 4;
		return;
	}
	else
	{
		int half = pow(2,n) / 2;
		int add = pow(2, n * 2) / 4;
		if (r < startRow + half && c < startCol + half)
		{
			z(n-1, startRow, startCol, value, r, c);
			return;
		}
		else if (r < startRow + half && c < startCol + half * 2)
		{
			value += add;
			z(n-1, startRow, startCol + half, value, r, c);
			return;
		}
		else if (r < startRow + half *2 && c < startCol + half)
		{
			value += 2*add;
			z(n-1, startRow + half, startCol, value, r, c);
			return;
		}
		else
		{
			value += 3*add;
			z(n-1, startRow + half, startCol + half, value, r, c);
		}
		return;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n=0;
	int r = 0;
	int c = 0;
	int value = -1;

	input(n,r,c);
	z(n, 0, 0, value, r, c);
}