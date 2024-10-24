#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
	string str1, str2;

	cin >> str1 >> str2;

	str1 = '0' + str1;
	str2 = '0' + str2;

	vector<vector<int>> lcs(str1.length(), vector<int>(str2.length(), 0));

	for (int i = 1; i < str1.length(); i++)
	{
		for (int j = 1; j < str2.length(); j++)
		{
			if (str1[i] == str2[j])
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else
			{
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
			}
		}
	}

	cout << lcs.back().back();
}