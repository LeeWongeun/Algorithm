#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> d;

void bfs(int start)
{
	deque<int> dq;
	dq.push_back(start);

	while (!dq.empty())
	{
		int cur = dq.front();
		dq.pop_front();

		if (cur * 2 <= 200000 && d[cur] < d[cur * 2])
		{
			d[cur * 2] = d[cur];
			dq.push_front(cur*2);
		}
		if (cur + 1 <= 200000 && d[cur] + 1 < d[cur + 1])
		{
			d[cur + 1] = d[cur] + 1;
			dq.push_back(cur + 1);
		}
		if (cur - 1 >= 0 && d[cur] + 1 < d[cur - 1])
		{
			d[cur - 1] = d[cur] + 1;
			dq.push_back(cur - 1);
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	d.resize(200001, 1e9);
	d[n] = 0;
	
	bfs(n);

	cout << d[k];
}