#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(const vector<vector<int>>& adj, vector<int>& isVisited, int start)
{
    queue<int> q;
    q.push(start);
    isVisited[start] = 1;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i=0;i<adj[cur].size();i++)
        {
            int next = adj[cur][i];
            if(isVisited[next] == 0)
            {
                q.push(next);
                isVisited[next] = 1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<vector<int>> adj(n);
    for(int i=0;i<computers.size();i++)
    {
        for(int j=0;j<computers.size();j++)
        {
            if(computers[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    vector<int> isVisited(n,0);
    for(int i=0;i<n;i++)
    {
        if(isVisited[i]==0)
        {
            bfs(adj, isVisited, i);
            answer++;
        }
    }
    
    return answer;
}