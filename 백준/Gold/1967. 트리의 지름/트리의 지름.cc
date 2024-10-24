#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> t;
int maxV = -1;
int maxD = -1;

void dfs(int cur, int curDist, vector<int>& visited)
{
    visited[cur] = 1;

    if (curDist > maxD)
    {
        maxV = cur;
        maxD = curDist;
    }

    for (auto& edge : t[cur])
    {
        int next = edge.first;
        int nextDist = edge.second;
        if (!visited[next])
        {
            dfs(next, curDist + nextDist, visited);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    t.resize(n + 1);

    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        t[a].push_back({ b, c });
        t[b].push_back({ a, c });
    }

    vector<int> visited(n + 1, 0);
    dfs(1, 0, visited);

    fill(visited.begin(), visited.end(), 0);
    maxD = -1;
    dfs(maxV, 0, visited);

    cout << maxD;
}
