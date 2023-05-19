#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int arr[1001][1001] = { 0 };
int isVisited[1001][1001] = { 0 };

struct coordinate {
	int x = 0;
	int y = 0;
};

int push_node(queue<coordinate> *q1, queue<coordinate> *q2, int *n, int *m, int* day) {
	coordinate current, next;
	int cnt = 0;
	if (q1->empty()) {
		return 0;
	}
	while (!q1->empty()) {
		current = q1->front();
		q1->pop();
		isVisited[current.y][current.x] = 1;
		cnt++;

		if (current.x > 0 && isVisited[current.y][current.x - 1] == 0) { //왼쪽
			next.x = current.x - 1;
			next.y = current.y;
			isVisited[next.y][next.x] = 1;
			q2->push(next);
		}
		if (current.x < *m-1 && isVisited[current.y][current.x + 1] == 0) { //오른쪽
			next.x = current.x + 1;
			next.y = current.y;
			isVisited[next.y][next.x] = 1;
			q2->push(next);
		}
		if (current.y > 0 && isVisited[current.y - 1][current.x] == 0) { //위
			next.x = current.x;
			next.y = current.y - 1;
			isVisited[next.y][next.x] = 1;
			q2->push(next);
		}
		if (current.y < *n-1 && isVisited[current.y + 1][current.x] == 0) { //아래
			next.x = current.x;
			next.y = current.y + 1;
			isVisited[next.y][next.x] = 1;
			q2->push(next);
		}
	}
	*day = *day + 1;
	return cnt;
}
int count_day(queue<coordinate> *q1, int *n, int *m) {
	queue<coordinate> q2;
	int day = 0, cnt = 0;

	while (!q1->empty() || !q2.empty()) {
		cnt+=push_node(q1, &q2, n, m, &day);
		cnt+=push_node(&q2, q1, n, m, &day);
	}

	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *m; j++) {
			if (isVisited[i][j] == 0) {
				return -1;
			}
		}
	}
	if (day == 0) day;
	else return day-1;
}
int main() {
	int n, m, day;
	coordinate cobuf;
	queue<coordinate> q1;

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 1) {
				cobuf.x = j;
				cobuf.y = i;
				q1.push(cobuf);
				isVisited[i][j] = 1;
			}
			else if (arr[i][j] == -1) {
				isVisited[i][j] = 1;
			}
			else {
				isVisited[i][j] = 0;
			}
		}
	}

	day = count_day(&q1, &n, &m);
	cout << day;
}