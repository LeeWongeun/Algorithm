#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int m, n;
	int cnt1 = 0, cnt2 = 0, ans=64, a;
	char input[50][50] = {};
	char chessboard1[8][8] = {  'B','W','B','W', 'B','W', 'B','W' ,
								'W','B','W', 'B','W', 'B','W', 'B',
								'B','W','B','W', 'B','W', 'B','W' ,
								'W','B','W', 'B','W', 'B','W', 'B',
								'B','W','B','W', 'B','W', 'B','W' ,
								'W','B','W', 'B','W', 'B','W', 'B',
								'B','W','B','W', 'B','W', 'B','W' ,
								'W','B','W', 'B','W', 'B','W', 'B'
							};
	char chessboard2[8][8] = {  'W','B','W', 'B','W', 'B','W', 'B' ,
								'B','W','B','W', 'B','W', 'B', 'W' ,
								'W','B','W', 'B','W', 'B','W', 'B' ,
								'B','W','B','W', 'B','W', 'B', 'W' ,
								'W','B','W', 'B','W', 'B','W', 'B' ,
								'B','W','B','W', 'B','W', 'B', 'W' ,
								'W','B','W', 'B','W', 'B','W', 'B' ,
								'B','W','B','W', 'B','W', 'B', 'W'
	};

	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> input[i][j];
		}
	}
	
	for (int i = 0; i <= m-8; i++)
	{
		for (int j = 0; j <= n-8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				for (int l = 0; l < 8; l++)
				{
					if (input[i + k][j + l] != chessboard1[k][l])
					{
						cnt1++;
					}
					if (input[i + k][j + l] != chessboard2[k][l])
					{
						cnt2++;
					}
				}
			}
			a = (cnt1 < cnt2) ? cnt1 : cnt2;
			if (ans > a) {
				ans = a;
			}
			cnt1 = 0;
			cnt2 = 0;
		}
	}
	cout << ans;
}