#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		int maxIndex = i;
		for (int j = i; j < str.size(); j++)
		{
			if (str[maxIndex] < str[j])
			{
				maxIndex = j;
			}
		}
		int temp = str[maxIndex];
		str[maxIndex] = str[i];
		str[i] = temp;
	}
	cout << str;
}