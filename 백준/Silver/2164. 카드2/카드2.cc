#include<iostream>
#include<queue>

using namespace std;

int main() {
	int n, buf;
	queue<int> q;

	cin >> n;
	for (int i = 1; i < n+1; i++) {
		q.push(i);
	}

	for (int i = n-1; i > 0; i--) {
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front();
}