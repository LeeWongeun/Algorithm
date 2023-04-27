#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str, buf;
	while (1)
	{
		cin >> str;
		if (str == "0")
		{
			break;
		}
		buf = str;
		reverse(buf.begin(), buf.end());
		if (buf == str)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
}