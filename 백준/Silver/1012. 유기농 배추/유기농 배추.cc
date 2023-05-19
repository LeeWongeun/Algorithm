#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> graph[50][50][2];
int isVisited[50][50];
int cnt = 0;

void dfs(int startx, int starty) {
	stack<int> xstack;
	stack<int> ystack;
	int currentX, currentY;
	int nextX, nextY;
	
	xstack.push(startx);
	ystack.push(starty);

	while (!xstack.empty() && !ystack.empty()) {
		currentX = xstack.top();
		currentY = ystack.top();

		isVisited[currentX][currentY] = 1;

		xstack.pop();
		ystack.pop();
		
		for (int i = 0; i < graph[currentX][currentY][0].size(); i++) {
			nextX = graph[currentX][currentY][0][i];
			nextY = graph[currentX][currentY][1][i];

			if (!isVisited[nextX][nextY]) {
				xstack.push(currentX);
				ystack.push(currentY);
				xstack.push(nextX);
				ystack.push(nextY);
				break;
			}
		}
	}
	cnt++;
}

int main() {
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, m, k, x, y, testcase;
	int arr[50][50] = { 0 };
	int ans[1000];
	
	cin >> testcase;
	for (int t = 0; t < testcase; t++) {
		cin >> n >> m >> k;

		cnt = 0;
		fill(&arr[0][0], &arr[n - 1][m], 0);
		fill(&isVisited[0][0], &isVisited[n - 1][m], 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				graph[i][j][0].clear();
				graph[i][j][1].clear();
			}
		}

		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			arr[x][y] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i < n - 1) {
					if (arr[i + 1][j] == 1) { //오른쪽
						graph[i][j][0].push_back(i + 1);
						graph[i][j][1].push_back(j);
					}
				}
				if (i > 0) {
					if (arr[i - 1][j] == 1) { //왼쪽
						graph[i][j][0].push_back(i - 1);
						graph[i][j][1].push_back(j);
					}
				}
				if (j < m - 1) {
					if (arr[i][j + 1] == 1) { //위
						graph[i][j][0].push_back(i);
						graph[i][j][1].push_back(j + 1);
					}
				}
				if (j > 0) {
					if (arr[i][j - 1] == 1) { //아래
						graph[i][j][0].push_back(i);
						graph[i][j][1].push_back(j - 1);
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!isVisited[i][j] && arr[i][j] == 1) {
					dfs(i, j);
				}
			}
		}

		ans[t] = cnt;
	}

	for (int i = 0; i < testcase; i++) {
		cout << ans[i] << '\n';
	}
}