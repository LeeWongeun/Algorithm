#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		pq.push(temp);
	}

	int sum = 0;
	while (pq.size() != 1)
	{
		int card1 = pq.top();
		pq.pop();
		int card2 = pq.top();
		pq.pop();
		pq.push(card1 + card2);
		sum += card1 + card2;
	}

	cout << sum;
}