#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> node(n);
    for(int i;i<edge.size();i++)
    {
        node[edge[i][0]-1].push_back(edge[i][1] - 1);
        node[edge[i][1]-1].push_back(edge[i][0] - 1);
    }
    
    vector<bool> visit(n,0);
    queue<int> q;
    queue<int> nextQ;
    nextQ.push(0);
    visit[0] = 1;
    int cur;
    
    while(nextQ.size())
    {
        q = nextQ;
        nextQ = queue<int>();
        while(q.size())
        {
            cur = q.front();
            q.pop();
            for(int i=0;i<node[cur].size();i++)
            {
                if(visit[node[cur][i]]==0)
                {
                    nextQ.push(node[cur][i]);
                    visit[node[cur][i]] = 1;
                }
            }
        }
        if(nextQ.size()==0) break;
        answer = nextQ.size();
    }
    
    return answer;
}