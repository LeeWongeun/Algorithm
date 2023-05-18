#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dfs(int start, vector<int> gp[], int isVisited[]) {
	int currentNode, nextNode, cnt = 0;
	stack<int> s;
	s.push(start);

	while (!s.empty()) {
		currentNode = s.top();
		isVisited[currentNode] = 1;
		s.pop();
		for (int i = 0; i < gp[currentNode].size(); i++) {
			nextNode = gp[currentNode][i];
			if (isVisited[nextNode] == 0) {
				s.push(currentNode);
				s.push(nextNode);
				cnt++;
				break;
			}
		}
	}

	return cnt;
}
int main() {
	int computerNum, n, a, b, isVisited[101] = { 0 };
	vector<int> v[101];

	cin >> computerNum;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cout << dfs(1, v, isVisited);
}