#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> q;

	int n, k, buf;

	cin >> n >> k;

	for (int i = 1; i < n + 1; i++) {
		q.push(i);
	}

	cout << '<';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k-1; j++) {
			buf = q.front();
			q.pop();
			q.push(buf);
		}
		buf = q.front();
		q.pop();
		if (i == n - 1) {
			cout << buf << '>';
			break;
		}
		cout << buf << ", ";
	}
}