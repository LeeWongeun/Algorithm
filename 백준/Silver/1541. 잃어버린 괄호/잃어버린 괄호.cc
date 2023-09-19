#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;

int main()
{
	string input;
	vector<string> parse_1;
	vector<vector<int>> parse_2;
	vector<int> vec;
	int ans = 0;

	cin >> input;

	istringstream iss;
	string str_buf;
	iss.str(input);

	while (getline(iss, str_buf, '-'))
	{
		parse_1.push_back(str_buf);
	}

	
	for (int i = 0; i < parse_1.size(); i++)
	{
		istringstream iss(parse_1[i]);
		vector<int> vec_buf;
		while (getline(iss, str_buf, '+'))
		{
			vec_buf.push_back(stoi(str_buf));
		}
		parse_2.push_back(vec_buf);
	}

	for (int i = 0; i < parse_2.size(); i++)
	{
		if (i == 0)
		{
			ans = accumulate(parse_2[i].begin(), parse_2[i].end(), 0);
		}
		else
		{
			ans -= accumulate(parse_2[i].begin(), parse_2[i].end(), 0);
		}
	}

	cout << ans;
}