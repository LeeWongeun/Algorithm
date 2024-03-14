#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

struct node {
	int index;
	int number;
};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	deque<node> dq;

	int n, l;
	cin >> n >> l;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	dq.push_back({ 0,vec[0] });
	cout << dq[0].number << ' ';

	for (int i = 1; i < n; i++)
	{
		while (dq.size() != 0 && dq.back().number > vec[i])
		{
			dq.pop_back();
		}

		if (dq.size() != 0 && dq.front().index < i - l + 1)
		{
			dq.pop_front();
		}

		dq.push_back({ i,vec[i] });

		cout << dq.front().number << ' ';
	}
}