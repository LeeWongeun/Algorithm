#include <string>
#include <vector>
#include <queue>

using namespace std;

//cutNode : 끊긴 노드
int BFS(const vector<vector<int>>& adj, int start, int cutNode)
{
    vector<int> isVisited(adj.size(), 0);
    int cnt = 1;
    queue<int> q;
    q.push(start);
    isVisited[start] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            if (isVisited[next] == 0 && next != cutNode)
            {
                q.push(next);
                isVisited[next] = 1;
                cnt++;
            }
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        adj[wires[i][0]].push_back(wires[i][1]);
        adj[wires[i][1]].push_back(wires[i][0]);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (i == adj[i][j]) continue;

            int diff = abs(BFS(adj, i, adj[i][j]) - BFS(adj, adj[i][j], i));

            if (diff < answer)
            {
                answer = diff;
            }
        }
    }
    return answer;
}