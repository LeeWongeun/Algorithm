#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <sstream>

using namespace std;

deque<int> tokenize(string ori, string delim)
{
	deque<int> res;
	vector<int> idx;
	idx.push_back(-1);

	for (int i = 0; i < ori.size(); i++)
	{
		for (int j = 0; j < delim.size(); j++)
		{
			if (delim[j] == ori[i])
			{
				idx.push_back(i);
			}
		}
	}
	idx.push_back(ori.size());

	for (int i = 1; i < idx.size(); i++)
	{
		int start = idx[i - 1] + 1;
		int end = idx[i];
		if (start >= end)
		{
			continue;
		}
		res.push_back(stoi(ori.substr(start, end - start)));
	}

	return res;
}

void printDq(deque<int> dq, int R)
{
	stringstream res;

	res << '[';
	for (int i = 0; i < dq.size(); i++)
	{
		if (R == 0) res << dq[i];
		else res << dq[dq.size()-1 - i];

		if (i != dq.size() - 1) res << ',';
	}
	res << ']';

	cout << res.str() << "\n";
}

void AC(deque<int> dq, string command)
{
	int R = 0;
	for (int j = 0; j < command.size(); j++)
	{
		if (command[j] == 'R')
		{
			if (R == 0) R = 1;
			else R = 0;
		}
		else
		{
			if (!dq.empty())
			{
				if (R == 0)
				{
					dq.pop_front();
				}
				else
				{
					dq.pop_back();
				}
			}
			else
			{
				cout << "error" << "\n";
				return;
			}
		}
	}
	printDq(dq, R);
}

int main()
{
	string arr;
	string command;
	deque<int> dq;
	int T;
	int n;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> command >> n >> arr;
		dq = tokenize(arr, "[],");
		AC(dq, command);
	}
}