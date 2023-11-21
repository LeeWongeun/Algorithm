#include<vector>
#include<queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<bool>> visit;
    for(int i=0;i<n;i++)
    {
        vector<bool> temp(m,0);
        visit.push_back(temp);
    }
    
    vector<vector<int>> dist;
    for(int i=0;i<n;i++)
    {
        vector<int> temp(m);
        dist.push_back(temp);
    }
    
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    dist[0][0] = 1;
    visit[0][0] = 1;
    pair<int,int> cur;
    
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nextRow = cur.first + row[i];
            int nextCol = cur.second + col[i];
            if(nextRow >=0 && nextRow < n && nextCol >= 0 && nextCol < m && maps[nextRow][nextCol] == 1 && visit[nextRow][nextCol] == 0)
            {
                q.push(make_pair(nextRow,nextCol));
                dist[nextRow][nextCol] = dist[cur.first][cur.second] + 1;
                visit[nextRow][nextCol] = 1;
            }
            if(nextRow == n-1 && nextCol == m-1)
            {
                answer = dist[nextRow][nextCol];
                return answer;
            }
        }
    }
    return -1;
}